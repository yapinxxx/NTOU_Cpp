#include <stdio.h>
#include <assert.h>
#include "g_para.h"
void readFile(int *dataSize, int data[])
{
    int i, len;
    FILE *fp;
    char filename[30];

    printf("Input the file name: ");
    fgets(filename,30,stdin);
    printf("filename : %s\n",filename);
    
    i = 0;
    // while(filename[i]!='\n')
    // {
    //     i++;
    // }
    // len = i;
    
    while(filename[i]!='\0')
    {
        i++;
    }
    len = i-1;

    // printf("len %d\n",len);
    //printf("filename %d\n",filename[i]);
    filename[len] = '\0';
    fp = fopen(filename, "rt");
    assert(fp!=0);
    
    fscanf(fp, "%d", dataSize);
    assert(*dataSize < DATASIZE);
    //printf("first fscanf done\n");
    for (i=0; i<*dataSize; i++)
    {
    fscanf(fp, "%d", &data[i]);
    assert(data[i]<=9&&data[i]>0);
    
    //printf("data %d ",data[i]);
    }
        
    fclose(fp);
     
}

// output array contents (20 values per row)
void printArray(const int a[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        if (i % 20 == 0)  // begin new line every 20 values
            printf("\n");

        printf("%2d", a[i]);

    }
}
