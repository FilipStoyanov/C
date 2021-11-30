#include<iostream>
#include<cmath>
using namespace std;
unsigned furthest_away(unsigned n){
    double x,y,distance;
    double max_distance{0};
    unsigned index{0};
    const double eps{0.0000001};
    for(unsigned i{0};i<n;++i){
        std::cin>>x>>y;
        distance = x*x + y*y;
       if( distance-max_distance > eps){
           max_distance=distance;
           index=i;
       }
    }
    return index;
}
int main (){
    unsigned n;
    std::cin>>n;
    std::cout<<furthest_away(n)<<std::endl;


    return 0;
}