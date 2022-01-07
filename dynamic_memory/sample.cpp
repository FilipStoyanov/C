#include <iostream>
#include <random>
#include <iterator>
using namespace std;
bool search(int *begin, int *end, int el)
{
    while (begin != end)
    {
        if (*begin == el)
        {
            return true;
        }
        ++begin;
    }
    return false;
}
int *sample(const int *begin, const int *end, int *out, unsigned samples)
{
    const int size = end - begin;
    const int *copy_begin{begin};
    int *copy_out{out};
    unsigned curr{0};
    while (curr < samples)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        int res = std::uniform_int_distribution<>(0, size)(gen);
        if (!search(out, copy_out, *(begin + res)))
        {
            *copy_out = *(begin + res);
            ++copy_out;
            ++curr;
        }
    }
    return copy_out;
}
int main()
{
    int arr[8]{0, 1, 2, 3, 4, 5, 6, 7};
    int samples[3];
    int *samples_end{sample(std::begin(arr), std::end(arr), std::begin(samples), 3)};

    for (int *i = std::begin(samples); i < samples_end; ++i)
    {
        std::cout << *i << ' ';
    }

    std::cout << '\n';

    samples_end = sample(std::begin(arr), std::end(arr), std::begin(samples), 3);

    for (int *i = std::begin(samples); i < samples_end; ++i)
    {
        std::cout << *i << ' ';
    }

    /*
    0 3 5
    7 4 8
*/

    return 0;
}