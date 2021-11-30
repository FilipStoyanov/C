#include <iostream>
using namespace std;
bool alternating_number(unsigned n)
{
    unsigned least_digit_number{1};
    unsigned copy_number{n};
    while (copy_number > 9)
    {
        unsigned first_digit{copy_number % 10};
        unsigned second_digit{(copy_number / 10) % 10};
        if ((least_digit_number % 2 == 1 && first_digit <= second_digit) || (least_digit_number % 2 == 0 && first_digit >= second_digit))
        {
            return false;
        }
        copy_number /= 10;
        ++least_digit_number;
    }
    return true;
}
bool alternating_number_in_range(unsigned p, unsigned q)
{
    for (unsigned number{p}; number <= q; ++number)
    {
        if (alternating_number(number))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    unsigned p, q;
    std::cin >> p >> q;
    std::cout << std::boolalpha << alternating_number_in_range(p, q) << std::endl;

    return 0;
}