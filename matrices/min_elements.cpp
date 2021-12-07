#include <iostream>
using namespace std;
const unsigned max_size{100};
unsigned min_elements(const int arr[max_size][max_size], unsigned rows, unsigned columns, int output_begin[], unsigned first)
{
    int min;
    for (unsigned i{0}; i < rows; ++i)
    {
        min = arr[i][0];
        for (unsigned j{0}; j < columns; ++j)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
        output_begin[first] = min;
        ++first;
    }
    return first;
}
void print(const int arr[][max_size], unsigned rows, unsigned columns)
{
    for (unsigned i{0}; i < rows; ++i)
    {
        for (unsigned j{0}; j < rows; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void print_arr(int arr[], unsigned end){
     for(unsigned i{0}; i < end; ++i){
         std::cout<<arr[i]<<" ";
     }
}

int main()
{
    const int arr[][max_size]{
        {1, 2},
        {0, 2},
        {5, 1}};
    int min_elems[max_size]{};
    unsigned min_elems_end{min_elements(arr, 3, 2, min_elems, 0)};
    print_arr(min_elems,min_elems_end);
    // -> 1 2 3

    return 0;
}