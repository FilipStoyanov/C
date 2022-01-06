#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void allocate_char_matrix(char **&table, unsigned height, unsigned width)
{
    table = new char *[height + 1];
    for (unsigned i{0}; i < height + 1; ++i)
    {
        table[i] = new char[width + 1];
    }
}
void deallocate_char_matrix(char **&table, unsigned height)
{
    for (unsigned i{0}; i < height; ++i)
    {
        delete[] table[i];
    }
    delete[] table;
}
bool is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}
bool is_punctuation_mark(char c)
{
    if (c == '.' || c == '?' || c == '!')
    {
        return true;
    }
    return false;
}
bool is_arithmetic_operation(char c)
{
    if (c != '-' && c != '+' && c != '*' && c != '>' && c != '<' && c != '/')
    {
        return false;
    }
    return true;
}
int begin_word(char *&word, char *&sentence)
{
    unsigned length_word = strlen(word);
    unsigned length_sentence = strlen(sentence);
    unsigned reps{0};
    int counter{0};
    while (counter < length_sentence)
    {
        reps = 0;
        int begin_counter = counter;
        char *prev_symbol = sentence;
        --prev_symbol;
        if (!is_letter(*prev_symbol))
        {
            for (unsigned i{0}; i < length_word && word[i] == *(sentence + counter); ++i)
            {
                ++reps;
                ++counter;
            }
        }
        if (reps == length_word && !is_letter(*(sentence + counter)))
        {
            return begin_counter;
        }
        ++counter;
    }
    return -1;
}
void replace_words(char *&old_word, char *&new_word, int pos, char *&sentence)
{
    int sentence_length = strlen(sentence);
    int length_old_word = strlen(old_word);
    int length_new_word = strlen(new_word);
    int number_symbols = length_new_word - length_old_word;
    int diff_index;
    char *copy_sentence = new char[1024];
    strcpy(copy_sentence, sentence);
    sentence_length += number_symbols;
    for (int i{pos + length_new_word}; i < sentence_length; ++i)
    {
        sentence[i] = copy_sentence[i - number_symbols];
    }
    int j{pos};
    sentence[sentence_length] = '\0';
    for (int i{0}; i < length_new_word; ++i)
    {
        sentence[j + i] = new_word[i];
    }
    delete[] copy_sentence;
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
    char **dictionary;
    allocate_char_matrix(dictionary, dictionary_length, 100);
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
        int pos{-1};
        do
        {
            pos = begin_word(old_word, text);
            if (pos > -1)
            {
                replace_words(old_word, new_word, pos, text);
            }
        } while (pos != -1);
    }
    char *edit_text = new char[2048];
    unsigned count_quotation_mark{0};
    unsigned counter{0};
    unsigned text_length = strlen(text);
    for (unsigned i{0}; i < text_length; ++i)
    {
        if ((is_punctuation_mark(text[i]) || text[i] == ',' || is_arithmetic_operation(text[i])) && text[i + 1] != ' ')
        {
            edit_text[counter] = text[i];
            ++counter;
            edit_text[counter] = ' ';
            ++counter;
        }
        else if (text[i] == '"')
        {
            ++count_quotation_mark;
            edit_text[counter] = '"';
            ++counter;
        }
        else if (text[i] != ' ' && !is_punctuation_mark(text[i]) && text[i] != ',' && !is_arithmetic_operation(text[i]) && count_quotation_mark % 2 == 0 && text[i + 1] == '"')
        {
            edit_text[counter] = ' ';
            ++counter;
            edit_text[counter] = '"';
            ++counter;
        }
        else if (text[i] != ' ' && (text[i + 1] == '(' || is_arithmetic_operation(text[i + 1])))
        {
            edit_text[counter] = ' ';
            ++counter;
            edit_text[counter] = text[i + 1];
            ++counter;
        }
        else if ((!is_punctuation_mark(text[i]) && text[i + 1] == '"' && count_quotation_mark % 2 == 1) || (!is_punctuation_mark(text[i]) && (text[i + 1] == '\n' || text[i + 1] == '\0')))
        {
            edit_text[counter] = text[i];
            ++counter;
            edit_text[counter] = '.';
            ++counter;
        }
        else
        {
            edit_text[counter] = text[i];
            ++counter;
        }
    }
    edit_text[counter] = '\0';
    std::cout << edit_text << std::endl;
    delete[] edit_text;
    delete[] line;
    delete[] old_word;
    delete[] new_word;
    delete[] text;
    deallocate_char_matrix(dictionary, dictionary_length);
}
int main()
{
    unsigned text_length, dictionary_length;
    autoCorrect(text_length, dictionary_length);
    return 0;
    //need to change symbol rules code
}