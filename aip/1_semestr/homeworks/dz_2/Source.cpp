#include "Trap.hpp"
#include <iostream>
#include <cstring>

int main()
{
	/*char arr[1000];
	std::cout << "Enter your string: ";
	gets_s(arr, 1000);

	for (size_t i = 0; i < strlen(arr); ++i) {
		for (size_t j = i + 1; j < strlen(arr); ++j) {
			if (arr[j] < arr[i]) {
				std::swap(arr[j], arr[i]);
			}
		}
	}

	std::cout << "String after sort: " << arr << std::endl;*/

	/*int n = 0;
	std::cout << "Enter your buffer size: ";
	std::cin >> n;
	char* arr = new char[n + 1];
	gets_s(arr, n + 1);
	std::cout << "Enter your string: ";
	gets_s(arr, n + 1);
	
	size_t start = 0;
	size_t end = 0;

	size_t count = 0;
	for (size_t i = 0; i < strlen(arr); ++i) {
		if (arr[i] == ' ') {
			if (arr[start] == 'A' && arr[end - 1] == 'E') {
				++count;
			}
			start = i + 1;
			end = i + 1;
		}
		else {
			++end;
		}
	}

	if (end != start && arr[start] == 'A' && arr[end - 1] == 'E') {
		++count;
	}

	std::cout << "Count words that starts with A and ends with E is: " << count << std::endl;
	delete[] arr;
	arr = nullptr;*/

	double a = 0;
	double b = 0;
	double n = 0;
	short func_num = 0;
	double (*func)(double);
	std::cout << "Enter a, b, n: ";
	std::cin >> a >> b >> n;
	std::cout << "Choose your function:\n"
		<< "1) x + cos(x)\n"
		<< "2) tg(x+1)/(x+1)\n";
	std::cin >> func_num;
	if (func_num == 1) {
		func = func1;
	}
	else {
		func = func2;
	}

	std::cout << trap(a, b, n, func) << std::endl;
		

	return 0;
}
