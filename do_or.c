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
    uint8_t ret = 0;
    byte_t* byte = NULL;
    for(count = 0; count < nz; count++)
    {
        byte = byte_array_get(array, count);
        ret |= do_or_single(byte);
    }
    return ret;

}
