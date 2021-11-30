#include <iostream>
using namespace std;
unsigned sieve(int arr[], unsigned begin)
{
    int save[10000];
    for (int i{0}; i < 10000; ++i)
    {
        save[i] = i;
    }
    unsigned diff;
    for (unsigned i{2}; i < 10000; ++i)
    {
        if (save[i] != -1)
        {
            arr[begin] = save[i];
            ++begin;
            diff = i;
            for (unsigned j{diff * 2}; j < 10000; j += diff)
            {
                save[j] = -1;
            }
        }
    }
    return begin;
}
void print(int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int primes[10000]{};
    unsigned end{sieve(primes, 0)};
    print(primes, 0, end);

    return 0;
}