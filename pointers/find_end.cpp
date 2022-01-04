#include <iostream>
using namespace std;
const int *find_end(const int *begin, const int *end, const int *s_begin, const int *s_end)
{
    int reps{0};
    const int *last_occurrence;
    while (begin != end)
    {
        const int *copy_arr{begin};
        reps = 0;
        for (const int *it{s_begin}; it != s_end && *it == *copy_arr; ++it)
        {
            ++reps;
            if (reps == s_end - s_begin)
            {
                last_occurrence = begin;
            }
            ++copy_arr;
        }
        ++begin;
    }
    if (last_occurrence)
    {
        return last_occurrence;
    }
    else
    {
        return end;
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
int main()
{
    const int arr[]{0, 1, 2, 1, 2};
    const int seq[]{1, 2 };
    const int *s_begin = find_end(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
    print(s_begin, std::end(arr)); // -> 1 2

    return 0;
}