#include <iostream>
#include <cmath>
using namespace std;
void print(int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
}
bool is_prime(unsigned n)
{
    if (n == 0 || n == 1)
        return false;
    if (n == 2)
        return true;
    for (unsigned i{2}; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
unsigned sieve_10000(int arr[], unsigned begin)
{
    int save[10000];
    for (int i{0}; i < 10000; ++i)
    { // initialize array with all digits from 1 to 10000
        save[i] = i;
    }
    for (int ind{0}; ind < 10000; ++ind)
    {
        if (is_prime(save[ind]))
        {
            for (int i{ind * 2}; i < 10000; i += ind)
            {
                save[i] = -1;
            }
        }
    }
    unsigned counter{0};
    for (unsigned i{0}; i < 10000; ++i)
    {
        if (save[i] != -1)
        {
            arr[begin + counter] = save[i];
            ++counter;
        }
    }
    return (begin + counter);
}
int main()
{
    int primes[10000]{};
    unsigned end{sieve_10000(primes, 0)};
    print(primes, 0, end);
    return 0;
}