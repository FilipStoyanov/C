#include<iostream>
#include<cmath>
using namespace std;
int main (){
    unsigned n;
    std::cin>>n;
    unsigned copy_n = n;
    if(copy_n%2==0){
        std::cout<<2<<" ";
        copy_n/=2;
    }
    while(copy_n%2 == 0){
        copy_n/=2;
    }
    for(unsigned i{3};i<=sqrt(copy_n);i+=2){
        if(copy_n%i==0){
            std::cout<<i<<" ";
        }
        while(copy_n%i==0){
            copy_n/=i;
        }
    }
    if(copy_n>2){
        std::cout<<copy_n<<std::endl;
    }
    return 0;
}