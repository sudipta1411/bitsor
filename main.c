#include <stdio.h>
#include"bits.h"
#include"do_or.h"

int main(int argc, char* argv[])
{
    byte_t* byte = byte_alloc(0);
    uint8_t bit_val;
    bit_val = do_or_single(byte);
    fprintf(stdout, "%u\n", bit_val);
    byte_free(&byte);
}
