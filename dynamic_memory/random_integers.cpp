#include<random>
#include<iostream>
int main (){
 std::random_device rd;
 std::mt19937 gen(rd());

 std::cout<<std::uniform_int_distribution<>(0,10)(gen);
 std::cout<<std::uniform_int_distribution<unsigned>(0,10)(gen);

return 0;
}