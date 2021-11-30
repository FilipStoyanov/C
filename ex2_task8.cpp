#include<iostream>
using namespace std;
int main () {
    int day,month,year;
    std::cin>>day>>month>>year;
    bool checkForDay = false;
    const bool isLongMonth = month == 1  || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12;
    const bool isValidDay = day > 0 && day <= 31;
    const bool isValidMonth = month > 0 && month < 12;
    const bool isValidYear = year >0;
    const bool isLeapYear = (year % 4 == 0 && year % 100 != 0 ) || (year%400 == 0);
    if( isLongMonth && isValidDay){
        checkForDay = true;
    }
    if(!isLongMonth && month !=2 && day>0 && day < 31){
       checkForDay = true;
    }else if (month == 2 && isLeapYear && day > 0 && day < 30){
         checkForDay = true;
    }else if (month == 2 && !isLeapYear && day > 0 && day < 29){
        checkForDay = true;
    } 
    (checkForDay && isValidMonth && isValidYear) ? std::cout<<"This is a valid date.\n" : std::cout<<"This is not a valid date.\n";
    return 0;
}