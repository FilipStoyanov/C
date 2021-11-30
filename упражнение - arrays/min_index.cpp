#include <iostream>
using namespace std;
unsigned min_element(const int arr[], unsigned begin, unsigned end)
{
    int min{arr[begin]};
    unsigned min_ind{begin};
    for (unsigned i{begin}; i < end; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_ind = i;
        }
    }
    return min_ind;
}

int main()
{
    int arr[]{1, 4, 3, 0, 2};
    std::cout<<min_element(arr, 0, 5)<<std::endl; // -> 3

    return 0;
}