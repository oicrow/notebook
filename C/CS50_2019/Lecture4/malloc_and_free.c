#include <stdio.h>
#include <stdlib.h> // malloc, free

int main (void)
{
    // malloc: meaning - memory allocation
    //       : declared in - <stdlib.h>
    //       : input - number of bytes to allocate
    //       : output - the address of the first byte allocated
    //
    // free : meaning - hand back the allocated memory (opposite to malloc)
    //      : declared in - <stdlib.h>
    //      : input - the pointer to the first byte allocated
    //
    // Valgrind: detect memory leaking
    //         : in the prompt >>> valgrind file_name
    
    // Buffer Overflow
    int *x = malloc(10 * sizeof(int));
    x[0] = 0;
    x[1] = 1;
    x[9] = 9;
    // x[10] = 10       ! Buffer Overflow
    // x[10000] = 10    ! Buffer Overflow
    free(x);
}
