#include<stdio.h>
#include<math.h>
#include<omp.h>
#include"do_or.h"

uint8_t do_or_single(byte_t* byte)
{
    /*NULL byte is equivalent to 0*/
    if(!byte)
        return 0;
    uint8_t ret = 0;
    uint8_t bit;
    while((bit = get_next_bit(byte)) != BYTE_END)
    {
        ret |= bit;
        if(ret == 1)
            break;
    }
    byte->n = 0;
    return ret;
}

uint8_t do_or_pair(byte_t* byte1, byte_t* byte2)
{
    uint8_t ret = 0;
    ret = do_or_single(byte1);
    if(!ret)
        ret |= do_or_single(byte2);
    return ret;
}

uint8_t do_or_array(byte_array_t* array)
{
    if(!array)
        return 0;
    size_t nz = get_array_size(array);
    size_t count;
    uint8_t ret = 0, local_ret;
    byte_t* byte;
    size_t chunk_size = nz / NUM_THREAD;
    int tid;
#pragma omp parallel \
    shared(array, nz, ret, chunk_size) \
    private(count, byte, tid, local_ret)
    {
        local_ret = 0;
        byte = NULL;
#pragma omp for \
        schedule(static, chunk_size)
        for(count = 0; count < nz; count++)
        {
            byte = byte_array_get(array, count);
            local_ret |= do_or_single(byte);
        }
#pragma omp atomic //critical
        ret |= local_ret;

        tid = omp_get_thread_num();
        fprintf(stdout, "Thread id %d and value %u\n", tid, local_ret);
    }
    return ret;
}

uint8_t do_or_tree(byte_array_t* array)
{
    if(!array)
        return 0;
    int nr_thread = omp_get_num_threads();
    size_t nz = get_array_size(array);
    size_t chunk_size = nz / nr_thread;
    int height = log2(nz);
    int h, i, tid, iter;
    size_t len = (size_t) nz / 2;
    byte_array_t* aux = byte_array_create_copy(0, len);
    byte_t *byte1, *byte2;
    uint8_t ret;
    for(h=1; h<=height; h++)
    {
        iter = nz / pow(2, h);
#pragma omp parallel \
        shared(array, aux, iter) \
        private(i, tid, byte1, byte2, ret)
        {
            tid = omp_get_thread_num();
#pragma omp for \
            schedule(static, chunk_size)
            for(i=0; i<iter; i++)
            {
                byte1 = byte_array_get(array, 2*i);
                byte2 = byte_array_get(array, 2*i+1);
                ret = do_or_pair(byte1, byte2);
                fprintf(stdout, "[%d] %u %u %u\n", tid, get_byte(byte1), get_byte(byte2), ret);
                byte_array_set(aux, i, ret);
            }
#pragma omp for
            for(i=0; i<iter; i++)
            {
                byte_t *byte = byte_array_get(aux, i);
                byte_array_set(array, i, get_byte(byte));
            }
        }
    }
    byte_array_free(&aux);
    fprintf(stdout, "result : %u\n", get_byte(byte_array_get(array, 0)));
    return get_byte(byte_array_get(array, 0));
}

static uint8_t do_or_seq(byte_array_t* array,
        unsigned long start, unsigned long end)
{
    if(!array)
        return 0;
     unsigned long i;
     uint8_t ret = 0;
     byte_t* byte = NULL;
     for(i=start ; i<end; i++)
     {
         byte = byte_array_get(array, i);
         if(!byte)
             break;
         ret |= do_or_single(byte);
         if(ret == 1)
             break;
     }
     return ret;
}
