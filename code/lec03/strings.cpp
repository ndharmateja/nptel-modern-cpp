#include <iostream>
#include <string>
#include <cstring>

int main()
{
    // string in c++
    std::string s1 = "A", s2 = "B";
    std::string s = s1 + s2;
    std::cout << "s: '" << s << "'"
              << std::endl;

    // Using string.h functions (can use c_str() or data() methods)
    // c_str() is readonly
    std::cout << "len(s): " << std::strlen(s.c_str())
              << std::endl;
    std::cout << "len(s): " << std::strlen(s.data())
              << std::endl;

    // For write, we have to use s.data() or &s[0]
    // Automatic resize won't happen, so we have to manually allocate
    s.resize(20);
    std::strcpy(s.data(), "Overwritten 1");
    std::cout << "s: '" << s << "'"
              << std::endl;
    std::strcpy(&s[0], "Overwritten 2");
    std::cout << "s: '" << s << "'"
              << std::endl;
}