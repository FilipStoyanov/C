#include <iostream>
using namespace std;
const unsigned max_size{3};
void transpose(const int arr[max_size][max_size], unsigned rows, unsigned columns, int arr_t[max_size][max_size])
{
    for (unsigned i{0}; i < max_size; ++i)
    {
        for (unsigned j{0}; j < max_size; ++j)
        {
            arr_t[i][j] = arr[j][i];
        }
    }
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
int main()
{
    const int arr[][max_size]{
        {1, 2},
        {3, 4},
        {5, 6}};

    int arr_t[max_size][max_size]{};
    transpose(arr, 3, 3, arr_t);
    print(arr_t, 3, 3);

    /*
1 3 5
2 4 6
*/

    return 0;
}