#include <iostream>
#include <iomanip>

void Print_array(int** ptr, int n) {
	for (size_t i = 0; i < n; ++i) {
		if (ptr[i] != nullptr) {
			for (size_t j = 0; j < n; ++j) {
				std::cout << ptr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
}

void Fill_array(int** ptr, int n) {
	for (size_t i = 0; i < n; ++i) {
		if (ptr[i] != nullptr) {
			for (size_t j = 0; j < n; ++j) {
				std::cin >> ptr[i][j];
			}
		}
	}
}


int main()
{
	/*const int n = 8, m = 6, k = 4;
	char arr[n][m][k] = {};

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			for (size_t l = 0; l < k; ++l) {
				arr[i][j][l] = 'L';
			}
		}
	}

	size_t count = 0;
	size_t spaces = 1;

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			for (size_t l = 0; l < k; ++l) {
				if (count == 0) {
					std::cout << std::setw(spaces++) << arr[i][j][l];
					++count;
				}
				else {
					std::cout << arr[i][j][l];
					++count;
				}
				if (count == 12) {
					std::cout << std::endl;
					count = 0;
				}
			}
		}
	}*/

	int n = 0;
	std::cout << "Enter n: ";
	std::cin >> n;
	int** arr = new int* [n];

	for (size_t i = 0; i < n; ++i) {
		arr[i] = new int[n];
	}

	std::cout << "Enter your matrix: ";

	Fill_array(arr, n);

	int p = 0, q = 0;
	std::cout << "Enter p and q: ";
	std::cin >> p >> q;
	size_t count = 0;

	std::cout << "Find " << arr[p][q] << std::endl;

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (arr[i][j] == arr[p][q]) {
				++count;
				std::cout << i << ' ' << j << std::endl;
			}
		}
	}

	std::cout << "Count of this value in matrix : ";
	std::cout << count << std::endl;

	delete[] arr[p];
	arr[p] = nullptr;

	std::cout << "Matrix without string with this element:\n";
	Print_array(arr, n);

	for (size_t i = 0; i < n; ++i) {
		if (arr[i] != nullptr) {
			delete[] arr[i];
			arr[i] = nullptr;
		}
	}
	
	delete[] arr;
	arr = nullptr;
	return 0;
}
