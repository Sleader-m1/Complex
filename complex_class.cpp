#include <iostream>
#include <cmath>
#include"Complex.h"
using namespace std;

double Complex::GetReal() {
	return real;
}

double Complex::GetImaginary() {
	return imaginary;
}

double Complex::GetModule() const {
	return sqrt(real * real + imaginary * imaginary);
}

double Complex::GetArgument() const {
	return atan(imaginary / real);
}

Complex Complex::GetLogarithm() const {
	double log_real = log(GetModule());
	double log_imaginary = GetArgument();
	return Complex(log_real, log_imaginary);
}

Complex Complex::GetComplexSin() const {
	double sin_real = sin(real) * (exp(imaginary) + exp(-imaginary)) / 2;
	double sin_imaginary = cos(real) * (exp(imaginary) - exp(-imaginary)) / 2;
	return Complex(sin_real, sin_imaginary);
}

Complex Complex::GetComplexCos() const {
	double cos_real = cos(real) * (exp(imaginary) + exp(-imaginary)) / 2;
	double cos_imaginary = sin(real) * (exp(imaginary) - exp(-imaginary)) / 2;
	return Complex(cos_real, cos_imaginary);
}

Complex Complex::ComplexPow(double power) const {
	Complex result = *this;
	double _module = pow(result.GetModule(), power);
	double arg = result.GetArgument();
	Complex _expon(cos(power * arg), sin(power * arg));
	return _module * _expon;
}

Complex Complex::ComplexPow(Complex power) const {
	Complex result = *this;
	Complex power_real = result.ComplexPow(power.real);
	Complex complex_log = power.imaginary * result.GetLogarithm();
	Complex power_imaginary = complex_log.GetComplexCos() + complex_log.GetComplexSin() * Complex(0, 1);
	return power_real * power_imaginary;
}

Complex operator+(Complex l_complex, Complex r_complex) {
	return Complex(l_complex.real + r_complex.real,
		l_complex.imaginary + r_complex.imaginary);
}

Complex operator-(Complex l_complex, Complex r_complex) {
	return Complex(l_complex.real - r_complex.real,
		l_complex.imaginary - r_complex.imaginary);
}

Complex operator*(double x, Complex complex) {
	return Complex(complex.real * x, complex.imaginary * x);
}

Complex operator*(Complex l_complex, Complex r_complex) {
	double res_real = l_complex.real * r_complex.real -
		l_complex.imaginary * r_complex.imaginary;
	double res_imaginary = l_complex.real * r_complex.imaginary +
		l_complex.imaginary * r_complex.real;
	return Complex(res_real, res_imaginary);
}

ostream& operator<<(ostream& stream, Complex complex) {
	if (complex.GetReal() != 0)
		stream << complex.GetReal();
	if (complex.imaginary != 0)
		stream << (complex.GetImaginary() < 0 ? "-" : "+")
		<< abs(complex.GetImaginary()) << "i";
	return stream;
}
