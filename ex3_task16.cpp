#include <iostream>
using namespace std;
int main()
{
    double x0{10};
    unsigned number;
    std::cin >> number;
    unsigned iterations;
    std::cin >> iterations;
    double f0, f1, x1;
    for (unsigned i{0}; i < iterations; ++i)
    {
        f0 = x0 * x0 - number;
        f1 = 2 * x0;
        x1 = x0 - f0 / f1;
        x0 = x1;
    }
    std::cout << x1 << std::endl;
    return 0;
}