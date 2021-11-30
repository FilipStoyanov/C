#include <iostream>
using namespace std;
void swap_ranges(int arr_1[], unsigned begin_1, unsigned end_1,
                 int arr_2[], unsigned begin_2)
{
    unsigned counter{begin_2};
    int swap;
    for (unsigned i{begin_1}; i < end_1; ++i)
    {
        swap = arr_1[i];
        arr_1[i] = arr_2[counter];
        arr_2[counter] = swap;
        ++counter;
    }
}
void print(int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int arr1[]{1, 3, 5};
    int arr2[]{2, 4, 6};

    swap_ranges(arr1, 0, 3, arr2, 0);
    print(arr1, 0, 3); // -> 2 4 6
    print(arr2, 0, 3); // -> 1 3 5

    return 0;
}