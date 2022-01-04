#include <iostream>
using namespace std;
void iota(int *begin, int *end, int value)
{
   while(begin != end){
       *begin = value;
       ++value;
       ++begin;
   }
}
int main()
{
    int range[10]{};
    iota(std::begin(range), std::end(range), 0);

    for (int num : range)
    {
        std::cout << num << ' ';
    }

    // 0 1 2 3 4 5 6 7 8 9

    return 0;
}