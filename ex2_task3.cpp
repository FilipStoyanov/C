#include<iostream>
using namespace std;
int main (){
double x1,y1;
cin>>x1>>y1;
const double eps=0.000001;
const double Y = 24-4*x1;
const double delta = y1-Y;
delta > eps ? std::cout<< "above" : std::cout<<"not above";
  return 0;
}