#include <iostream>
using namespace std;
void print(const int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

unsigned adjacent_difference(const int input_arr[], unsigned input_begin, unsigned input_end,
                             int output_arr[], unsigned output_begin)
{
    unsigned counter{output_begin};
    output_arr[counter] = input_arr[counter];
    ++counter;
    int difference;
    for (unsigned i{input_begin}; i < input_end - 1; ++i)
    {
        difference = input_arr[i + 1] - input_arr[i];
        output_arr[counter] = difference;
        ++counter;
    }
    return counter;
}

int main()
{
    int arr[]{0, 1, 10, 3, 7};
    int res[5]{};

    unsigned size{adjacent_difference(arr, 0, 5,
                                      res, 0)};

    print(res, 0, size); // -> 0 1 2 3 4;

    return 0;
}