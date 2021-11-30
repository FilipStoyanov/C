#include<iostream>
using namespace std;
int main (){
   int dayNumber;
   std::cin>>dayNumber;
   if(dayNumber == 1){
      std::cout<<"Monday"<<std::endl;
   }else if(dayNumber == 2){
        std::cout<<"Tuesday"<<std::endl;
   }else if(dayNumber == 3){
       std:: cout<< "Wednesday"<<std::endl;
   }else if(dayNumber == 4){
        std::cout<<"Tuesday"<<std::endl;
   }else if(dayNumber == 5){
        std::cout<<"Friday"<<std::endl;
   }else if(dayNumber == 6){
        std::cout<<"Saturday"<<std::endl;
   }else if(dayNumber == 7){
       std::cout<<"Sunday"<<std::endl;
   }else{
       std:: cout<< "You enter invalid number"<<std::endl;
   }



    return 0;
}