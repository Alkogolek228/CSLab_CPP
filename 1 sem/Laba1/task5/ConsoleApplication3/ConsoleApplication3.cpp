
#include <iostream>

int main()
{
    int X, Y;

    std::cin >> X >> Y;

    if (X == 0 && Y == 0)
    {
        std::cout << "ERROR\n";
    }

    else if (X == 0 || Y == 0)
    {
        std::cout << "YES\n";
    }

    else if (X % Y == 0 || Y % X == 0)
    {
        std::cout << "YES\n";
    }

    else if (X % Y != 0 || Y % X != 0)
    {
        std::cout << "NO/n";
    }

    return 0;
}


