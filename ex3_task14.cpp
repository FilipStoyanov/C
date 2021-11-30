#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    unsigned number;
    std::cin >> number;
    unsigned copy_number{number};
    if (copy_number == 0 || copy_number == 1 || copy_number == 2)
    {
        std::cout << copy_number << std::endl;
        return 0;
    }
    while (copy_number % 2 == 0 && copy_number != 2)
    {
        copy_number /= 2;
        std::cout << 2 << " * ";
    }
    for (unsigned i = 3; i <= sqrt(copy_number); i += 2)
    {
        while (copy_number % i == 0 && copy_number != i)
        {
            copy_number /= i;
            std::cout << i << " * ";
        }
    }
    if (copy_number >= 2)
    {
        std::cout << copy_number << std::endl;
    }
    return 0;
}