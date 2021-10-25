#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    double a, b;

    a = 0.000123456;
    b = 123.456789;
    cout << "hello" << endl;
    //cout << setprecision(5);
    cout.precision(5);
    cout << fixed;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cin.get();
    return 0;
}
