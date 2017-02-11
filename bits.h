#ifndef _BITS_H
#define _BITS_H

#include<stdint.h>
#include<stddef.h>
#define BYTE_SIZE 8
#define BYTE_END 2
#define BYTE_INVALID 0xff
#define ARR_SIZE(x) ((sizeof x) / (sizeof *x))

typedef struct
{
    uint8_t b;
    uint8_t n;
} byte_t;

typedef struct
{
    byte_t **ar;
    size_t nz;
} byte_array_t;

byte_t* byte_alloc(uint8_t);
void byte_free(byte_t**);
uint8_t get_next_bit(byte_t*);
uint8_t get_byte(byte_t*);
void set_byte(byte_t*, uint8_t);

size_t get_array_size(byte_array_t*);
byte_array_t* byte_array_create(uint8_t*, size_t);
byte_array_t* byte_array_create_copy(uint8_t, size_t);
byte_t* byte_array_get(byte_array_t*, size_t);
void byte_array_set(byte_array_t*, size_t, uint8_t);
void byte_array_free(byte_array_t**);
#endif /*_BITS_H*/
