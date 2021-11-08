#include "Complex.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

bool my_greater(Complex num1, Complex num2);

int main()
{
    vector<Complex> C_list;
    vector<Complex>::iterator iter;
    
    Complex test, tmp, sum, target;
    string filename;
    double real, imaginary;
    int count, pos;

    cin >> filename;
    ifstream in(filename);
    if(!in)
    {
        cout << "Error open file: " << filename << endl;
    }

    pos = 0;

    //version 1
    while(!in.eof())
    {
        in >> real >> imaginary;
        if(in.fail())
        {
            cout << "End of the file! " << endl;
            break;            
        }
        // if(in.eof())
        // {
        //     cout << "End of the file! " << endl;
        //     break;
        // }
        cout << real << " " << imaginary << endl;
        tmp.setValue(real,imaginary);
        C_list.push_back(tmp);
        //C_list[pos].print();
        ++pos;
    }

    //version 2
    // while(in >> real >> imaginary)
    // {
    //     cout << real << " " << imaginary << endl;
    // }

    
    sum.setValue(1,0);
    for(iter=C_list.begin();iter < C_list.end(); iter++)
    {
        sum.multiple(*iter);
        
    }
    
    sum.print();
    target.setValue(-8.96419,-3.24387);
    target.print();
    assert(sum.equal(target,1e-5));

    cout << C_list.size() << endl;
    sort(C_list.begin(),C_list.end(),my_greater);
    for(count=0;count<C_list.size();count++)
    {
        C_list[count].print();
    }


    cin.get();
    return 0;
}



bool my_greater(Complex num1, Complex num2)
{
    return (num1.magnitude() < num2.magnitude() );
}