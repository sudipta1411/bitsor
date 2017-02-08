#ifndef _BITS_H
#define _BITS_H

#include<stdint.h>
#define BYTE_SIZE 8
#define BYTE_END 2

typedef struct
{
    uint8_t b;
    uint8_t n;
} byte_t;

byte_t* byte_alloc(uint8_t);
void byte_free(byte_t**);
uint8_t get_next_bit(byte_t*);


#endif /*_BITS_H*/
