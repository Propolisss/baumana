#include <iostream>
#include <cmath>



int main()
{
    double x = 0;
    bool flag = false;
    int count = 0;
    std::cin >> x;

    for (size_t n = 1; n <= 50; n++)
    {
        if (std::sin(std::pow(x, n)) < 0)
            ++count;
    }

    if (count > 3)
        flag = true;

    std::cout << flag;



    return 0;
}
