#include <iostream>
#include <utility>
int foo(int *a)
{
    *a *= 2;
    return *a;
}
void swap(int *a, int *b)
{
    int c{*a};
    *a = *b;
    *b = c;
}
void print(const int *first, const int *last){
    for( ; first < last; ++first ){
            std::cout<<*first<<" ";
    }
}
using namespace std;
int main()
{
    int a{10};
    int b{20};
    swap(&a, &b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    int arr[]{1, 2, 3};
    int *ptr = {&arr[0]};
    std::cout << *(ptr + 3) << std::endl;
    std::cout << std::begin(arr) << std::endl;  // returns pointer to arr begin
    std::cout << std::cbegin(arr) << std::endl; // returns constant pointer to arr begin
    std::cout << std::end(arr) << std::endl;    // returns pointer to the end of arr
    std::cout << std::cend(arr) << std::endl;   // returns constant pointer to the end of arr
    std::cout << std::end(arr) - std::begin(arr) << std::endl;
    print(std::cbegin(arr), std::cend(arr));
    //    std::cout<<foo(&a)<<std::endl;
    //    std::cout<<a<<std::endl;

    return 0;
}