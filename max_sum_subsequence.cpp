#include <iostream>
using namespace std;
int max_sum_subsequence(unsigned n)
{
    int number;
    int sum{0};
    int max_sum{0};
    for (unsigned i{0}; i < n; ++i)
    {
        std::cin >> number;
        sum += number;
        sum = sum * (sum > 0);
        max_sum = std::max(max_sum, sum);
    }
    return max_sum;
}
int main()
{
    unsigned n;
    std::cin >> n;
    std::cout << max_sum_subsequence(n) << std::endl;

    return 0;
}