#include<stdio.h>
#include"io.h"
#include"sort.h"
// calculate average of all values
void mean(const int dataArray[], int arraySize)
{
    double total = 0.0;

    printf("********\n  Mean\n********\n");

    // total response values
    for (int i = 0; i < arraySize; i++)
        total += dataArray[i];

    // format and output results
    printf("The mean is the average value of the data\n"
           "items. The mean is equal to the total of\n"
           "all the data items divided by the number\n"
           "of data items ( %d ). The mean value for\n"
           "this run is: %f / %d = %f\n\n", 
           arraySize, total, arraySize, total / arraySize);
}

// sort array and determine median element's value
void median(int dataArray[], int arraySize)
{
    printf("\n********\n Median\n********\nThe unsorted array of data is");

    printArray(dataArray, arraySize);  // output unsorted array

    sort(dataArray, arraySize);  // sort array of data
    

    printf("\n\nThe sorted array is");
    printArray(dataArray, arraySize);  // output sorted array 
     
    // display median element
    printf("\n\nThe median is the %d-th element of\nthe sorted %d" 
           " element array.\nFor this run the median is %d\n\n",
           arraySize/2, arraySize, dataArray[arraySize / 2]);
}


// determine most frequent data value
void mode(int freq[], int dataArray[], int arraySize)
{
    int i, j, k;
    int rating;
    int largest = 0;    // represents largest frequency
    int modeValue = 0;  // represents most frequent response

    printf("\n********\n  Mode\n********\n");

    // calculate the occuring frequency of data
    //printArray(dataArray,arraySize);
    for(i=0;i<arraySize;i++)
    {
        freq[dataArray[i]]++;
    }

    // output headers for result columns
    printf("Data  Frequency       Histogram\n"
           "                                1    1    2    2\n"
           "                           5    0    5    0    5\n\n");

    // output results
    for (rating = 1; rating <= 9; rating++) {
        printf("%4d%10d         ", rating, freq[rating]);

        // keep track of mode value and largest fequency value
        if (freq[rating] > largest)
        {
            largest = freq[rating];
            modeValue = rating;
        }

        // output histogram bar representing frequency value
        for (k = 1; k <= freq[rating]; k++)
            printf("*");
        printf("\n");
    }

    // display the mode value
    printf("The mode is the most frequent value.\n"
           "For this run the mode is %d which "
           "occurred %d times.\n", modeValue, largest);
}

