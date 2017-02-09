//#include<stdio.h>
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

size_t get_array_size(byte_array_t* array)
{
    if(!array)
        return 0;
    return array->nz;
}

byte_array_t* byte_array_create(uint8_t* vals, size_t nz)
{
    if(!vals)
        return NULL;
    int i = 0;
    byte_array_t* b_array = (byte_array_t*)malloc(sizeof(byte_array_t));
    if(!b_array)
        return NULL;
    b_array->ar = (byte_t**)malloc(sizeof(byte_t*)*nz);
    if(!b_array->ar)
        return NULL;
    for(; i<nz; i++)
    {
        *(b_array->ar+i) = byte_alloc(vals[i]);
    }
    b_array->nz = nz;
    return b_array;

}

byte_t* byte_array_get(byte_array_t* array, size_t index)
{
    if(!array || index >= array->nz)
        return NULL;
    return array->ar[index];
}

void byte_array_free(byte_array_t** array)
{
    if(array && *array)
    {
        int i;
        for(i=0; i<(*array)->nz; i++)
        {
            byte_free((*array)->ar+i);
        }
    }
    *array = NULL;
}
