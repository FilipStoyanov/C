#include <iostream>
using namespace std;
bool is_power(unsigned number)
{
    while (number % 2 == 0)
    {
        number /= 2;
    }
    return (number == 1);
}
int largest_power_of_2(unsigned n)
{
    unsigned max_number = 1;
    unsigned number;
    for (unsigned i{0}; i < n; ++i)
    {
        std::cin >> number;
        if (is_power(number) && number > max_number)
        {
            max_number = number;
        }
    }
    return max_number;
}
int main()
{

    unsigned n;
    std::cin >> n;
    std::cout << largest_power_of_2(n) << std::endl;

    return 0;
}