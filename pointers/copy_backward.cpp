#include <iostream>
using namespace std;
int *copy_backward(const int *begin, const int *end, int *output_begin)
{
    const int* copy_end{end};
    --copy_end;
    --begin;
    int* output_start{output_begin};
    while( copy_end != begin){
        *output_begin = *copy_end;
        --copy_end;
        ++output_begin;
    }
    return output_start;
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
    const int arr[]{1, 2, 3};
    int backward_copy[3]{};

    copy_backward(std::begin(arr), std::end(arr), std::begin(backward_copy));
    print(std::begin(backward_copy), std::end(backward_copy)); // -> 3 2 1


    return 0;
}