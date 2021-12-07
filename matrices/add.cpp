#include <iostream>
using namespace std;
const unsigned max_size{100};
void add(const int a[max_size][max_size], const int b[max_size][max_size], unsigned rows, unsigned columns,
         int res[max_size][max_size])
{
    for (unsigned i{0}; i < rows; ++i)
    {
        for (unsigned j{0}; j < columns; ++j)
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}
void print(const int arr[][max_size], unsigned rows, unsigned columns){
    for(unsigned i{0}; i < rows; ++i){
        for(unsigned j{0}; j < rows; ++j){
            std::cout<<arr[i][j]<< " ";
        }
        std::cout<<std::endl;
    }
}
int main()
{
    const int a[][max_size]{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    const int b[][max_size]{
        {9, 1, 7},
        {6, 5, 4},
        {3, 2, 1}};

    int res[max_size][max_size]{};

    add(a, b, 3, 3, res);

    print(res, 3, 3);

    /*
10 10 10
10 10 10
10 10 10
*/

    return 0;
}