#include <iostream>

using namespace std;

int main()
{
    char filename[10];
    int i,len;
    cin>>filename;
    i = 0;
    while(filename[i]!='\0')
    {
        i++;
    }

    len = i;
    cout << len << filename << "line1" <<'\n';
    cout << "line2";



}