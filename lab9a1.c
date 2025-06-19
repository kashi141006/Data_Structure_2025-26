#include <stdio.h>
#include <stdlib.h>
void main()
{
    
   int *iptr = (int*)malloc(sizeof(int));
   float *fptr = (float*)malloc(sizeof(float));
   char *cptr = (char*)malloc(sizeof(char));
    if (iptr && fptr && cptr)
    {
        *iptr = 2;
        *fptr = 10.20;
        *cptr = 'k';
        printf("integer:%d\n", *iptr);
    printf(" float:%.2f\n", *fptr);
    printf(" character:%c", *cptr);
    }

    
    free(iptr);
    free(fptr);
    free(cptr);
}