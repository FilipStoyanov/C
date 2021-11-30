#include<iostream>
using namespace std;
void print(const int arr[], unsigned begin, unsigned end){
    for(unsigned i{begin}; i<end;++i){
        std::cout<<arr[i]<<" ";
    }
}

int main (){
   int arr[]{0,1,2,3};
   print(arr,1,4);


    return 0;
}