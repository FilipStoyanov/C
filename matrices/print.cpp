#include<iostream>
using namespace std;
const unsigned max_size{100};
void print(const int arr[][max_size], unsigned rows, unsigned columns){
    for(unsigned i{0}; i < rows; ++i){
        for(unsigned j{0}; j < rows; ++j){
            std::cout<<arr[i][j]<< " ";
        }
        std::cout<<std::endl;
    }
}
int main (){
    const int arr [][max_size]{
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
    };
    print(arr,3,max_size);


    return 0;
}