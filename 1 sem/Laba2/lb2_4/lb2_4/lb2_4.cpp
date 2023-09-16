#include <iostream>
#include <iomanip>

int main()
{
    double X, Y, max;
    int option;
    std::cin >> option;

    switch (option)
    {
    case 1:

        std::cin >> X >> Y;
        max = (X > Y) ? X : Y;
        std::cout << max;
        break;

    case 2:

        std::cin >> X >> Y;
        bool check = (X > Y);
        std::cout << (check ? X : Y);
        break; 
    }


}
