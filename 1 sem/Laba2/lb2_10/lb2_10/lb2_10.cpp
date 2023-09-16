#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");
    long double x1, y1, r, x2, y2, R, l;
    std::cin >> x1 >> y1 >> r >> x2 >> y2 >> R;
    l = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (R > r && r + l < R) 
    {
        std::cout << "Да"; 
        return 0;
    }

    else if (R < r && r + l > R) 
    {
        std::cout << "Да, но справедливо обратное для двух фигур";
        return 0;
    }

    if (l <= R + r) 
    {
        std::cout << "Фигуры пересекаются";
        return 0;
    }

    else if (l > R + r) 
    {
        std::cout << "Ни одно условие не выполнено";
        return 0;
    }

    return 0;
}