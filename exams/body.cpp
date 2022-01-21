#include <iostream>
#include <cstring>
#define SIZE 5
using namespace std;
struct Body
{
    double coordinates[2];
    double weight;
    double speed;
    char description[20];
};
void enterBody(Body &a)
{
    std::cout << "x :";
    std::cin >> a.coordinates[0];
    std::cout << "y :";
    std::cin >> a.coordinates[1];
    std::cout << "weight: ";
    std::cin >> a.weight;
    std::cout << "speed: ";
    std::cin >> a.speed;
    std::cout << "description: ";
    std::cin.clear();
    std::cin.ignore();
    std::cin.getline(a.description, 20);
}
void print_bodies(Body &a)
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "PRINT" << std::endl;
    std::cout << std::endl;
    std::cout << "x: " << a.coordinates[0] << std::endl;
    std::cout << "y: " << a.coordinates[1];
    std::cout << "weight: " << a.weight << std::endl;
    std::cout << "speed: " << a.speed << std::endl;
    std::cout << "description: " << a.description << std::endl;
}
int main()
{
    Body *bodies = new Body[SIZE];
    for (unsigned i{0}; i < SIZE; ++i)
    {
        enterBody(bodies[i]);
    }
    for (unsigned i{0}; i < SIZE; ++i)
    {
        print_bodies(bodies[i]);
    }
    delete[] bodies;

    return 0;
}