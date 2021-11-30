#include <iostream>
using namespace std;
unsigned set_difference(const int input_1[], unsigned begin_1, unsigned end_1,
                        const int input_2[], unsigned begin_2, unsigned end_2,
                        int output[], unsigned output_begin)
{
    unsigned i{begin_1};
    unsigned j{begin_2};
    while (i < end_1 && j < end_2)
    {
        if (input_1[i] < input_2[j])
        {
            output[output_begin] = input_1[i];
            ++i;
            ++output_begin;
        }else if(input_1[i] > input_1[j]){
             ++j;
        }else{
            ++j;
            ++i;
        }
    }
    while (i < end_1)
    {
        output[output_begin] = input_1[i];
        ++output_begin;
        ++i;
    }
    while (j < end_2)
    {
        output[output_begin] = input_2[j];
        ++output_begin;
        ++j;
    }
    return output_begin;
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
    int set_1[]{1, 2, 3, 4, 7, 11};
    int set_2[]{2, 4, 7};
    int result[10]{};

    unsigned end{set_difference(set_1, 0, 6,
                                set_2, 0, 3,
                                result, 0)};

    print(result, 0, end); // -> 1 3

    return 0;
}