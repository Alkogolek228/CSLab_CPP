#include <iostream>
#include <cmath>

std::string dectoany(long long number, const unsigned int& base)
{
    const char* DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
    bool flag_of_inversion = false;
    std::string reversString, stringInBase;

    stringInBase += DIGITS[number % base];
    number = number / base;

    while (number)
    {
        stringInBase += DIGITS[number % base];
        number = number / base;
    }

    if (flag_of_inversion == true)
    {
        reversString = "1";
    }

    for (int i = stringInBase.length() - 1; i >= 0; i--)
    {
        reversString += stringInBase[i];
    }

    return reversString;
}

int main() // O(n) + const
{
    long long number;
    std::cin >> number;
    std::string NUMBER = dectoany(number, 3);

    for (int i = 0; i < NUMBER.length(); i++)
    {
        if (NUMBER[i] == '0')
        {
            NUMBER[i] = '3';
            NUMBER[i-1]--;
            if (NUMBER[i-1] != '0')
            {
                
            }
            else if((i-1)==0)
            {
                NUMBER.erase(i - 1, 1);
            }
            i -= 2;
            i = std::max(i, 0);
        }
    }

    std::cout << NUMBER;
}
