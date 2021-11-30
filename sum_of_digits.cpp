#include <iostream>
using namespace std;
bool is_equal_sum(unsigned n)
{
    unsigned even_sum{0};
    unsigned odd_sum{0};
    while (n > 0)
    {
        (n % 10) % 2 == 0 ? (even_sum += n % 10) : (odd_sum += n % 10);
        n /= 10;
    }
    return (even_sum == odd_sum);
}
int main()
{
    unsigned n;
    std::cin >> n;
    std::cout << std::boolalpha << is_equal_sum(n) << std::endl;

    return 0;
}