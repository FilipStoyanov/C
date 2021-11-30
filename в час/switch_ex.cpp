#include<iostream>
using namespace std;
int main (){
    int x{2};
    switch(x){
        case 1: {
            std::cout<<"one\n";
            break;
        }
        case 2: {
            std::cout<<"two\n";
            break;
        }
        case 3: {
            std::cout<<"three\n";
            break;
        }
        default: std::cout<<"idk\n";

    }
    return 0;
}