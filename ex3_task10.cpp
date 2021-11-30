#include<iostream>
using namespace std;
int main (){
    unsigned n;
    std::cin>>n;
    unsigned f1=0;
    unsigned f2=1;
    unsigned f3=1;
    for(unsigned i=1;i<n;++i){
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
    }
     n==0 ? std::cout<<f1 : std::cout<<f3<<std::endl;
    return 0;
}