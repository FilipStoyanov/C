#include <iostream>
char **allocate_matrix(int height, int width)
{
    char **matrix = new char *[height];
    for (unsigned i{0}; i < height; ++i)
    {
        matrix[i] = new char[width];
    }
    return matrix;
}
void deallocate_matrix(char **table, int height)
{
    for (int i{0}; i < height; ++i)
    {
        delete[] table[i];
    }
    delete[] table;
}
bool is_valid_symbol(char c){
    if(c == 'L' || c == 'R' || c == 'U' || c == 'D'){
        return true;
    }
    return false;
}
void enter_matrix(char **&desk, int height, int width)
{
    for (unsigned i{0}; i < height; ++i)
    {
        for (unsigned j{0}; j < width; ++j)
        {
            std::cin >> desk[i][j];
        }
    }
}
void print_matrix(char **&desk, int height, int width)
{
    for (unsigned i{0}; i < height; ++i)
    {
        for (unsigned j{0}; j < width; ++j)
        {
            std::cout << desk[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
bool is_valid(char**& desk, int N, int M){  
  for(unsigned i{0}; i < N; ++i){
    for(unsigned j{0}; j < M; ++j){
        if(!is_valid_symbol(desk[i][j])){
            return false;
        }
    }
  }
  return true;
}
int path_length(char** desk, int start_row, int start_col, int N, int M){
    int length{0};
    int curr_i{start_row};
    int curr_j{start_col};
    char** desk_copy = allocate_matrix(N,M);
    for(unsigned i{0}; i < N; ++i){
        for(unsigned j{0}; j < M; ++j){
            desk_copy[i][j] = desk[i][j];
        }
    }
    while(curr_i >= 0 && curr_j >= 0 && curr_i < N && curr_j < M && desk_copy[curr_i][curr_j] != 'v'){
        if(desk_copy[curr_i][curr_j] == 'L'){
            desk_copy[curr_i][curr_j] = 'v';
            --curr_j;
        }
        if(desk_copy[curr_i][curr_j] == 'R'){
            desk_copy[curr_i][curr_j] = 'v';
            ++curr_j;
        }
        if(desk_copy[curr_i][curr_j] == 'D'){
            desk_copy[curr_i][curr_j] = 'v';
            ++curr_i;
        }
        if(desk_copy[curr_i][curr_j] == 'U'){
            desk_copy[curr_i][curr_j] = 'v';
            --curr_i;
        }
        ++length;
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
    char **desk = allocate_matrix(N, M);
    bool valid_input{true};
    do{
     enter_matrix(desk, N, M);
     valid_input = is_valid(desk, N, M);
     if(!valid_input){
         std::cout << "Invalid input! You should enter only letter R,L,U or D.Try again!"<< std::endl;
     }
    }while(!valid_input);
    unsigned curr_path_length{0};
    unsigned max_path_length{0};
    int start_row, start_column;
    char curr_symbol;
    for(unsigned i{0}; i < N; ++i){
        for(unsigned j{0}; j < M; ++j){
            curr_path_length = path_length(desk,i,j, N, M);
            std::cout<<curr_path_length << std::endl;
            if(curr_path_length > max_path_length){
                max_path_length = curr_path_length;
                start_row = i;
                start_column = j;
            }
        }
    }
    deallocate_matrix(desk, N);
    std::cout << "Start position: "<< "(" << start_row << ", " << start_column <<")"<<std::endl;
}
using namespace std;
int main()
{ 
    int N,M;
    task2(N,M);

    return 0;
}