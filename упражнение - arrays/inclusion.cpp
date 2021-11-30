#include <iostream>
using namespace std;
bool includes(const int set_1[], unsigned begin_1, unsigned end_1,
              const int set_2[], unsigned begin_2, unsigned end_2)
{
    if (end_1 - begin_1 < end_2 - begin_2)
    {
        return false;
    }
    unsigned same_digits{0};
    for (unsigned i{begin_1}; i < end_1; ++i)
    {
        if (set_2[0] == set_1[i])
        {
            same_digits = 1;
            while (set_1[i + same_digits] == set_2[same_digits])
            {
                ++same_digits;
            }
        }
        if (same_digits == end_2 - begin_2)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int set_1[]{1, 2, 3, 5};
    int set_2[]{1, 2, 3};
    int set_3[]{1, 2, 4};

    std::cout << std::boolalpha << includes(set_1, 0, 4, set_2, 0, 3) << std::endl; // -> true

    std::cout << std::boolalpha << includes(set_1, 0, 4, set_3, 0, 3) << std::endl; // -> false

    return 0;
}