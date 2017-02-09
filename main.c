#include <stdio.h>
#include<stdint.h>
#include"bits.h"
#include"do_or.h"

int main(int argc, char* argv[])
{
    byte_t* byte = byte_alloc(0);
    //uint8_t bytes[] = {1,2,3,4,5,6,3,8,9,0,20,34,32,12,4,5};
    uint8_t bytes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    size_t nz = ARR_SIZE(bytes);
    byte_array_t* b_ar = byte_array_create(bytes, nz);
    fprintf(stdout, "BYTE ARRAY SIZE : %zu\n", get_array_size(b_ar));
    int i;
    /*for(i=0; i<b_ar->nz; i++)
    {
        fprintf(stdout,"%u\n", byte_array_get(b_ar,i)->b);
    }*/
    uint8_t ret = do_or_array(b_ar);
    fprintf(stdout, "OR RESULT : %u\n", ret);
    byte_array_free(&b_ar);
#ifdef OMP
    fprintf(stdout, "OMP ENABLED\n");
#endif
    return 0;
}
