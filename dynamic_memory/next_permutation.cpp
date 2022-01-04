#include <iostream>
#include <algorithm>
using namespace std;
void reverse(int *begin, int *end)
{
    while (begin != end && begin != --end)
    {
        std::swap(*begin, *end);
        ++begin;
    }
}
bool next_permutation(int *&begin, int *&end)
{
    if (begin == end)
    {
        return false;
    }
    int *iter_begin = begin;
    ++iter_begin;
    if (iter_begin == end)
    {
        return false;
    }

    iter_begin = end;
    --iter_begin;

    while (true)
    {
        int *iter_end = iter_begin;
        --iter_begin;

        if (*iter_begin < *iter_end)
        {
            int *copy_end = end;

            while (!(*iter_begin < *--copy_end))
            {
                std::swap(*iter_begin, *copy_end);
                reverse(iter_end, end);
                return true;
            }
        }

        if (iter_begin == begin)
        {
            reverse(begin, end);
            return false;
        }
    }
}
int main()
{
    int arr[]{1, 2, 3};

    do
    {
        for (int num : arr)
        {
            std::cout << num << ' ';
        }

        std::cout << std::endl;
    } while (next_permutation(std::begin(arr), std::end(arr)));

    /*
        1 2 3
        1 3 2
        2 1 3
        2 3 1
        3 1 2
        3 2 1
    */

    return 0;
}