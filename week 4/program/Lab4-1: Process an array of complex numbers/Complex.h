#pragma once

class Complex
{
    public:
        Complex(void);//constructor
        virtual ~Complex(void);//destructor
        void setValue(double real, double imaginary);
        void add(Complex input);
        void multiple(Complex input);
        void subtract(Complex input);
        bool divide(Complex input);
        bool equal(Complex input, double precision);
        double magnitude(void);
        void print(void);
        static void unitTest(void);
    private:
        double m_real;
        double m_imaginary;
};