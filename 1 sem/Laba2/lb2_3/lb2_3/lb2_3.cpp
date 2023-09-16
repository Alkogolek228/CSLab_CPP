#include <iostream>

int main()
{
    long long X, Y;
    long double A, B, C, K;
    std::cin >> X >> Y;
    std::cin >> A >> B >> C >> K;

    if (X > Y)
    {
        Y = 0;
    }
    else if (Y > X)
    {
        X = 0;
    }
    else if (X == Y)
    {
        X = 0;
        Y = 0;
    }

    std::cout << X << " " << Y << "\n";

    if (A > B && A > C)
    {
        A -= K;
    }
    else if (B > A && B > C)
    {
        B -= K;
    }
    else if (C > A && C > B)
    {
        C -= K;

    }
    std::cout << A << " " << B << " " << C << "\n";
    return 0;
}
