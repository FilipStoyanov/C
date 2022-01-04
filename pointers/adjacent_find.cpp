#include <iostream>
using namespace std;
const int *adjacent_find(const int *begin, const int *end)
{
    while (begin != end)
    {
        const int *curr_el = begin;
        const int *next_el = ++begin;
        if (*curr_el == *next_el)
        {
            return curr_el;
        }
    }
    return end;
}
void print(const int *begin, const int *end)
{
    for (const int *it{begin}; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main()
{
    const int arr[]{0, 1, 2, 1, 1, 2, 2};
    const int *adj_begin = adjacent_find(std::begin(arr), std::end(arr));
    print(adj_begin, adj_begin + 2); // -> 1 1

    return 0;
}