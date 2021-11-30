#include <iostream>
using namespace std;
void print(int arr[], unsigned begin, unsigned end)
{
    for (unsigned i{begin}; i < end; ++i)
    {
        std::cout << arr[i] << " ";
    }
}
void count_sort(int arr[], unsigned begin, unsigned end)
{
    int count_reps[100]{0};
    for(unsigned i{begin}; i<end;++i){
        ++count_reps[arr[i]];
    }
    unsigned counter{begin};
    for(unsigned i{0}; i<100; ++i){
        for(unsigned j{0}; j< count_reps[i]; ++j){
            arr[counter] = i; 
            ++counter;
        }
    }
}
int main()
{
    int arr[]{1, 0, 2, 2, 1};
    count_sort(arr, 0, 5);
    print(arr,0,5);

    return 0;
}