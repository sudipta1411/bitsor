#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#include"bits.h"
#include"do_or.h"

int main(int argc, char* argv[])
{
    clock_t start, end;
    uint8_t ret;
    size_t nz = atol(argv[1]);
    fprintf(stdout, "%lu\n", nz);
    byte_t* byte = byte_alloc(0);
    omp_set_num_threads(NUM_THREAD);
    byte_array_t* b_ar = byte_array_create_copy(1,nz);
    //fprintf(stdout, "BYTE ARRAY SIZE : %zu\n", get_array_size(b_ar));
    start = clock();
    ret = do_or_tree(b_ar); //do_or_array(b_ar);
    end = clock();
    fprintf(stdout, "[tree] Array length : %lu, OR Result : %u, time: %f\n",
           nz, ret, ((double)(end-start))/CLOCKS_PER_SEC);

    start = clock();
    ret = do_or_array(b_ar);
    end = clock();
    fprintf(stdout, "[array] Array length : %lu, OR Result : %u, time: %f\n",
           nz, ret, ((double)(end-start))/CLOCKS_PER_SEC);
    byte_array_free(&b_ar);
    return 0;
}
