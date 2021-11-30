#include <iostream>
using namespace std;
bool is_set(const int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end - 1; ++i)
    {
        if (arr[i] >= arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int set[]{1, 2, 3};
std:
    cout << std::boolalpha << is_set(set, 0, 3) << std::endl;

    return 0;
}