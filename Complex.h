#pragma once

#include<iostream>
using namespace std;

class Complex {
	double real;
	double imaginary;
public:
	Complex(double x, double y) : real(x), imaginary(y) {}

	double GetReal();

	double GetImaginary();

	double GetModule()const;

	double GetArgument()const;

	Complex GetLogarithm()const;

	Complex GetComplexSin()const;

	Complex GetComplexCos()const;

	Complex ComplexPow(double power)const;

	Complex ComplexPow(Complex power)const;

	friend Complex operator+(Complex l_complex, Complex r_complex);

	friend Complex operator-(Complex l_complex, Complex r_complex);

	friend Complex operator*(double x, Complex complex);

	friend Complex operator*(Complex l_complex, Complex r_complex);

	friend ostream& operator<<(ostream& stream, Complex complex);
};
