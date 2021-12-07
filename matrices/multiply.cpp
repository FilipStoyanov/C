#include <iostream>
using namespace std;
const unsigned max_size{100};
void multiply(const int a[max_size][max_size], unsigned a_rows, unsigned a_columns,
              const int b[max_size][max_size], unsigned b_columns,
              int res[max_size][max_size])
{
    for (unsigned i{0}; i < a_rows; ++i)
    {
        for (unsigned j{0}; j < b_columns; ++j)
        {
            res[i][j] = 0;
            for(unsigned k{0}; k < a_columns; ++k){
               res[i][j] += a[i][k] * b[k][j];
            }
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
    const int am[][max_size]{
        {1, 2, 3},
        {4, 5, 6},
    };

    const int bm[][max_size]{
        {7, 8},
        {9, 10},
        {11, 12}};

    int resm[max_size][max_size]{};

    multiply(am, 2, 3, bm, 2, resm);

    print(resm, 2, 2);

    /*
58 64
139 154
*/

    return 0;
}