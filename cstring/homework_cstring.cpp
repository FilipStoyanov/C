#include<iostream>
#include<cstring>
bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}
void run_length_encode(char destination[], char source[])
{
    unsigned size1 = strlen(source);
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
    // std::cin.getline(str2, 100);
    // std::cout<<my_strstr(str2,str1);
    run_length_decode(str2,str1);
    reverse_words(str1);

    
    

 
    

    return 0;
}