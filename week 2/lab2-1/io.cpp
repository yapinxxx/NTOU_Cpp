#include <assert.h>
#include "g_para.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void readFile(int *dataSize, int data[])
{
    int i, len;
    //FILE *fp;
    
    char filename[30], buf[100];

    //printf("Input the file name: ");
    cout << "Input the file name" << endl;
    cin >> filename;
    //fgets(filename,30,stdin);
    //printf("filename : %s\n",filename);
    cout << filename <<endl;
    
    i = 0;
    //fgets will set '\n' on the lest position
    // while(filename[i]!='\n')
    // {
    //     i++;
    // }
    // len = i;
    
    //fgets will set '\n' on the lest position
    //behind the '\n' is '\0'
    // while(filename[i]!='\0')
    // {
    //     i++;
    // }
    // len = i-1;

    //c++ version
    while(filename[i]!='\0')
    {
        i++;
    }
    len = i;

    
    
    ifstream infile(filename);
    
    //assert(infile!=0);
    
    infile >> *dataSize;
    assert(*dataSize < DATASIZE);

    
    for (i=0; i<*dataSize; i++)
    {
    
    infile.ignore(100,'\n');

    infile >> data[i];
    
    assert(data[i]<=9&&data[i]>0);
    
    //To resolve the comment after the num
    
    
    //printf("data %d ",data[i]);
    }
        
    //fclose(fp);
     
}

// output array contents (20 values per row)
void printArray(const int a[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        if (i % 20 == 0)  // begin new line every 20 values
        {
            //printf("\n");
            cout << "\n";
        }    

        //printf("%2d", a[i]);
        cout << setw(2) << a[i] ;

    }
}

void writeFile(int dataSize, int data[])
{
    int i;
    // char filename[30];
    // cin >> filename ;
    // cout << "Output the file name" <<endl;
    //ofstream outfile(filename);

    ofstream outfile("raw4a.dat");
    outfile << dataSize << "\n";
    for(i=0;i<dataSize;i++)
    {
        outfile << data[i] << "\n";
    }
}