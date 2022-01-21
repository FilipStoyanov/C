#include <iostream>
#include <cstring>
using namespace std;
unsigned longestSequence(char *s)
{
    unsigned max_size{0};
    unsigned size=strlen(s);
    unsigned curr_size;
    while(*s != '\0')
    {
        char curr_symbol{*s};
        curr_size = 0;
        while (*s != '\0' && *s == curr_symbol)
        {
            ++curr_size;
            ++s;
        }
        if (curr_size > max_size)
        {
            max_size = curr_size;
        }
    }
    return max_size;
}
int main()
{
    char* s = new char[100];
    std:: cin.getline(s,100);
    std::cout << longestSequence(s) << std::endl;
    delete []s;
    return 0;
}