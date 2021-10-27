// Complex.h: interface for the CComplex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPLEX_H__DDF879E1_5100_4AD9_909C_0C61887CED08__INCLUDED_)
#define AFX_COMPLEX_H__DDF879E1_5100_4AD9_909C_0C61887CED08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Complex  
{
public:
	void print();
	void setValue(double real, double imaginary);
	bool equal(Complex rhs, double precision);
	double magnitue();
	bool divide(Complex rhs);
	void multiply(Complex rhs);
	void subtract(Complex rhs);
	void add(Complex rhs);
	Complex();
	virtual ~Complex();
    static void unitTest();

private:
	double m_real;
	double m_imaginary;
};

#endif // !defined(AFX_COMPLEX_H__DDF879E1_5100_4AD9_909C_0C61887CED08__INCLUDED_)
