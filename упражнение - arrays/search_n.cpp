#include <iostream>
using namespace std;
unsigned search_n(const int arr[], unsigned begin, unsigned end, unsigned count, int elem)
{
    unsigned count_matching{0};
   if(count > end - begin) return end;
    for(unsigned i{begin}; i < end; ++i){
        if(arr[i] == elem){
            count_matching = 1;
            while( arr[i+count_matching] == elem && i+count_matching < end){
                 ++count_matching;
            }
            if(count_matching == count){
                return i;
            }
        }
    }
    return end;
}
void print(const int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    const int arr[]{0, 1, 1, 2, 1, 1, 1};
    const int s_begin = search_n(arr, 0, 6, 3, 1);
    print(arr, s_begin, 7); // -> 1 1 1

    return 0;
}