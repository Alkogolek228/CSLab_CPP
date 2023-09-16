#include<iomanip>
#include <iostream>

int main()
{
    double a, b, c, Y;
    int N;
    std::cin >> N;
    std::cin >> a >> b >> c;

    switch (N) 
    {
    case 2:

        Y = b * c - a * a;
        break;

    case 56:

        Y = b * c;
        break;

    case 7:

        Y = pow(a, 7) + c;
        break;

    case 3:

        Y = a - b * c;
        break;
    }

    if (N != 2 && N != 3 && N != 7 && N != 56) 
    {
        Y = pow((a + b), 3);
    }

    std::cout << Y;
    return 0;
}