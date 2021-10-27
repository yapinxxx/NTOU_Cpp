#include "Complex.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>
/*
加法 (a + b i) + (c + d i) = (a+c) + (b+d) i
減法 (a + b i) - (c + d i) = (a-c) + (b-d) i
乘法 (a + b i) * (c + d i) = (ac-bd) + (ad+bc) i
除法 (a + b i) / (c + d i) = (ac+bd)/(c*c+d*d) + (-ad+bc)/(c*c+d*d) i
大小 (複數平面上向量的長度) | a + b i | = (a*a+b*b)0.5
*/



Complex::Complex(void)
        :m_real(0), m_imaginary(0.)
{
    //std::cout << "test"  << std::endl;
}

void Complex::setValue(double real, double imaginary)
{
    m_real = real;
    m_imaginary = imaginary;

}

void Complex::add(Complex input)
{
    m_real += input.m_real;
    m_imaginary += input.m_imaginary;

}


void Complex::multiple(Complex input)
{
    double tmp;
    tmp = m_real;
    m_real = (m_real * input.m_real) - (m_imaginary * input.m_imaginary);
    m_imaginary = (tmp * input.m_imaginary) + (m_imaginary * input.m_real);

}

void Complex::subtract(Complex input)
{
    input.m_real = (-1) * input.m_real;
    input.m_imaginary = (-1) * input.m_imaginary;
    add(input);
}

bool Complex::divide(Complex input)
{
    //numerator
    //denominator

    if(input.m_real==0&&input.m_imaginary==0)
    {
        //NaN
        return 0;//denominator error

    }
    Complex tmp;
    double denominator;
    tmp = input;
    tmp.m_imaginary = tmp.m_imaginary * (-1);
    multiple(tmp);
    input.multiple(tmp);


    denominator = input.m_real;
    m_real = m_real / denominator;
    m_imaginary = m_imaginary / denominator;
    return 1;//success

}

double Complex::magnitude(void)
{
    double tmp_real, tmp_imaginary;
    tmp_real = pow(m_real,2);
    tmp_imaginary = pow(m_imaginary,2);
    tmp_real =  tmp_real + tmp_imaginary;
    tmp_real = sqrt(tmp_real);
    return tmp_real;
}

bool Complex::equal(Complex input, double precision)
{
    double tmp_magnitude;
    subtract(input);
    tmp_magnitude =  fabs(magnitude());
    
    if(tmp_magnitude < precision)
    {
        return true;
    }
    return false;

}

void Complex::print(void)
{
    
    std::cout <<  m_real << " + "  
    << m_imaginary <<  " i" <<std::endl;
    std::cout << std::fixed;
    std::setprecision(7);
    std::cout << magnitude() << std::endl;
}

void Complex::unitTest(void)
{
    Complex x, y, z;
    
    // std::cout << "Test add()" << std::endl;
    x.setValue(1,2);
    y.setValue(3,4);
    z.setValue(4,6);
    x.add(y);
    // x.print();
    // z.print();
    assert(x.equal(z,1e-10));
    // std::cout << "End add()" << "\n" << std::endl;



    // std::cout << "Test subtraction()" << std::endl;
    x.setValue(4,6);
    y.setValue(3,4);
    z.setValue(1,2);
    x.subtract(y);
    // x.print();
    // z.print();
    assert(x.equal(z,1e-10));
    // std::cout << "End subtraction()" << "\n" << std::endl;
    

    // std::cout << "Test multiple()" << std::endl;
    x.setValue(1,2);
    y.setValue(3,4);
    z.setValue(-5,10);
    x.multiple(y);
    // x.print();
    // z.print();
    assert(x.equal(z,1e-10));
    // std::cout << "End multiple()" << "\n" << std::endl;
    
    

    // std::cout << "Test multiple2()" << std::endl;
    x.setValue(1,2);
    y.setValue(-3,4);
    x.multiple(x);
    // x.print();
    // y.print();
    assert(x.equal(y,1e-10));
    // std::cout << "End multiple2()" << "\n" << std::endl;

    // std::cout << "Test divide()" << std::endl;
    x.setValue(7,3);
    y.setValue(1,1);
    z.setValue(5,-2);
    assert(x.divide(y));
    // x.print();
    // z.print();
    assert(x.equal(z,1e-10));
    y.setValue(0,0);
    assert(!x.divide(y));
    // std::cout << "End divide()" << "\n" << std::endl;
    std::cout << "unitTest success" << std::endl;


    
    //cin.get();
}

Complex::~Complex(void)
{


}