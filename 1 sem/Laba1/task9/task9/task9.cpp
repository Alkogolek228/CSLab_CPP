#include <iostream>
#include <climits>

int main()
{
    int a, b;
    std::cout << "Enter digit a\n";
    std::cin >> a;
    std::cout << "Enter digit b\n";
    std::cin >> b;

    while (a >= INT_MAX || a <= INT_MIN || b >= INT_MAX || b <= INT_MIN)
    {
        std::cin.clear();
        std::cout << "Parameter is full, try another\n";
        std::cout << "Enter digit a\n";
        std::cin >> a;
        std::cin.clear();
        std::cout << "Enter digit b\n";
        std::cin >> b;
    }

    a = a xor b;
    b = b xor a;
    a = a xor b;
    std::cout << a << " " << b;

    return 0;
}

