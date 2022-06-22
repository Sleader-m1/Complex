#include <iostream>
#include <cmath>
#include"Complex.h"
using namespace std;

Complex Rieman_Sum(Complex power) {
	Complex new_power(-power.GetReal(), -power.GetImaginary());
	Complex sum(1, 0);
	if (power.GetReal() > 1) {
		for (int i = 2; i < 5000; ++i) {
			Complex num(i, 0);
			sum = sum + num.ComplexPow(new_power);
		}
	}
	else if (power.GetReal() < 1) {
		new_power = Complex(-abs(power.GetReal() - 1)-1, -power.GetImaginary());
		for (int i = 2; i < 10000; ++i) {
			Complex num(i, 0);
			sum = sum - num.ComplexPow(new_power);
		}
	}
	return sum;
}

int main()
{
	Complex com(0.5, 1);
	cout << com;
}
