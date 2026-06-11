#include <iostream>
#include <cmath>

int main()
{
    double x;
    std::cout << "Input number: ";
    std::cin >> x;

    double sqrt_x = sqrt(x);
    std::cout << "Square Root of " << x
              << ": " << sqrt_x
              << std::endl;
}