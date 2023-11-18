#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, count;
	std::cout << "Введите количество значений k: ";
	std::cin >> count;

	for (size_t i = 0; i < count; i++)
	{
		std::cin >> n;
		int fib1 = 1, fib2 = 1, summ = 0;
		for (size_t j = 0; j < n; j++)
		{
			summ += fib1;
			int temp = fib2;
			fib2 += fib1;
			fib1 = temp;
		}
		std::cout << summ << ' ';
	}
	std::cout << '\n';
	/*for (size_t i = 0; i < count; i++)
	{
		int fib1 = 1, fib2 = 1, summ = 0;
		std::cin >> n;

		while (n > 0)
		{
			summ += fib1;
			int temp = fib2;
			fib2 += fib1;
			fib1 = temp;
			n--;
		}
		std::cout << summ << ' ';
	}
	std::cout << '\n';*/
	/*for (size_t i = 0; i < count; i++)
	{
		int fib1 = 0, fib2 = 1, summ = 0;
		std::cin >> n;
		do
		{
			summ += fib1;
			int temp = fib2;
			fib2 += fib1;
			fib1 = temp;
			n--;
		} while (n >= 0);
		std::cout << summ << ' ';
	}
	std::cout << '\n';*/

	//return 0;
	return EXIT_SUCCESS;
}