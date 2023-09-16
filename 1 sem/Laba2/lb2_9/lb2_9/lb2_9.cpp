#include <iostream>
#include <cmath>

int main()
{
    std::cout << "y=-p*f(x)+a*cos^2(x^3) + b*sin^3(x^2)\n";
    long double x, z, y, a, b;
    int option;
    std::cout << "Enter option (f(x)=2x - 1; f(x)=x^3 - 2; f(x)=x/3 - 3)\n";
    std::cin >> option;
    switch (option)
    {
    case 1:
        std::cout << "f(x)=2x\n";
        std::cout << "Enter Z:\n";
        std::cin >> z;
        std::cout << "Enter a,b:\n";
        std::cin >> a >> b;

        if (z < 1)
        {
            x = z;
            y = (3.14159265358979323846 * 2.0 * x) + (a * powl(cos(powl(x, 3)), 2)) + (b * powl(sin(powl(x, 2)), 3));
            std::cout << y;
        }

        else if (z >= 1)
        {
            x = sqrt(pow(z, 3));
            y = (3.14159265358979323846 * 2.0 * x) + (a * powl(cos(powl(x, 3)), 2)) + (b * powl(sin(powl(x, 2)), 3));
            std::cout << y;
        }
     break;

    case 2:
        std::cout << "f(x)=x^3\n";
        std::cout << "Enter Z:\n";
        std::cin >> z;
        std::cout << "Enter a,b:\n";
        std::cin >> a >> b;

        if (z < 1)
        {
            x = z;
            y = (3.14159265358979323846 * powl(x,3)) + (a * powl(cos(powl(x, 3)), 2)) + (b * powl(sin(powl(x, 2)), 3));
            std::cout << y;
        }

        else if (z >= 1)
        {
            x = sqrt(pow(z, 3));
            y = (3.14159265358979323846 * powl(x, 3)) + (a * powl(cos(powl(x, 3)), 2)) + (b * powl(sin(powl(x, 2)), 3));
            std::cout << y;
        }
        break;

    case 3:
        std::cout << "f(x)=x/3\n";
        std::cout << "Enter Z:\n";
        std::cin >> z;
        std::cout << "Enter a,b:\n";
        std::cin >> a >> b;

        if (z < 1)
        {
            x = z;
            y = (3.14159265358979323846 * (x / 3)) + (a * powl(cos(powl(x, 3)), 2)) + (b * powl(sin(powl(x, 2)), 3));
            std::cout << y;
        }

        else if (z >= 1)
        {
            x = sqrt(pow(z, 3));
            y = (3.14159265358979323846 * (x / 3)) + (a * powl(cos(powl(x, 3)), 2)) + (b * powl(sin(powl(x, 2)), 3));
            std::cout << y;
        }
        break;
    }
}

