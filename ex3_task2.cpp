#include <iostream>
using namespace std;
int main()
{
    double a;
    int b;
    double res = 1;
    cin >> a >> b;
    int copy_b = b;
    int copy_a=a;
    while (copy_b != 0)
    {
        if (copy_b % 2 != 0)
        {
            res = res * copy_a;
        }
        copy_b /= 2;
        copy_a = copy_a * copy_a;
    }
    b >= 0 ? std::cout << res : std::cout << double(1.0 / res) << std::endl;

    return 0;
}