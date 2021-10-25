#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cassert>

using namespace std;

struct DataRecord
{
    int lineNumber;
    int value;
    bool operator == (const DataRecord& y);

};

bool DataRecord::operator == (const DataRecord& y)
{
    if(value==y.value && lineNumber==y.lineNumber)
    {
        return 1;
        
    }
    else
    {
        return 0;
    }
}


bool my_cmp(const DataRecord elm1, const DataRecord elm2);
void printstruct(const vector<DataRecord> D_ary, const int timesSize);

int main()
{
    int times,read_value,dataSize;
    string openfile;
    cout << "Please input openfile name" << endl;
    //getline(cin,openfile);
    cin >> openfile;
    ifstream inf(openfile);

    vector<DataRecord> recordArray;
    DataRecord tmp, goal;
    vector<DataRecord>::iterator result;
    string line;
    cout << openfile << endl;
    
    times = 0;
    dataSize = 0;
    inf >> dataSize;
    /* my iter version
    for(times=0;times<dataSize;times++,iter++)
    {
        iter = recordArray.begin();
        inf >> iter->value;
        iter->lineNumber = times;
    }*/
    cout << dataSize << endl;
    assert(dataSize!=0);

    for(times=0;times<dataSize;times++)
    {
        inf >> tmp.value;
        tmp.lineNumber = times;
        recordArray.push_back(tmp);
        
    }
    printstruct(recordArray,times);
    cout << "==========" << endl;
    sort(recordArray.begin(), recordArray.end(),my_cmp);
    printstruct(recordArray,times);
    
    goal.value = 8;
    goal.lineNumber = 17;
    
    
    /*Use find fun*/
    // result = find(recordArray.begin(),recordArray.end(),goal);
    // if(result!=recordArray.end())
    // {
    //     cout << result->lineNumber << ":" << result->value << endl;
    // }

    /*Use binary_search*/
    if(binary_search(recordArray.begin(),recordArray.end(),goal,my_cmp))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }


    cin.get();
    return 0;

}

bool my_cmp(const DataRecord elm1, const DataRecord elm2)
{
    if(elm1.value == elm2.value)
    {
        return elm1.lineNumber < elm2.lineNumber;
    }
    else
    {
        return elm1.value < elm2.value;

    }
    // elm1.value < elm2.value;
    //sort() cmp is different from qsort() cmp
    //In sort() cmp , elm1 elm2, need return true
    //In qsort() cmp, elm1 elm2, need return negative number
}

void printstruct(const vector<DataRecord> D_ary, const int timesSize)
{
    int times;
    /*print recordArray*/
    for(times=0;times<timesSize;times++)
    {
        cout << D_ary[times].lineNumber
    << " " << D_ary[times].value << endl;
    }
    
}