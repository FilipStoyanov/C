#include<iostream>
#include<cmath>
using namespace std;
double cos3(double x, double eps){
    double curr_element{pow(-1,1)*((pow(3,2) + 3)/2)*pow(x,2)};
    double save{curr_element};
    double factoriel{1};
    double sum{curr_element};
    unsigned k{2};
    double fact{2};
    bool flag{false};
    while(!flag){
      fact = fact*(2*k-1)*(2*k);
      curr_element=pow(-1,k)*((pow(3,2*k) + 3)/fact)*pow(x,2*k);
      flag={fabs(curr_element-save) <= eps};
      sum+=curr_element;
      save=curr_element;
      ++k;
    }
    return sum/4;
}
int main (){
   double x,eps;
   std::cin>>x>>eps;
   std::cout<<cos3(x,eps)<<std::endl;



    return 0;
}