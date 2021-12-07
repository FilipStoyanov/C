#include<iostream>
#include<cstring>
unsigned my_strstr(const char source[],const char target[]){
    unsigned i{0};
    unsigned size_source = strlen(source);
    unsigned size_target = strlen(target);
    while(source[i]){
        unsigned j{i};
        while(source[j] == target[j-i] && target[j-i]){
           ++j;
        }
        if( (j-i) == size_target){
            return i;
        }
        ++i;
    }
    return size_source;
}
using namespace std;
int main (){
    char str1[101];
    cin.getline(str1,100);
    char str2[101];
    cin.getline(str2,100);
    unsigned begin{my_strstr(str1,str2)};
    char source[101];
    size_t size1{strlen(str1)};
    for(unsigned i{begin}; i<size1; ++i){
      std::cout<<str1[i]; // try to make this with iterators
    }


    return 0;
}