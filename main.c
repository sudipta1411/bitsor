#include <stdio.h>
#include<stdint.h>
#include"bits.h"
#include"do_or.h"

int main(int argc, char* argv[])
{
    byte_t* byte = byte_alloc(0);
    size_t nz = 10;
    uint8_t bytes[] = {1,2,3,4,5,6,3,8,9,0};
    byte_array_t* b_ar = byte_array_create(bytes, nz);
    fprintf(stdout, "%u\n", get_array_size(b_ar));
    int i;
    for(i=0; i<b_ar->nz; i++)
    {
        fprintf(stdout,"%u\n", byte_array_get(b_ar,i)->b);
    }
    byte_array_free(&b_ar);
    return 0;
}
