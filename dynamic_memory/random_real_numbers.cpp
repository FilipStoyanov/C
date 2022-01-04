#include<iostream>
#include<random>
using namespace std;
int main (){

   std::random_device rd;
   std::mt19937 gen(rd());
   std::cout<<std::uniform_real_distribution<>(0, 1)(gen);

    return 0;
}