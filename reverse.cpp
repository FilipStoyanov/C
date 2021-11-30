#include<iostream>
#include<utility>
using namespace std;
void  print(int arr[], unsigned begin, unsigned end){
    for(unsigned i{begin};i<end;++i){
        std::cout<<arr[i]<<" ";
    }
}
void reverse(int arr[], unsigned begin, unsigned end){
    for(unsigned i{end};i>=begin;--i){
        std::cout<<arr[i]<<" ";
    }
}
unsigned copy(const int input_arr[], unsigned input_begin, unsigned input_end,
              int output_arr[], unsigned output_begin)
    {
                 unsigned currIndex = output_begin;
                 for(unsigned i{input_begin};i<input_end;++i){
                     output_arr[currIndex] = input_arr[i];
                     ++currIndex;
                 }
      return output_begin;
    }
void rotate(int arr[], unsigned begin, unsigned mid, unsigned end){
   for(unsigned i{begin};i<end/2;++i){
       if(i<=mid){
           swap(arr[i],arr[end-i-1]);
       }
   }
}
int main (){

 
    return 0;
}