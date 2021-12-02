#include <iostream>
#include <cstring>
using namespace std;
unsigned my_strlen(const char word[])
{
    unsigned len{0};
    while (word[len] != '\0')
    {
        ++len;
    }
    return len;
}

int my_strcmp(const char lsh[], const char rsh[])
{
    unsigned i{0};
    while (lsh[i] == rsh[i] && lsh[i] && rsh[i])
    {
        ++i;
    }
    return lsh[i] - rsh[i];
}
void my_strcpy(char dest[], const char source[])
{
    unsigned i{0};
    while (source[i])
    {
        dest[i] = source[i];
        ++i;
    }
    dest[i] = '\0';
    std::cout << dest;
}
void my_strcat(char dest[], const char source[])
{
    unsigned i{my_strlen(dest)};
    unsigned j{0};
    while (source[j])
    {
        dest[i] = source[j];
        ++i;
        ++j;
    }
    dest[i] = '\0';
}
int my_strchr(const char str[], char symbol)
{
    unsigned i{0};
    while (str[i])
    {
        if (str[i] == symbol)
        {
            return i;
        }
        ++i;
    }
    return -1;
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}
int my_atoi(char str[])
{
    unsigned i{0};
    unsigned number;
    unsigned count_digits{0};
    int digit;
    unsigned result{0};
    bool is_negative{false};
    if (str[i] == '-')
    {
        ++i;
        is_negative = true;
    }
    while (str[i] && is_digit(str[i]))
    {
        digit = {str[i] - '0'};
        result = result * 10 + digit;
        ++i;
    }
    return is_negative ? -result : result;
}
void run_length_encode(char destination[], char source[])
{
    unsigned size1 = my_strlen(source);
    unsigned counter{1};
    unsigned j{0};
    for (unsigned input{0}; input < size1 - 1; ++input)
    {
        if (source[input] == source[input + 1])
        {
            ++counter;
        }
        else
        {
            if (counter > 1)
            {
                destination[j] = char(counter + '0');
                ++j;
            }
            destination[j] = source[input];
            counter = 1;
            ++j;
        }
    }
    destination[j] = '\0';
}





void reverse_words(char sentence[])
{
    int i{0};
    unsigned begin_word;
    size_t size{strlen(sentence)};
    while (sentence[i])
    {
        if (sentence[i] == ' ')
        {
            ++i;
        }
        begin_word = i;
        while (sentence[i] != ' ' && sentence[i])
        {
            ++i;
        }
        for (unsigned word_counter{0}; word_counter < (i - begin_word) / 2 && sentence[i - word_counter - 1]; ++word_counter)
        {
            std::swap(sentence[begin_word + word_counter], sentence[i - word_counter - 1]);
        }
    }
    std::cout << sentence << std::endl;
}
void run_length_decode(char decode_sentence[], const char sentence[])
{
    unsigned i{0};
    unsigned number{0};
    unsigned decode_counter{0};
    while (sentence[i])
    {
        number = 0;
        while (is_digit(sentence[i]) && sentence[i])
        {
            number = number * 10 + (sentence[i] - '0');
            ++i;
            std::cout << number << std::endl;
        }
        if (number)
        {
            for (unsigned j{0}; j < number; ++j)
            {
                decode_sentence[decode_counter] = sentence[i];
                ++decode_counter;
            }
        }
        else
        {
            decode_sentence[decode_counter] = sentence[i];
            ++decode_counter;
        }
        ++i;
    }
    decode_sentence[decode_counter] = '\0';
    std::cout << decode_sentence;
}
int my_strstr(const char str[], const char target[])
{
    unsigned i{0};
    unsigned j;
    size_t target_size{strlen(target)};
    while (str[i])
    {
        j = i;
        while (str[j] == target[j - i] && str[j] && target[j - i])
        {
            ++j;
        }
        if ((j - i) == target_size)
        {
            return i;
        }
        ++i;
    }
    return -1;
}
void cut_str(const char source[], unsigned from, char result[])
{
    unsigned res_counter{0};
    size_t source_size{strlen(source)};
    for (unsigned j{from}; j < source_size; ++j)
    {
        result[res_counter] = source[j];
        ++res_counter;
    }
    result[res_counter] = '\0';
    std::cout << result << std::endl;
}
int main()
{
    char str1[101];
    std::cin.getline(str1, 100);
    char str2[101];
    std::cin.getline(str2, 101);
    char str3[101];
    cut_str(str1, my_strstr(str1, str2), str3);
    // run_length_decode(str2, str1);
    // char c;
    // std::cin >> c;
    // char str2[101];
    // std::cin.getline(str2,100);
    // my_strcat(str1,str2);
    // std::cout << my_atoi(str1) << std::endl;
    // run_length_encode(str2,str1);
    // reverse_words(str1);

    return 0;
}