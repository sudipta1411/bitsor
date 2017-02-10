#include<stdio.h>
#ifdef OMP
#include<omp.h>
#endif
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
#ifdef OMP
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
#pragma omp critical
        ret |= local_ret;

        tid = omp_get_thread_num();
        fprintf(stdout, "Thread id %d and value %u\n", tid, local_ret);
    }
#endif
    return ret;

}
