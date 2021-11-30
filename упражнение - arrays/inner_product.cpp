#include <iostream>
using namespace std;
int inner_product(const int input_arr_1[], unsigned begin_1, unsigned end_1,
                  const int input_arr_2[], unsigned begin_2)
{
    int inner_prod = 0;
    for (unsigned i{begin_1}; i < end_1; ++i)
    {
        i <= begin_2 ? inner_prod += input_arr_1[i] * input_arr_2[i] : inner_prod;
    }
    return inner_prod;
}
int main()
{
    int a[]{0, 1, 2, 3, 4};
    int b[]{5, 4, 2, 3, 1};

    std::cout<<inner_product(a, 0, 5, b, 5);

    return 0;
}