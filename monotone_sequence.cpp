#include <iostream>
using namespace std;

bool is_monotone(unsigned n)
{
    if (n < 1)
        return false;
    double number1;
    std::cin >> number1;
    double last_number{number1};
    double number2;
    std::cin >> number2;
    bool increase{number1 < number2};
    for (unsigned i{2}; i < n; ++i)
    {
        std::cin >> number1;
        if ((last_number < number1 && !increase) || (last_number > number1 && increase))
        {
            return false;
        }
        last_number = number1;
    }
    return true;
}
int main()
{

    unsigned n;
    std::cin >> n;
    std::cout << std::boolalpha << is_monotone(n);

    return 0;
}