#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x, y;
    std::cin >> x >> y;
    const double distance = sqrt(x * x + (y - 2) * (y - 2));
    const double eps = 0.000001;
    const bool isInFigure1 = distance - 2 <= eps && (x > 0 || fabs(x - 0) <= eps) && (y > 0 || fabs(y - 0) <= eps);
    const bool isInFigure2 = (x >= -3 || fabs(x + 3) <= eps) && (x <= eps) && (y <= eps) && (y > -3 || fabs(y + 3) <= eps);
    const bool isInFigure3 = ((x > -3 || fabs(x + 3) <= eps) && x <= eps && (y > 0 || fabs(y) <= eps) && (y < 3 || fabs(y - 3) <= eps) && fabs(y) - fabs(x) <= eps);
    const bool isInFigure4 = ( (x > 1 || fabs(x-1) <=eps) && (x < 3 || fabs(x-3) <=eps) && (y > -3 || fabs(y+3) <=eps) && (y < -1 || fabs(y+1) <=eps) && fabs(x) - fabs(y) <= eps);
    if (isInFigure1 || isInFigure2 || isInFigure3 || isInFigure4)
    {
        std::cout << "Inside\n";
    }
    else
    {
        std::cout << "Outside\n";
    }
    return 0;
}