#include <iostream>

int main()
{
    int st = 1, num, sum = 0;
    std::cout << "Enter value\n";
    std::cin >> num;

    while (num <= 1)
    {
        std::cin.clear();
        std::cout << "Error, try another num\n";
        std::cin >> num;
    }

    int option;
    std::cout << "Enter case\n";
    std::cin >> option;

    switch (option)
    {
    case 1:

        for (int i = st; i <= num; i++)
        {
            if (i % 2 == 0)
            {
                sum += i;
            }
        }

        std::cout << sum;
        break;

    case 2:
        
        st += st % 2;
        num -= num % 2;
        std::cout << (st + num) * (num - st + 2) / 4;
        break;
    } 
}
