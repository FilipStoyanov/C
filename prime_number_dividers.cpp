#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(unsigned n)
{
    if (n == 0 || n == 1) return false;
    if (n == 2)  return true;
    for (unsigned i{2}; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
unsigned number_dividers(unsigned n, unsigned k)
{
    unsigned counter{0};
    for (unsigned i{1}; i < k; ++i)
    {
        if (n % i == 0)
        {
            ++counter;
        }
    }
    return counter;
}
unsigned sum_of_numbers(unsigned n)
{
    unsigned counter{0};
    unsigned sum{0};
    for (unsigned number{2}; counter < n; ++number)
    {
        unsigned dividers{number_dividers(number, n)};
        if (is_prime(dividers))
        {
            sum += number;
            ++counter;
        }
    }
    return sum;
}

int main()
{
    unsigned n;
    std::cin >> n;
    std::cout << sum_of_numbers(n) << std::endl;

    return 0;
}