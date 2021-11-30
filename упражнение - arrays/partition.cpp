#include <iostream>
using namespace std;
unsigned partition(int arr[], unsigned begin, unsigned end, int pivot)
{
    unsigned index_of_first_bigger;
    for (unsigned i{begin}; i < end - 1; ++i)   //reorder the range
      {
        if (arr[i] > pivot)
        {
            for (unsigned j{i + 1}; j < end; ++j)
            {
                if (arr[j] <= pivot)
                {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }
    for(unsigned i{begin}; i<end; ++i){   //find first element bigger than pivot
        if(arr[i] > pivot){
            index_of_first_bigger=i;
            break;
        }
    }
    return index_of_first_bigger;
}
int main()
{
    int arr[]{4, 0, 2, 1, 5};    //0 2 1 4 5
    std::cout << partition(arr, 0, 5, 3);

    return 0;
}