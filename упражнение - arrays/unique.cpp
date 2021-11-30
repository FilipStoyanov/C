#include <iostream>
using namespace std;
void print(int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
unsigned unique(int arr[], unsigned begin, unsigned end)
{
    unsigned copy_end{end};
    unsigned counter{begin};
    unsigned diff;
    for (unsigned i{begin}; i < copy_end - 1; ++i)
    {
        diff = 1;
        while (arr[i] == arr[i + diff])
        {
            ++diff;
        }
        if (diff > 1)
        {
            for (unsigned j{i + 1}; j <= copy_end - (diff-1); ++j)
            {
                arr[j] = arr[j + diff -1];
            }
            copy_end -= (diff - 1);
        }
    }
    return copy_end;
}
int main()
{

    int arr[]{0, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 4,4, 5, 5, 6, 6,6};
    unsigned end{unique(arr, 0, 19)};

    print(arr, 0, end); // -> 0 1 2 3 4 5

    return 0;
}