#include <iostream>
using namespace std;
#define MAX 4

bool reachable(int matrix[][MAX], int N, int sx, int sy, int limit)
{
    std::cout <<"x= " << sx << "y= "<<sy<< std::endl;
    if (sx < 0 || sy < 0 || sx == N || sy == N || matrix[sx][sy] > limit)
    {
        return false;
    }
    if (matrix[sx][sy] == limit)
    {
        return true;
    }
    if (reachable(matrix, N, sx + 1, sy, limit))
        return true; //DOWN
    if (reachable(matrix, N, sx, sy + 1, limit))
        return true; //RIGHT
    return false;
}
void allocate_matrix(int **&matrix, int N)
{
    matrix = new int *[N];
    for (unsigned i{0}; i < N; ++i)
    {
        matrix[i] = new int[N];
    }
}
void deallocate_matrix(int **&matrix, int N)
{
    for (unsigned i{0}; i < N; ++i)
    {
        delete matrix[i];
    }
    delete[] matrix;
}
void enter_matrix(int **&matrix, int N)
{
    for (unsigned i{0}; i < N; ++i)
    {
        for (unsigned j{0}; j < N; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}
int main()
{
    // int **matrix;
    // unsigned n;
    // std::cin >> n;
    // allocate_matrix(matrix, n);
    // enter_matrix(matrix, n);
    // deallocate_matrix(matrix, n);
    int matrix[4][MAX] = {
        1, 10, 0, 0,
        4, 10, 0, 0,
        2, 0, 3, 3,
        4, 10, 0, 5
    };
    int startX = 3;
    int startY = 3;
        std::cout<< std::boolalpha << reachable(matrix, 4, 0, 0, 3) << std::endl;
    return 0;
}