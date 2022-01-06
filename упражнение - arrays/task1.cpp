#include <iostream>
using namespace std;
void allocate_matrix(int**& matrix, int height, int width)
{
    matrix = new int*[height];
    for (int i{0}; i < height; ++i)
    {
        matrix[i] = new int[width];
    }
}
void enter_matrix(int**& matrix, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}
void print_matrix(int**& matrix, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void deallocate_matrix(int**& matrix, int height)
{
    for (int i{0}; i < height; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void copy_matrix(int**& matrix, int**& source, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            matrix[i][j] = source[i][j];
        }
    }
}
void transformMatrix(int**& A, int**& B, int N1, int M1, int N2, int M2)
{
    if (N2 < N1 || M2 < M1)
    {
        int** A1 = new int*[N1];
        allocate_matrix(A1, N1, M1);
        copy_matrix(A1, A, N1, M1);
        deallocate_matrix(A, N1);
        if (N2 < N1)
        {
            N1 = N2;
        }
        if (M2 < M1)
        {
            M1 = M2;
        }
        allocate_matrix(A, N1, M1);
        copy_matrix(A, A1, N1, M1);
        deallocate_matrix(A1, N1);
    }
    for (int i{0}; i < N1; ++i)
    {
        for (int j{0}; j < M1; ++j)
        {
            if (A[i][j] <= B[i][j])
            {
                A[i][j] = B[i][j];
            }
            else
            {
                A[i][j] *= -1;
            }
        }
    }
    print_matrix(A, N1, M1);
    deallocate_matrix(A, N1);
    deallocate_matrix(B, N2);
}
void task1_demo(){
    int N1, M1, N2, M2;
    std::cout << "N1:";
    std::cin >> N1;
    std::cout << "M1:";
    std::cin >> M1;
    std::cout << "N2:";
    std::cin >> N2;
    std::cout << "M2:";
    std::cin >> M2;
    int** A;
    int** B;
    std::cout<< "A: " << std::endl;
    allocate_matrix(A, N1, M1);
    enter_matrix(A, N1, M1);
    std::cout<< "B: " << std::endl;
    allocate_matrix(B, N2, M2);
    enter_matrix(B, N2, M2);
    std::cout<<std::endl;
    transformMatrix(A, B, N1, M1, N2, M2);
}
int main()
{
    task1_demo();
   
    return 0;
}