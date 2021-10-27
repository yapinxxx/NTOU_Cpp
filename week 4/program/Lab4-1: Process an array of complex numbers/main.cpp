#include <cstdio>
#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
x1=(-b+sqrt(b2-4ac))/(2a), 
x2=(-b-sqrt(b2-4ac))/(2a)
*/

int main()
{
    Complex x1, x2, tmp, tmp2, numerator, denominator;
    double a, b, c, tmp_b4ac, tmp_2a_invb;
    int times;
    Complex::unitTest();

    cin >> a >> b >> c;

    tmp_2a_invb = ((-1)*b)/(2*a);// (-b)/2a
    
    tmp_b4ac = b*b-4*a*c; //b^2 - 4ac
    
    
    x1.setValue(tmp_2a_invb,0);
    x2.setValue(tmp_2a_invb,0);

    
    

    if(tmp_b4ac>0)
    {
        tmp_b4ac = sqrt(tmp_b4ac);
        tmp_b4ac = tmp_b4ac / (2*a);
        tmp.setValue(tmp_b4ac,0);
    }
    //only one ans
    else if(tmp_b4ac==0)
    {
        x1.print();
        x2.print();
        cout << "x1 is the same as x2" << endl;
    }
    else
    {
        tmp_b4ac = (-1) * tmp_b4ac;
        tmp_b4ac = sqrt(tmp_b4ac); 
        tmp_b4ac = tmp_b4ac / (2*a); 
        tmp.setValue(0,tmp_b4ac);
    }
    
    // tmp.print();
    // x1.print();
    // x2.print();

    x1.add(tmp);
    x2.subtract(tmp);

    cout << "x1 " << endl;
    x1.print();
    cout << "x2 " << endl;
    x2.print();


    
    /*
    ((x1)5 + (x2)5) / ((x2)10 - (x1)7)
    */
    tmp = x1;
    tmp2 = x2;
    //tmp.print();
    for(times=1;times<5;times++)
    {
        x1.multiple(tmp);
        x2.multiple(tmp2);
    }
    numerator = x1;
    numerator.add(x2);
    
    //init x1, x2
    x1 = tmp;
    x2 = tmp2;
    for(times=1;times<10;times++)
    {
        x2.multiple(tmp2);
    }
    for(times=1;times<7;times++)
    {
        x1.multiple(tmp);
    }
    denominator = x2;
    denominator.subtract(x1);

    cout << "Ans:" << endl;
    numerator.divide(denominator);
    numerator.print();   
    
    cin.get();
    return 0;
}