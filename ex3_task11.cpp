#include <iostream>
using namespace std;
int main()
{
    unsigned a, b;
    std::cin >> a >> b;
    unsigned copy_a{a};
    unsigned copy_b{b};
    const bool isHaveZero{copy_a == 0 || copy_b == 0};
    while (copy_a != copy_b && !isHaveZero)
    {
        if (copy_a >= copy_b)
        {
            copy_a = copy_a - copy_b;
        }
        else
        {
            copy_b = copy_b - copy_a;
        }
    }
    isHaveZero ? std::cout << 1 : std::cout << copy_a << std::endl;

    return 0;
}