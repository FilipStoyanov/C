#include <iostream>
using namespace std;
unsigned crosswords(char c[9], char *words[10], unsigned n)
{
    bool flag;
    unsigned max_size{0};
    unsigned reps;
    for (unsigned i{0}; i < n; ++i)
    {
        char *word = strcpy(word[i]);
        for (unsigned j{0}; j < 3; ++j)
        {
            for (unsigned k{0}; k < 3; ++k)
            {
                if (c[j][k] == word[0])
                {
                    reps = 0;
                    unsigned curr_j{j};
                    unsigned curr_k{k};
                    unsigned counter{1};
                    flag = true;
                    while (curr_j < 3 && curr_k < 3 && curr_j >= 0 && curr_k >= 0 && flag)
                    {
                        if (c[curr_j + 1][curr_k] == word[counter])
                        {
                            ++curr_j;
                            ++counter;
                        }
                        else if (c[curr_j][curr_k + 1] == word[counter])
                        {
                            ++curr_k;
                            ++counter;
                        }
                        else if (c[curr_j][curr_k - 1] == word[counter])
                        {
                            --curr_k;
                            ++counter;
                        }
                        else if (c[curr_j - 1][curr_k] == word[counter])
                        {
                            --curr_j;
                            ++counter;
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    char c[3][3] = { 'c',
                     'a',
                     't',
                     'w',
                     'h',
                     'o',
                     'w',
                     'i',
                     'n'
    }

    return 0;
}