#include <iostream>
using namespace std;
void replace(int *begin, int *end, int old_value, int new_value)
{
    while(begin != end){
        if(*begin == old_value){
            *begin = new_value;
        }
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
int main()
{
    int arr[]{0, 9, 2, 9, 3, 9};
    replace(std::begin(arr), std::end(arr), 9, 1);
    print(std::begin(arr), std::end(arr)); // -> 0 1 2 1 3 1

    return 0;
}