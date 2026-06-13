#include <stdio.h>
#include "fact.h"

int main()
{
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    printf("fact(%d) = %d\n", n, factorial(n));
    return 0;
}