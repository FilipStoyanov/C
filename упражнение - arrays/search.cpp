#include <iostream>
using namespace std;
unsigned search(const int arr[], unsigned begin, unsigned end,
                const int s_arr[], unsigned s_begin, unsigned s_end)
{
    unsigned j{0};
    unsigned save_begin_index;
    bool flag;
    for(unsigned i{begin}; i < end; ++i){
        if(arr[i] == s_arr[s_begin]){
            unsigned k{i+1};
            flag=false;
            for(unsigned j{s_begin + 1}; j < s_end-s_begin && flag != true; j++ ){
               if(arr[k++] != s_arr[j]){
                   flag = true;
                   std::cout<<"yes"<<std::endl;
               }
               std::cout<<k<<std::endl;
            }
            if(flag != true){
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
    const int arr[]{ 1, 2, 3 };
    const int seq[]{2, 3, 4};
    unsigned s_begin = search(arr, 0, 3, seq, 0, 2);
    print(arr, s_begin, 3); // -> 2 3

    return 0;
}