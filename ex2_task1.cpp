#include<iostream>
#include<cmath>
using namespace std;
int main (){
    int x1;
    int y1;
    int x2;
    int y2;
    std::cin>>x1>>y1;
    std::cin>>x2>>y2;

    const bool clashing_horses{
        (fabs(x1-x2)==2 && fabs(y1-y2)==1) ||
        (fabs(x1-x2)==1 && fabs(y1-y2)==2)
    };
    std:: cout<<std::boolalpha<<clashing_horses<<std::endl;

    return 0;
}