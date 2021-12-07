#include <iostream>
using namespace std;
const unsigned max_size{100};
void spiral(const int arr[max_size][max_size], unsigned size, int output[], unsigned first)
{
    for (unsigned start{0}; size > start; --size, ++start)
    {
        for (unsigned i{start}; i < size; ++i)
        {
            std::cout << arr[start][i] << " ";
        }
        for (unsigned i{start + 1}; i < size; ++i)
        {
            std::cout << arr[i][size - 1] << " ";
        }
        for (unsigned i{size - 2}; i > start; --i)
        {
            std::cout << arr[size - 1][i] << " ";
        }
        for (unsigned i{size - 1}; i > start; --i)
        {
            std::cout << arr[i][start] << " ";
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
    const int sp4[][max_size]{
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7},
    };

    int spiral_arr4[16]{};

    spiral(sp4, 4, spiral_arr4, 0);

    // for (int num : spiral_arr4)
    // {
    //     std::cout << num << ' ';
    // }

    /*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/

    return 0;
}