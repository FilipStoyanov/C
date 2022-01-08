#include <iostream>
using namespace std;
int *remove(int* begin, int* end, int element)
{
    bool flag{false};
    long int length{end - begin};
    int curr{0};
    while (curr < length)
    {
          if(*(begin + curr) == element)
            {
                for (int *it{begin+curr}; it != end; ++it)
                {
                        *it = *(it + 1);
                }
                --end;
            }
        ++curr;
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
    int arr[]{0, 1, 2, 1, 4, 1, 6};
    int *new_end = remove(std::begin(arr), std::end(arr), 1);
    print(std::begin(arr), new_end); // -> 0 2 4 6

    return 0;
}