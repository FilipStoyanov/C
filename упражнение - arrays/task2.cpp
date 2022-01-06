#include <iostream>
void allocate_matrix(char **matrix, int height, int width)
{
    matrix = new char*[height];
    for (int i{0}; i < height; ++i)
    {
        matrix[i] = new char[width];
    }
}
void deallocate_matrix(char **table, int height)
{
    for (int i{0}; i < height; ++i)
    {
        delete[] table[i];
    }
    delete[] table;
}
bool is_valid_symbol(char c)
{
    if (c == 'L' || c == 'R' || c == 'U' || c == 'D')
    {
        return true;
    }
    return false;
}
void enter_matrix(char **desk, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            std::cin >> desk[i][j];
        }
    }
}
bool is_valid(char **desk, int N, int M)
{
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            if (!is_valid_symbol(desk[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}
int path_length(char **desk, int start_row, int start_col, int N, int M)
{
    int curr_i{start_row};
    int curr_j{start_col};
    char **desk_copy = new char *[N];
    allocate_matrix(desk_copy, N, M);
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            desk_copy[i][j] = desk[i][j];
        }
    }
    int length{0};
    while (curr_i >= 0 && curr_j >= 0 && curr_i < N && curr_j < M && desk_copy[curr_i][curr_j] && desk_copy[curr_i][curr_j] != 'v')
    {
        switch (desk_copy[curr_i][curr_j])
        {
        case 'L':
        {
            desk_copy[curr_i][curr_j] = 'v';
            --curr_j;
            ++length;
            break;
        }
        case 'R':
        {
            desk_copy[curr_i][curr_j] = 'v';
            ++curr_j;
            ++length;
            break;
        }
        case 'U':
        {
            desk_copy[curr_i][curr_j] = 'v';
            --curr_i;
            ++length;
            break;
        }
        case 'D':
        {
            desk_copy[curr_i][curr_j] = 'v';
            ++curr_i;
            ++length;
            break;
        }
        }
    }
    deallocate_matrix(desk_copy, N);
    return length;
}
void task2(int N, int M)
{
    std::cout << "N:";
    std::cin >> N;
    std::cout << "M:";
    std::cin >> M;
    char **desk = new char *[N];
    allocate_matrix(desk, N, M);
    bool valid_input{true};
    do
    {
        enter_matrix(desk, N, M);
        valid_input = is_valid(desk, N, M);
        if (!valid_input)
        {
            std::cout << "Invalid input! You should enter only letter R,L,U or D.Try again!" << std::endl;
        }
    } while (!valid_input);
    int curr_path_length{0};
    int max_path_length{0};
    int start_row, start_column;
    char curr_symbol;
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            curr_path_length = path_length(desk, i, j, N, M);
            if (curr_path_length > max_path_length)
            {
                max_path_length = curr_path_length;
                start_row = i;
                start_column = j;
            }
        }
    }
    deallocate_matrix(desk, N);
    std::cout << start_row << " " << start_column << std::endl;
}
using namespace std;
int main()
{
    int N, M;
    task2(N, M);
    return 0;
}