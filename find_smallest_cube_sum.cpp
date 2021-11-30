#include<iostream>
#include<cmath>
using namespace std;
bool sum_of_2_cubes(unsigned n, unsigned k){
    for(unsigned a{1};a<cbrt(n); ++a){
        if(a*a*a + (a+k)*(a+k)*(a+k) == n){
            return true;
        }
    }
    return false;
}
unsigned find_smallest_cube_sum(unsigned p, unsigned k){
   bool is_find{false};
   unsigned number{p};
   while(!is_find){
      ++number;
      if(sum_of_2_cubes(number,k)){
          is_find = true;
      }
   }
    return number;
}
int main (){
   unsigned p,k;
   std::cin>>p>>k;
   std::cout<<find_smallest_cube_sum(p,k)<<std::endl;

    return 0;
}