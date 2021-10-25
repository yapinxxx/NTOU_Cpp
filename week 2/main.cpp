#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char ary[100];
    int i;
    i = 0;
    cin.get(ary,100);
    //cin.getline(ary,100);
    while(ary[i]!='\0')
    {
        cout << ary[i] <<endl;
        i++;
    }
    cout << i << endl;
    cout << ary;

}