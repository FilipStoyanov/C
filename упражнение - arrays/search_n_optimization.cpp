#include <iostream>
using namespace std;
unsigned search_n(const int arr[], unsigned begin, unsigned end, unsigned count, int elem)
{
    unsigned copy_counter;
    bool flag;
    unsigned k;
    for (unsigned i{begin}; i < end; ++i)
    {
        if (arr[i] == elem)
        {
            k=i;
            flag = true;
            copy_counter = count ;
            unsigned count_repeating{1};
            for(unsigned j{1}; j < count && count_repeating != count; ++j)
            {
                if (arr[++k] == elem)
                {
                    ++count_repeating;
                }
            }
            if (count_repeating == count)
            {
                return i;
            }
        }
    }
    return end;
}
void print(const int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    const int arr[]{0, 1, 1, 2, 1, 1, 1};
    const int s_begin = search_n(arr, 0, 6, 3, 1);
    print(arr, s_begin, s_begin+3); // -> 1 1 1

    return 0;
}