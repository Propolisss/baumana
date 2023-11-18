#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Russian");
	long double x, y;

	std::cin >> x >> y;
	if ((y <= x + 1) && (y >= -x - 1) && (y >= -sqrt(-1/2. * x)) && (y <= sqrt(-1/2. * x)))
		std::cout << "Точка принадлежит заштрихованной области\n";
	else
		std::cout << "Точка не принадлежит заштрихованной области\n";

	return 0;
}