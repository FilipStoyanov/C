#include <iostream>
#include <cstring>
using namespace std;
char **allocate_char_matrix(unsigned height, unsigned width)
{
    char **table = new char *[height + 1];
    for (unsigned i{0}; i < height + 1; ++i)
    {
        table[i] = new char[width + 1];
    }
    return table;
}
char *begin_word(char *word, char *sentence)
{
    unsigned length_word = strlen(word);
    unsigned length_sentence = strlen(sentence);
    unsigned reps{0};
    while (*sentence != '\0')
    {
        reps = 0;
        char *begin_pointer = sentence;
        for (unsigned i{0}; i < length_word && word[i] == *sentence; ++i)
        {
            ++reps;
            ++sentence;
        }
        if (reps == length_word)
        {
            return begin_pointer;
        }
        ++sentence;
    }
    return nullptr;
}
void replace_word(char *new_word, char *old_word, char *sentence)
{
    char *beg = begin_word(old_word, sentence);
    if (beg != nullptr)
    {
        //check new word is longer than the old one
        //replace word
    }
}
void autoCorrect(unsigned n, unsigned dictionary_length)
{
    do
    {
        std::cin >> n;
        if (n >= 1024)
        {
            std::cout << "Invalid input! Try again!" << std::endl;
        }
    } while (n >= 1024);
    char *text = new char[1024];
    std::cin.getline(text, n + 2, '\0');
    std::cin.clear();
    do
    {
        std::cin >> dictionary_length;
        if (dictionary_length > 128)
        {
            std::cout << "Invalid input! Dictionary length should be less than 128! Try again!" << std::endl;
        }
    } while (dictionary_length > 128);
    char **dictionary = allocate_char_matrix(dictionary_length, 100);
    for (unsigned i{0}; i <= dictionary_length; ++i)
    {
        std::cin.clear();
        std::cin.getline(dictionary[i], 101);
    }
    char *old_word = new char[99];
    char *new_word = new char[99];
    char *line = new char[100];
    unsigned length_line;
    for (unsigned i{1}; i <= dictionary_length; ++i)
    {
        strcpy(line, dictionary[i]);
        length_line = strlen(line);
        unsigned j{0};
        for (; j < length_line && line[j] != '-'; ++j)
        {
            old_word[j] = line[j];
        }
        old_word[j] = '\0';
        for (unsigned k{j + 1}; k < length_line; ++k)
        {
            new_word[k - j - 1] = line[k];
        }
        new_word[length_line - j - 1] = '\0';
        char *beg = strstr(text, old_word);
        unsigned size_old = strlen(old_word);
        unsigned size_new = strlen(new_word);
        if (beg != nullptr)
        {
            strncpy(beg, new_word, size_new);
        }
    }
    char *edit_text = new char[2048];
    unsigned count_quotation_mark{0};
    unsigned counter{0};
    for (unsigned i{0}; i < n; ++i)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ',' || text[i] == '-')
        {
            edit_text[counter] = text[i];
            ++counter;
            edit_text[counter] = ' ';
        }
        else if (text[i] == '"')
        {
            ++count_quotation_mark;
            if (count_quotation_mark % 2 == 1)
            {
                edit_text[counter] = ' ';
                ++counter;
                edit_text[counter] = text[i];
            }
        }
        else if (text[i] == '"')
        {
            ++count_quotation_mark;
            if (count_quotation_mark % 2 == 1)
            {
                edit_text[counter] = ' ';
                ++counter;
                edit_text[counter] = text[i];
            }
        }
        else if (text[i] == '(' || text[i] == '>' || text[i] == '*' || text[i] == '-' || text[i] == '+' || text[i] == '/')
        {
            edit_text[counter] = ' ';
            ++counter;
            edit_text[counter] = text[i];
        }
        else if (text[n - 1] != '.' || text[n - 1] != '?' || text[n - 1] != '!' || text[n - 1] != '"')
        {
            edit_text[counter] = '.';
        }
        else if (text[i] == '\n')
        {
            char c = edit_text[counter];
            edit_text[counter] = '.';
            ++counter;
            edit_text[counter] = text[i];
        }
        else
        {
            edit_text[counter] = text[i];
        }
        ++counter;
    }
    edit_text[counter] = '\0';
    std::cout << edit_text << std::endl;
    delete[] edit_text;
    delete[] line;
    delete[] old_word;
    delete[] text;
    delete[] dictionary;
}
int main()
{
    unsigned text_length, dictionary_length;
    autoCorrect(text_length, dictionary_length);
    //    char* str = new char[100];
    //    std::cin>>str;
    //    char* sentence = new char[100];
    //    std::cin>>sentence;
    return 0;
}