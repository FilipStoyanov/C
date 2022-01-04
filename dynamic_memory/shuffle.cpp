#include <iostream>
#include <random>
#include <iterator>
using namespace std;
void iota(int *begin, int *end, int value)
{
    while (begin != end)
    {
        *begin = value;
        ++value;
        ++begin;
    }
}
int random_index(const int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    int res = std::uniform_int_distribution<>(0, end)(gen);
    return res;
}
void print(int *begin, int *end)
{
    while (begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}
void shuffle(int *begin, int *end)
{
    const int end_arr = end - begin;
    const int size_arr = end - begin;
    int* new_start{end};
    --new_start;
    int* new_end{begin};
    int rand_ind;
    int end_index = end - begin - 1;
    while( end_index > size_arr / 2){
          --end_index;
          rand_ind = random_index(end_index);
          std::swap(*new_start, *(begin + rand_ind));
         --new_start;
    }
}
int main()
{
    int arr[10]{};
    iota(std::begin(arr), std::end(arr), 0);
    shuffle(std::begin(arr), std::end(arr));
    print(std::begin(arr), std::end(arr));
    return 0;
}