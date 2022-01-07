#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
bool equal(const int *begin_1, const int *end_1, const int *begin_2, const int *end_2)
{
    const int *el_1{begin_1};
    const int *el_2{begin_2};
    if (end_1 - begin_1 != end_2 - begin_2)
    {
        return false;
    }
    while (el_1 != end_1 || el_2 != end_2)
    {
        if (*el_1 != *el_2)
        {
            return false;
        }
        ++el_1;
        ++el_2;
    }
    return true;
}
int main()
{
    const int arr[]{1, 2, 1, 3};
    const int arr2[]{1, 2};
    std::cout << std::boolalpha << equal(std::begin(arr), std::begin(arr) + 2, std::begin(arr2), std::end(arr2)); // -> true
    std::cout << std::boolalpha << equal(std::begin(arr) + 2, std::end(arr), std::begin(arr2), std::end(arr2));   // -> false
    return 0;
}