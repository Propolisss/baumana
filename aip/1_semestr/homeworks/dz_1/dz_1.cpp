#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

double sh(double x_)
{
    double summ = x_, prev = x_, eps = 1e-15;
    
    for (size_t i = 1; std::fabsl(prev) >= eps; i += 2)
    {
        prev *= (x_ * x_) / static_cast<double>((i + 1) * (i + 2));
        summ += prev;
    }
    
    return summ;
}
double ch(double x_)
{
    double summ = 1, prev = 1, eps = 1e-15;

    for (size_t i = 0; std::fabsl(prev) >= eps; i += 2)
    {
        prev *= (x_ * x_) / static_cast<double>((i + 1) * (i + 2));
        summ += prev;
    }

    return summ;
}

double sinus(double x_)
{
    double summ = x_, prev = x_, eps = 1e-15;

    for (size_t i = 1; std::fabsl(prev) >= eps; i += 2)
    {
        prev *= -(x_ * x_) / static_cast<double>((i + 1) * (i + 2));
        summ += prev;
    }

    return summ;
}
double cosinus(double x_)
{
    double summ = 1, prev = 1, eps = 1e-15;

    for (size_t i = 0; std::fabsl(prev) >= eps; i += 2)
    {
        prev *= -(x_ * x_) / static_cast<double>((i + 1) * (i + 2));
        summ += prev;
    }

    return summ;
}
double f(double x_)
{
    return std::powl(x_, 1.5);
}



int main()
{
    setlocale(LC_ALL, "RU");


    // CHAPTER 1 ============================================
    // part 1.1 ============================================
    /*double y;
    y = 1;
    std::cout << "После инициализации y = " << y << std::endl;
    y = y / 6000;
    y = std::exp(y);
    y = std::sqrt(y);
    y = y / 14;
    y = 14 * y;
    y = y * y;
    y = std::log(y);
    y = 6000 * y;
    std::cout << "После преобразований y = " << y << std::endl;*/
    // part 1.2 ============================================
    /*double y1 = 0, y2 = 0, y = 0, x = 0, delta_rel = 0, delta_abs = 0, ep = 0;
    std::cout << std::setprecision(16);
    
    for (double x = 5; x <= 25; x += 5)
    {
        y1 = sh(x);
        y2 = ch(x);
        y = std::powl(y2, 2) - std::powl(y1, 2);
        delta_abs = std::fabsl(1 - y);
        delta_rel = delta_abs / 1;
        std::cout << x << std::setw(30) << y1 << std::setw(30) << y2 << std::setw(30) << y << std::setw(30)
            << delta_abs << std::setw(30) << delta_rel << std::endl;
    }*/
    // part 1.3 ============================================
    /*std::cout << std::setprecision(15);

    for (double i = -1; i <= 1; i += 0.1)
    {
        std::cout << std::fabsl(std::powl(sinus(i), 2) + std::powl(cosinus(i), 2)) << std::endl;
    }*/
    // CHAPTER 1 ============================================






    // CHAPTER 2 ============================================
    // part 2.2
    /*double x = 0, y = 0, w = 0;
    std::cout << "Введите x y w: ";
    std::cin >> x >> y >> w;

    x *= x;
    y = y * y + 5;
    w = w * w - 5;
    
    if (x >= y && x >= w)
        std::cout << x;
    else if (y >= x && y >= w)
        std::cout << y;
    else
        std::cout << w;*/


    // part 2.3
    double len = 0, eps = 0, correct = 9.073415289388, delta_y = 0, delta_x_2 = 0;
    double n = 0.5;
    std::cout << std::setprecision(12) << std::fixed;
    std::cout << "Введите желаемую точность: ";
    std::cin >> eps;
    
    while (std::fabsl(len - correct) >= eps)
    {
        n *= 2;
        len = 0;
        delta_x_2 = std::powl(4 / n, 2);
        for (double x = 4 / n; x <= 4; x += 4 / n)
        {
            delta_y = f(x) - f(x - 4 / n);
            len += std::sqrtl(std::pow(delta_y, 2) + delta_x_2);
        }
    }

    std::cout << len << ' ' << correct - len << ' ' << n << std::endl;


    // CHAPTER 2 ============================================


    return EXIT_SUCCESS;
}