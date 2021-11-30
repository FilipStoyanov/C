#include <iostream>
using namespace std;
unsigned adjacent_find(const int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end - 1; ++i)
    {
        if (arr[i] == arr[i + 1])
        {
            return i;
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
}
int main()
{
    const int arr[]{0, 1, 2, 1, 1, 2, 2};
    unsigned adj_begin = adjacent_find(arr, 0, 6);
    print(arr, adj_begin, adj_begin+2); // -> 1 1

    return 0;
}