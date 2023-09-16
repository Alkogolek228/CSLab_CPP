#include <iostream>
#include <climits>

int main()
{
    long long a, s = 0, r;
    int n;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "n = ";
    std::cin >> n; 

    for (long long i = 1; i <= n; i++)
    {
         r = pow(2, (i - 1)) * pow(-1, (i - 1)) * a;
         s += r;
        
        if(r >= LONG_MAX || r <= LONG_MIN || s >= LONG_MAX || s <= LONG_MIN)
        {
            break;
        }
    }
    std::cout << s;
}