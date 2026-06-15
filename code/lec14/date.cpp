#include <iostream>

// 12 x 4 = 48 bytes allocated for month_names
// 7 x 10 = 70 bytes allocated for day_names (even though some of the day strings
// are smaller than 10 characters long)
// But these are read-write. If we had used char* month_names[12]
// and char* day_names[7], then these would be read-only.
char month_names[][4] = {"Jan", "Feb", "Mar", "Apr",
                         "May", "Jun", "Jul", "Aug",
                         "Sep", "Oct", "Nov", "Dec"};
char day_names[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday",
                        "Friday", "Saturday", "Sunday"};
enum Month
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};
enum Day
{
    Mon = 1,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
};
typedef unsigned int UINT;

class Date
{
    UINT date_;
    Month month_;
    UINT year_;

public:
    Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m), year_(y)
    {
        std::cout << "ctor: ";
        print();
    }
    ~Date()
    {
        std::cout << "dtor: ";
        print();
    }
    void print()
    {
        std::cout << date_ << "/"
                  << month_names[month_ - 1] << "/"
                  << year_ << std::endl;
    }
};

// Expected output:
// ctor: 30/Jul/1961
// 30/Jul/1961
// dtor: 30/Jul/1961
int main()
{
    Date d(30, 7, 1961);
    d.print();

    return 0;
}
