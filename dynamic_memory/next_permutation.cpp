#include <iostream>
#include <algorithm>
using namespace std;
void reverse(int *begin, int *end)
{
    while(begin != end && begin != --end)
    {
        std::iter_swap(first,last);
        ++begin;
    }
}
void print(const int *begin, const int *end)
{
    for (const int *it{begin}; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// bool next_permutation(int *begin, int *end)
// {
//     bool is_decreasing_sorted{false};
//     int *highest_smaller;
//     int *highest_bigger;
//     while (!is_decreasing_sorted)
//     {
//         highest_smaller = nullptr;
//         highest_bigger = nullptr;
//         const int *before_end = end;
//         --before_end;
//         for (int *it{begin}; it != before_end; ++it)
//         {
//             if (*it < *(it + 1))
//             {
//                 highest_smaller = it;
//             }
//         }
//         if (highest_smaller)
//         {
//             for (int *it{highest_smaller}; it != end; ++it)
//             {
//                 if (*it > *highest_smaller)
//                 {
//                     highest_bigger = it;
//                 }
//             }
//         }
//         std::cout << "smaller " << *highest_smaller << std::endl;
//         std::cout << "bigger " << *highest_bigger << std::endl;
//         if (highest_smaller && highest_bigger)
//         {
//             std::swap(*highest_smaller, *highest_bigger);
//             int *copy_bigger{highest_bigger};
//             int *copy_smaller{highest_smaller};
//             std::cout << "copy_smaller " << *highest_smaller << std::endl;
//             std::cout << "copy_bigger " << *highest_bigger << std::endl;
//             reverse(copy_smaller, copy_bigger);
//             print(begin, end);
//             is_decreasing_sorted = false;
//         }
//         else
//         {
//             is_decreasing_sorted = true;
//         }
//     }
//     if (is_decreasing_sorted)
//     {
//         reverse(begin, end);
//         print(begin, end);
//         return false;
//     }
//     return true;
// }
bool next_permutation(int *begin, int *end)
{
    if (begin == end){
        return false;
    }
    int *it_begin{begin};
    ++it_begin;
    if (it_begin == end){
        return false;
    }
    it_begin = end;
    --it_begin;
    while (true)
    {
        int *it_end{it_begin};
        --it_begin;
        if (*it_begin < *it_end)
        {
            int *copy_end{it_end};
            while (!(*it_begin < *--copy_end))
            {
                std::swap(it_begin, copy_end);
                reverse(it_end, end);
                return true;
            }
        }
        if (it_begin == begin)
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