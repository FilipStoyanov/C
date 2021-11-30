#include<iostream>
#include<cmath>
using namespace std;
int main (){
    double x1,y1,x2,y2,radius;
    const double eps=0.000000001;
    std::cout<< "Enter center coordinates:";
    std::cin>>x1>>y1;
    std::cout<<"Enter point coordinates";
    std::cin>>x2>>y2;
    std::cout<<"Enter circle radius";
    std::cin>>radius;
    const double PI=3.14;
    double distance=sqrt(fabs(x2-x1)*fabs(x2-x1) + fabs(y2-y1)*fabs(y2-y1));
    const double delta=fabs(distance-radius);
    bool isInside = delta <= eps ? true : false;
    std::cout<<isInside<<std::endl;
    return 0;
}