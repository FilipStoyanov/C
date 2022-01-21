#include <iostream>
#include <cstring>
bool has_symbol(char *str, char symbol)
{
    while (*str != '\0')
    {
        if (*str == symbol)
        {
            return true;
        }
        ++str;
    }
    return false;
}
void encode(const char *s1, const char *r1, const char *s2, char *r2)
{
    char alphabet[28] = {0};
    size_t len_s1 = strlen(s1);
    int ind_alphabet;
    if (strlen(s1) != strlen(r1))
    {
        std::cout << "Invalid input" << std::endl;
    }
    bool has_encode{true};
    for (unsigned i = 0; i < len_s1; ++i)
    {
        if (s1[i] == ' ')
        {
            ind_alphabet = 27;
        }
        else
        {
            ind_alphabet = s1[i] - 'a';
        }
        if (alphabet[ind_alphabet] != 0 && alphabet[ind_alphabet] != r1[i])
        {
            std::cout << "Invalid encoding!" << std::endl;
            has_encode = false;
            break;
        }
        else
        {
            alphabet[ind_alphabet] = r1[i];
        }
    }
    size_t length_s2 = strlen(s2);
    if (!has_encode)
    {
        std::cout << r2;
        return;
    }
    int ind;
    unsigned counter{0};
    for (unsigned i{0}; i < length_s2; ++i)
    {
        if (s2[i] == ' ')
        {
            ind = 27;
        }
        else
        {
            ind = s2[i] - 'a';
        }
        if (alphabet[ind] != 0)
        {
            r2[counter] = alphabet[ind];
        }
        else
        {
            r2[counter] = s2[i];
        }
        ++counter;
    }
    r2[counter] = '\0';
    std::cout << r2 << std::endl;
}
using namespace std;

int main()
{
    char result[20];
    encode("hello", "worrd", "love", result);

    return 0;
}