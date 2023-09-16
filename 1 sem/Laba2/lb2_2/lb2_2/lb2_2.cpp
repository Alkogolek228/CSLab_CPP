#include <iostream>

int main()
{
    double x, y, z;
    std::cin >> x >> y >> z;
    if (x < y + z && y < x + z && z < x + y)
    {
        std::cout << "YES";
    }

    else
    {
        std::cout << "NO";
    }
}
