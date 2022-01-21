#include <iostream>
#include <cstring>
#define ROW 3
#define COL 3
using namespace std;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
bool isValid(int row, int col)
{
    return (row >= 0 && row < ROW) && (col >= 0 && col < COL);
}
bool DFS(char C[3][3], int startX, int startY, char *word, int index)
{
    if (index == strlen(word))
    {
        return true;
    }
    if (!isValid(startX, startY))
    {
        return false;
    }
    if (C[startX][startY] == word[index])
    {
        char temp = C[startX][startY];
        C[startX][startY] = '#';
        bool res = DFS(C, startX - 1, startY, word, index + 1) ||
                   DFS(C, startX + 1, startY, word, index + 1) ||
                   DFS(C, startX, startY - 1, word, index + 1) ||
                   DFS(C, startX, startY + 1, word, index + 1);
        C[startX][startY] = temp;
        return res;
    }
    else
    {
        return false;
    }
}
bool crossword(char C[3][3], char *words[], unsigned n)
{
    bool flag = true;
    unsigned counter{0};
    for (unsigned i{0}; i < n; ++i)
    {
        flag = true;
        for (unsigned j{0}; j < 3 && flag; ++j)
        {
            for (unsigned k{0}; k < 3 && flag; ++k)
            {
                if (C[j][k] == words[i][0])
                {
                    if (DFS(C, j, k, words[i], 0) == true)
                    {
                        flag = false;
                        ++counter;
                    }
                }
            }
        }
    }
    if (counter == n)
    {
        return true;
    }
    return false;
}
int main()
{
    char c[3][3] = {
        'c', 'a', 't',
        'w', 'h', 'o',
        'w', 'i', 'n'};
    char* word[] = {
        "cat",
        "hot",
        "chat"
    };
    std::cout << std::boolalpha << crossword(c, word, 3) << std::endl;

    return 0;
}