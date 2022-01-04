#include <iostream>
#include <iterator>
using namespace std;
const int *search_n(const int *begin, const int *end, unsigned count, int elem)
{
    int reps{0};
    while (begin != end)
    {
        reps = 0;
            for (const int *it{begin}; it != end && *it == elem; ++it)
            {
                ++reps;
                if (reps == count)
                {
                    return begin;
                }
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
    const int arr[]{0, 1, 1, 2, 1, 1, 1};
    const int *s_begin = search_n(std::begin(arr), std::end(arr), 3, 1);
    print(s_begin, std::end(arr)); // -> 1 1 1

    return 0;
}