#include<stdio.h>
#include<stdlib.h>
#include"bits.h"

uint8_t get_next_bit(byte_t* byte)
{
    if(byte->n == BYTE_SIZE)
        return BYTE_END;
    uint8_t ret = byte->b & 0x01;
    byte->b = byte->b >> 1;
    byte->n++;
    return ret;
}

byte_t* byte_alloc(uint8_t val)
{
    byte_t *byte = NULL;
    byte = (byte_t*)malloc(sizeof(byte_t));
    if(!byte)
        return NULL;
    byte->n = 0;
    byte->b = val;
    return byte;
}

void byte_free(byte_t** byte)
{
    if(byte && *byte)
        free(*byte);
    *byte = NULL;
}

