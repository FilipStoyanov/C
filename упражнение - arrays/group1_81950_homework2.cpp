#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

//TASK 0
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
void autoCorrect(unsigned n, char *&text, unsigned dictionary_length, char **&dictionary)
{

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
        if ((is_punctuation_mark(text[i]) || text[i] == ',' || text[i] == ';' || text[i] == ':' || is_arithmetic_operation(text[i])) && text[i + 1] != ' ')
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
        else if (text[i] != ' ' && !is_punctuation_mark(text[i]) && text[i] != ',' && text[i] != ':' && text[i] != ';' && !is_arithmetic_operation(text[i]) && count_quotation_mark % 2 == 0 && text[i + 1] == '"')
        {
            edit_text[counter] = text[i];
            ++counter;
            edit_text[counter] = ' ';
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
}
void task0()
{
    unsigned n, dictionary_length;
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
    autoCorrect(n, text, dictionary_length, dictionary);
    delete[] text;
    deallocate_char_matrix(dictionary, dictionary_length);
}

//TASK 1
void allocate_matrix(int **&matrix, int height, int width)
{
    matrix = new int *[height];
    for (int i{0}; i < height; ++i)
    {
        matrix[i] = new int[width];
    }
}
void enter_matrix(int **&matrix, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}
void print_matrix(int **&matrix, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void deallocate_matrix(int **&matrix, int height)
{
    for (int i{0}; i < height; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void copy_matrix(int **&matrix, int **&source, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            matrix[i][j] = source[i][j];
        }
    }
}
void transformMatrix(int **&A, int **&B, int N1, int M1, int N2, int M2)
{
    if (N2 < N1 || M2 < M1)
    {
        int **A1 = new int *[N1];
        allocate_matrix(A1, N1, M1);
        copy_matrix(A1, A, N1, M1);
        deallocate_matrix(A, N1);
        if (N2 < N1)
        {
            N1 = N2;
        }
        if (M2 < M1)
        {
            M1 = M2;
        }
        allocate_matrix(A, N1, M1);
        copy_matrix(A, A1, N1, M1);
        deallocate_matrix(A1, N1);
    }
    for (int i{0}; i < N1; ++i)
    {
        for (int j{0}; j < M1; ++j)
        {
            if (A[i][j] <= B[i][j])
            {
                A[i][j] = B[i][j];
            }
            else
            {
                A[i][j] *= -1;
            }
        }
    }
    print_matrix(A, N1, M1);
    deallocate_matrix(A, N1);
    deallocate_matrix(B, N2);
}
void task1()
{
    int N1, M1, N2, M2;
    std::cout << "N1:";
    std::cin >> N1;
    std::cout << "M1:";
    std::cin >> M1;
    std::cout << "N2:";
    std::cin >> N2;
    std::cout << "M2:";
    std::cin >> M2;
    int **A;
    int **B;
    std::cout << "A: " << std::endl;
    allocate_matrix(A, N1, M1);
    enter_matrix(A, N1, M1);
    std::cout << "B: " << std::endl;
    allocate_matrix(B, N2, M2);
    enter_matrix(B, N2, M2);
    std::cout << std::endl;
    transformMatrix(A, B, N1, M1, N2, M2);
}

//TASK 2'
void allocate_matrix(char **&matrix, int height, int width)
{
    matrix = new char *[height];
    for (int i{0}; i < height; ++i)
    {
        matrix[i] = new char[width];
    }
}
void deallocate_matrix(char **&table, int height)
{
    for (int i{0}; i < height; ++i)
    {
        delete[] table[i];
    }
    delete[] table;
}
bool is_valid_symbol(char c)
{
    if (c == 'L' || c == 'R' || c == 'U' || c == 'D')
    {
        return true;
    }
    return false;
}
void enter_matrix(char **&desk, int height, int width)
{
    for (int i{0}; i < height; ++i)
    {
        for (int j{0}; j < width; ++j)
        {
            std::cin >> desk[i][j];
        }
    }
}
bool is_valid(char **&desk, int N, int M)
{
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            if (!is_valid_symbol(desk[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}
int path_length(char **&desk, int start_row, int start_col, int N, int M)
{
    int curr_i{start_row};
    int curr_j{start_col};
    char **desk_copy;
    allocate_matrix(desk_copy, N, M);
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            desk_copy[i][j] = desk[i][j];
        }
    }
    int length{0};
    while (curr_i >= 0 && curr_j >= 0 && curr_i < N && curr_j < M && desk_copy[curr_i][curr_j] && desk_copy[curr_i][curr_j] != 'v')
    {
        switch (desk_copy[curr_i][curr_j])
        {
        case 'L':
        {
            desk_copy[curr_i][curr_j] = 'v';
            --curr_j;
            ++length;
            break;
        }
        case 'R':
        {
            desk_copy[curr_i][curr_j] = 'v';
            ++curr_j;
            ++length;
            break;
        }
        case 'U':
        {
            desk_copy[curr_i][curr_j] = 'v';
            --curr_i;
            ++length;
            break;
        }
        case 'D':
        {
            desk_copy[curr_i][curr_j] = 'v';
            ++curr_i;
            ++length;
            break;
        }
        }
    }
    deallocate_matrix(desk_copy, N);
    return length;
}
void task2()
{
    int N, M;
    do
    {
        std::cin >> N;
        std::cin >> M;
        if (N < 1 || M < 1)
        {
            std::cout << "You should enter integer numbers greater than 1" << std::endl;
        }
    } while (N < 1 || M < 1);
    char **desk;
    allocate_matrix(desk, N, M);
    bool valid_input{true};
    do
    {
        enter_matrix(desk, N, M);
        valid_input = is_valid(desk, N, M);
        if (!valid_input)
        {
            std::cout << "Invalid input! You should enter letters R,L,U or D. Try again!" << std::endl;
        }
    } while (!valid_input);
    int curr_path_length{0};
    int max_path_length{0};
    int start_row, start_column;
    char curr_symbol;
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            curr_path_length = path_length(desk, i, j, N, M);
            if (curr_path_length > max_path_length)
            {
                max_path_length = curr_path_length;
                start_row = i;
                start_column = j;
            }
        }
    }
    deallocate_matrix(desk, N);
    std::cout << start_row << " " << start_column << std::endl;
}
int main()
{
    task0();
    //task1();
    //task2'();
    return 0;
}