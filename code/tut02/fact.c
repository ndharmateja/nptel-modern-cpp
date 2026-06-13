#include <stdlib.h>

int factorial(unsigned int n)
{
    int result = 1;
    for (size_t i = 2; i <= n; i++)
        result *= i;
    return result;
}