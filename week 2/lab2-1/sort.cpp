// function that sorts an array 
#include <stdlib.h>
int cmp(const void *num1, const void *num2)
{
    return ( *(int*)num1 -  *(int*)num2);
}

int isDecending(int a[], int size)
{
    int i;
    for (i=1; i<size; i++)
        if (a[i]>a[i-1])
    	    return 0;
    return 1;
}

void sort(int a[], int size)
{
    qsort(a,size,sizeof(int),cmp);
    //selection_sort(a,size);
}

void selection_sort(int a[], int size)
{
    int i,j,tmp,max,max_pos;
    max =  0;
    for(i=size-1;i>=0;i--)
    {
        for(j=i;j>=0;j--)
        {
            if(a[j]>max)
            {
                max = a[j];
                max_pos = j;
            }
        }
        a[max_pos] = a[i];
        a[i] = max;
        max = 0;

    }
    isDecending(a,size);

    /*printf("sort_fun\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");*/
}

