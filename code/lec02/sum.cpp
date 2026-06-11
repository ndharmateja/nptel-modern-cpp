#include <iostream>

int main()
{
    int a, b;
    std::cout << "Input two numbers"
              << std::endl;
    std::cin >> a >> b;

    int sum = a + b;
    std::cout << a << " + " << b << " = " << (a + b)
              << std::endl;
}