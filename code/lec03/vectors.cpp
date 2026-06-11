#include <iostream>
#include <vector>

void print_vector(const std::vector<int> &v)
{
    std::cout << "[ ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v.at(i) << " ";
    std::cout << "]" << std::endl;
}

int main()
{
    // Both are functionally equivalent
    // filled with 0s (or whatever default value provided)
    std::vector<int> v1(10);
    print_vector(v1);

    // But this one takes multiple steps internally
    std::vector<int> v2;
    v2.resize(10);
    print_vector(v2);
}