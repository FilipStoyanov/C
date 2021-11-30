#include <iostream>
using namespace std;
void print(const int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
}
unsigned partial_sum(const int input_arr[], unsigned input_begin, unsigned input_end,
                     int output_arr[], unsigned output_begin)
{
    int sum{input_arr[input_begin]};
    unsigned counter{output_begin};
    for (unsigned i{input_begin}; i < input_end; ++i)
    {

        sum += input_arr[i];
        output_arr[counter] = sum;
        ++counter;
    }
    return counter;
}
int main()
{

    int arr[]{0, 1, 2, 3, 4};
    int res[5]{};

    unsigned size{partial_sum(arr, 0, 5,res, 0)};

    print(res, 0, size); // -> 0 1 3 6 10;

    return 0;
}