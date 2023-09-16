#include <iostream>

int main()
{
    long double a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    
    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0)
    {
        std::cout << "Incorrect input";
    }

    else if (x >= a && y >= b || x >= c && y >= b || x >= a && y >= c)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}

