#include <iostream>

class Point
{
    int x_, y_;

public:
    Point(int x, int y) : x_(x), y_(y)
    {
        std::cout << "Point ctor: ";
        print();
        std::cout << std::endl;
    }
    ~Point()
    {
        std::cout << "Point dtor: ";
        print();
        std::cout << std::endl;
    }
    void print()
    {
        std::cout << "(" << x_ << ", "
                  << y_ << ")";
    }
};

class Rect
{
    Point tl_, br_;

public:
    // ! If we used tl_(Point(tlx, tly)) and br_(Point(brx, bry)) instead
    // ! then temporary copies of the Point objects are created and those destructors also called
    // ! Note: We have to disable compiler optimizations to be able to see that
    // ! Use: g++ -std=c++14 -fno-elide-constructors point_rect.cpp
    Rect(int tlx, int tly, int brx, int bry) : tl_(tlx, tly), br_(brx, bry)
    {
        std::cout << "Rect ctor: ";
        print();
    }
    ~Rect()
    {
        std::cout << "Rect dtor: ";
        print();
    }
    void print()
    {
        std::cout << "[";
        tl_.print();
        std::cout << " ";
        br_.print();
        std::cout << "]" << std::endl;
    }
};

// Expected output:
// Point ctor: (0, 2)
// Point ctor: (5, 7)
// Rect ctor: [(0, 2) (5, 7)]
//
// [(0, 2) (5, 7)]
//
// Rect dtor: [(0, 2) (5, 7)]
// Point dtor: (5, 7)
// Point dtor: (0, 2)
// ! The destructor of the Rect r object is called as we exit the main fn
// ! As we finish the destructor's body of Rect, it calls the destructors
// ! of the member variables in the reverse order of constructors
int main()
{
    Rect r(0, 2, 5, 7);

    std::cout << std::endl;
    r.print();
    std::cout << std::endl;
}