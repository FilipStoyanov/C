#include <iostream>
using namespace std;
unsigned find(const int arr[], unsigned begin, unsigned end, int element)
{
    for (; begin < end; ++begin)
    {
        if (arr[begin] == element)
        {
            return begin;
        }
    }

    return end;
}
unsigned find_first_of(const int arr[], unsigned begin, unsigned end,
                       const int s_arr[], unsigned s_begin, unsigned s_end)
{
    unsigned find_index;
    for(unsigned i{s_begin}; i < s_end; ++i){
        find_index = find(arr,begin,end, s_arr[i]);
        if(find_index != end){
            return find_index;
        }
    }
    return end;
}

int main()
{
    const int arr[]{0, 1, 2, 3, 4};
    const int seq[]{5, 4};

    unsigned found = find_first_of(arr, 0, 5, seq, 0, 2);
    std::cout << arr[found]; // -> 2

    return 0;
}