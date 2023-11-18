#include <iostream>

int main() 
{
	size_t n = 0;
	int count_inversion = 0;
	std::cin >> n;
	int* arr = new int[n];

	for (size_t i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	
	for (size_t i = 0; i < n - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			++count_inversion;
		}
	}

	std::cout << count_inversion << std::endl;


	delete[] arr;
	arr = nullptr;

	return 0;
}