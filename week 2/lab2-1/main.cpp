#include<cstdio>
#include<iostream>
#include"g_para.h"
#include"io.h"
#include"statistic.h"





using namespace std;
int main()
{
    // avoid the buffer problem from
    // iostream and stdio.h conflect
    //std::ios::sync_with_stdio();
    int dataSize;
    int frequency[10] = {0};
    int data[DATASIZE];
    
    // reading file
    readFile(&dataSize, data);
    writeFile(dataSize, data);
    cout << "write end \n";

    // process responses
    mean(data, dataSize);
    median(data, dataSize);
    mode(frequency, data, dataSize);
    
    cin.get();
    return 0;  // indicates successful termination
}
