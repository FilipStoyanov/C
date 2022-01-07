#include <iostream>
#include <random>
using namespace std;
double approximate_pi(unsigned attempts, double eps)
{
    double random_x, random_y;
    unsigned circle_points{0};
    unsigned square_points{0};
    double pi;
    for (unsigned i{0}; i < attempts; ++i)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        random_x = std::uniform_real_distribution<>(0, 1)(gen);
        random_y = std::uniform_real_distribution<>(0, 1)(gen);
        if (random_x * random_x + random_y * random_y <= 1)
        {
            ++circle_points;
        }
        ++square_points;
    }
    pi = double(4 * circle_points) / square_points;
    return pi;
}
int main()
{
    std::cout << approximate_pi(1000000, 0.0001) << '\n'
              << approximate_pi(1000000, 0.0001) << '\n';

    /*
    3.14372
    3.14187
*/

    return 0;
}