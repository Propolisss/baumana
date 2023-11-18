#include <iostream>

int main()
{
	int n = 10;
	std::cout << "Enter size of your matrix: ";
	std::cin >> n;
	int** arr = new int*[n];

	for (size_t i = 0; i < n; ++i) {
		arr[i] = new int[n];
	}

	std::cout << "Enter your matrix: ";
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			std::cin >> arr[i][j];
		}
	}
	std::cout << std::endl;

	int maxx = arr[0][1];
	int minn = arr[1][0];

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (i == j) {
				std::cout << arr[i][j] << ' ';
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

	return 0;
}