#include<cstdio>
#include<iostream>
#include"g_para.h"
#include"io.h"
#include"statistic.h"





using namespace std;
int main()
{
    int dataSize;
    int frequency[10] = {0};
    int data[DATASIZE];
    
    // reading file
    readFile(&dataSize, data);
    printArray(data,dataSize);

    // process responses
    mean(data, dataSize);
    median(data, dataSize);
    mode(frequency, data, dataSize);
    
    cin.get();
    return 0;  // indicates successful termination
}
