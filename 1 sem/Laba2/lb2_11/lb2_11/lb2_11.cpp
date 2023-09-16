#include <iostream>
#include <cmath>

int main()
{
    double R, P, Q, PI;
    std::cin >> R >> P >> Q;
    PI = acos(-1.0);
    if (Q >= PI / 2)
    {
        std::cout << "Enter another angle\n";
    }
    else
    {
        double d1 = 2 * P * sin(Q / 2);
        double d2 = 2 * P * cos(Q / 2);
        double r = d1 * d2 / (2 * sqrt(d1 * d1 + d2 * d2));
        if (R < r)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}
