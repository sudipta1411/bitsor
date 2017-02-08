#include"do_or.h"

uint8_t do_or_single(byte_t* byte)
{
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
