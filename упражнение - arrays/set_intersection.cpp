#include <iostream>
using namespace std;
unsigned set_intersection(const int input_1[], unsigned begin_1, unsigned end_1,
                          const int input_2[], unsigned begin_2, unsigned end_2,
                          int output[], unsigned output_begin)
{
    unsigned i{begin_1};
    unsigned j{begin_2};
    unsigned ind{output_begin};
    while (i < end_1 && j < end_2)
    {
        if (input_1[i] == input_2[j])
        {
            output[ind] = input_1[i];
            ++ind;
            ++i;
            ++j;
        }
        else if (input_1[i] < input_2[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    return ind;
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
    int set_1[]{1, 2, 3, 4};
    int set_2[]{2, 4};
    int result[10]{};

    unsigned end{set_intersection(set_1, 0, 4,
                                  set_2, 0, 2,
                                  result, 0)};

    print(result, 0, end); // -> 2 4

    return 0;
}