#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    ptr = (int *) malloc(100*sizeof(int));

    ptr[100] = 10; // buffer overflow
    ptr[-1] = -1; // buffer underflow
    
    return 0; // memory leakage
}