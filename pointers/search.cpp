#include <iostream>
#include <iterator>
using namespace std;
const int *search(const int *begin, const int *end, const int *s_begin, const int *s_end)
{
    int reps{0};
    while (begin != end)
    {
        reps = 0;
        const int* copy_it{begin};
        for (const int *it{s_begin}; it != s_end && *it == *copy_it; ++it)
            {
                ++reps;
                if (reps == s_end - s_begin)
                {
                    return begin;
                }
                ++copy_it;
            }
            ++begin;
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
    const int arr[]{0, 1, 2, 1, 2, 3};
    const int seq[]{1, 2 };
    const int *s_begin = search(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
    print(s_begin, std::end(arr)); // -> 1 2 1 2

    return 0;
}