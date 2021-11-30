#include<iostream>
using namespace std;
bool strictly_increasing(unsigned n){
    if(n < 1 ) return false;
    double number;
    std::cin>>number;
    double last_number{number};
    for(unsigned i{1};i<n;++i){
       std::cin>>number;
       if(number<=last_number){
           return false;
       }
       last_number = number;
    }
    return true;
}
int main(){
    unsigned n;
    std::cin>>n;
    std::cout<<strictly_increasing(n);



    return 0;
}