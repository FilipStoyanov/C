#include <iostream>
using namespace std;
bool duplicate_digits(unsigned n)
{
    unsigned copy_n{n};
    unsigned new_number;
    unsigned curr_digit;
    while (copy_n > 0)
    {
        curr_digit = copy_n % 10;
        new_number = copy_n / 10;
        while (new_number > 0)
        {
            if (curr_digit == new_number % 10)
            {
                return true;
            }
            new_number /= 10;
        }
        copy_n /= 10;
    }
    return false;
}
int main()
{
    unsigned number;
    std::cin >> number;
    std::cout << std::boolalpha << duplicate_digits(number) << std::endl;
    return 0;
}