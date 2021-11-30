#include <iostream>
using namespace std;
bool two_with_given_sum(const int arr[], unsigned begin, unsigned end, int sum)
{
    unsigned left_counter{begin};
    unsigned right_counter{end - 1};
    while (left_counter != right_counter)
    {
        if (arr[left_counter] + arr[right_counter] == sum)
        {
            return true;
        }
        else if (arr[left_counter] + arr[right_counter] > sum)
        {
            --right_counter;
        }
        else
        {
            ++left_counter;
        }
    }
    return false;
}

bool three_with_given_sum(const int arr[], unsigned begin, unsigned end, int sum)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        if (two_with_given_sum(arr, ++i, end, sum-arr[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[]{1, 2, 3, 4};
    std::cout << std::boolalpha << two_with_given_sum(arr, 0, 4, 7)<<std::endl;
    std::cout << std::boolalpha << three_with_given_sum(arr, 0, 4, 5);

    return 0;
}