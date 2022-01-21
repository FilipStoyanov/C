#include <iostream>
#include <cstring>
using namespace std;

int x[4] = {-1, 1, 0, 0}; // UP DOWN LEFT RIGHT
int y[4] = {0, 0, -1, 1}; // MOVING IN MATRIX COULD BE REPRESENT BY TWO ARRAYS
bool read_word(const char c[][3], const char *word, unsigned startX, unsigned startY)
{
    size_t word_len = strlen(word);
    if (c[startX][startY] != word[0])
    {
        return false;
    }
    for (unsigned i{0}; i < 4; ++i)
    {
        int dx = startX + x[i];
        int dy = startY + y[i];
        int j = 1;
        std::cout << "i: " << i << c[dx][dy] << std::endl;
        for (j = 1; j < word_len; ++j)
        {
            if (dx < 0 || dx >= 3 || dy < 0 || dy >= 3)
            {
                break;
            }
            if (c[dx][dy] != word[j])
            {
                break;
            }
            else
            {
                dx += x[i];
                dy += y[i];
            }
        }
        if (j == word_len)
        {
            return true;
        }
    }
    return false;
}
bool crossword(const char(c[3][3]), const char *words[], unsigned n)
{
    unsigned count{0};
    for (unsigned i{0}; i < 3; ++i)
    {
        for (unsigned j{0}; j < 3; ++j)
        {
            for (unsigned k{0}; k < n; ++k)
            {
                if (read_word(c, words[i], i, j))
                {
                    ++count;
                }
            }
        }
    }
    if (count == n)
    {
        return true;
    }
    return false;
}
int main()
{
    const char *sentence[3] = {
        "cat",
        "what",
        "not"};
    const char c[3][3] = {
        'c', 'a', 't',
        'w', 'h', 'o',
        'w', 'i', 'n'};
    const char *w[] = {
        "cat",
        "what",
        "not"};
        std:cout << std::boolalpha << crossword(c,w, 3) << std::endl;

    return 0;
}