#include <iostream>
#include <cstring>
using namespace std;
bool checkForWord(char *&word)
{
    if (word[0] == '\n')
    {
        return true;
    }
    return false;
}
int main()
{
    unsigned N;
    std::cout << "N: ";
    std::cin >> N;
    char *word = new char[256];
    for (unsigned i{0}; i < N; ++i)
    {
        std::cin.getline(word, 256);
        std::cout << std::boolalpha << checkForWord(word) << std::endl;
    }
    delete[] word;

    return 0;
}