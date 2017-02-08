#include <stdio.h>
#include"bits.h"

int main(int argc, char* argv[])
{
    byte_t* byte = byte_alloc(127);
    uint8_t bit_val;
    while((bit_val = get_next_bit(byte)) != BYTE_END)
    {
        fprintf(stdout, "%u\n", bit_val);
    }
    byte_free(&byte);
}
