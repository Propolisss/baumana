#include "Trap.hpp"
#include <cmath>

double trap(double a, double b, double n, double(*func)(double x))
{
	double summ = 0.f;
	double h = (b - a) / n;

	for (size_t i = 2; i < n; ++i) {
		summ += func(a + h * i);
	}

	summ = h * ((func(a) + func(b)) / 2 + summ);

	return summ;
}

double func1(double x) {
	return x + std::cos(x);
}

double func2(double x) {
	return std::tan(x + 1) / (x + 1);
}
