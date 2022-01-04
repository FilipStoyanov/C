#include <iostream>
using namespace std;
const int *find_first_of(const int *begin, const int *end, const int *s_begin, const int *s_end)
{
    while (begin != end)
    {
        for (const int *it{s_begin}; it != s_end; ++it)
        {
            if (*it == *begin)
            {
                return begin;
            }
        }
        ++begin;
    }
    return end;
}
int main()
{
    const int arr[]{0, 1, 2, 3, 4};
    const int seq[]{2, 4};

    const int *found = find_first_of(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
    std::cout << *found; // -> 2

    return 0;
}