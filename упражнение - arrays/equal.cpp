#include <iostream>
using namespace std;
bool equal(const int arr_1[], unsigned begin_1, unsigned end_1,
           const int arr_2[], unsigned begin_2, unsigned end_2)
{
    unsigned j{begin_2};
    for (unsigned i{begin_1}; i < end_1 || end_1 - begin_1 != end_2 - begin_2; ++i)
    {
        if (arr_1[i] != arr_2[j] || end_1 - begin_1 != end_2 - begin_2)
        {
            return false;
        }
        ++j;
    }
    return true;
}
int main()
{
    const int arr[]{1, 2, 1, 3};
    const int arr2[]{1, 2};

    std::cout << std::boolalpha << equal(arr, 0, 2, arr2, 0, 2)<<std::endl; // -> true
    std::cout << std::boolalpha << equal(arr, 1, 3, arr2, 0, 2)<<std::endl; // -> false

    return 0;
}