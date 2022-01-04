#include <iostream>
#include <algorithm>
using namespace std;
void swap_ranges(int* begin_1, int* end_1, int* begin_2){
    while(begin_1 != end_1){
        std::swap(*begin_1, *begin_2);
        ++begin_2;
        ++begin_1;
    }
}
void print(const int *begin, const int *end)
{
    for (const int *it{begin}; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int arr1[]{1, 3, 5};
    int arr2[]{2, 4, 6};

    swap_ranges(std::begin(arr1), std::end(arr1), std::begin(arr2));
    print(std::begin(arr1), std::end(arr1)); // -> 2 4 6
    print(std::begin(arr2), std::end(arr2)); // -> 1 3 5

    return 0;
}