#include <stdio.h>
#include<stdint.h>
#include<omp.h>
#include"bits.h"
#include"do_or.h"

int main(int argc, char* argv[])
{
    byte_t* byte = byte_alloc(0);
    /*uint8_t bytes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};*/
    //uint8_t bytes[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //uint8_t bytes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    omp_set_num_threads(NUM_THREAD);
    size_t nz = NUM;//ARR_SIZE(bytes);
    byte_array_t* b_ar = byte_array_create_copy(0,nz);//byte_array_create(bytes, nz);
    fprintf(stdout, "BYTE ARRAY SIZE : %zu\n", get_array_size(b_ar));
    uint8_t ret = do_or_tree(b_ar); //do_or_array(b_ar);
    fprintf(stdout, "OR RESULT : %u\n", ret);
    byte_array_free(&b_ar);
#ifdef OMP
    fprintf(stdout, "OMP ENABLED\n");
#endif
    return 0;
}
