#include <iostream>

int main() // O(n) + small const
{
    int number;
    std::cin >> number;
    int ones, dec, cent, mil;

    ones = number % 10;
    dec = (number / 10) % 10;
    cent = (number / 100) % 10;
    mil = (number / 1000) % 10;

    if (mil == 1)
    {
        std::cout << "M";
    }
    if (mil == 2)
    {
        std::cout << "MM";
    }
    if (mil == 3)
    {
        std::cout << "MMM";
    }
    if (cent == 1)
    {
        std::cout << "C";
    }
    if (cent == 2)
    {
        std::cout << "CC";
    }
    if (cent == 3)
    {
        std::cout << "CCC";
    }
    if (cent == 4)
    {
        std::cout << "CD";
    }
    if (cent == 5)
    {
        std::cout << "D";
    }
    if (cent == 6)
    {
        std::cout << "DC";
    }
    if (cent == 7)
    {
        std::cout << "DCC";
    }
    if (cent == 8) 
    {
        std::cout << "DCCC";
    }
    if (cent == 9)
    {
        std::cout << "CM";
    }

    if (dec == 1)
    {
        std::cout << "X";
    }
    if (dec == 2)
    {
        std::cout << "XX";
    }
    if (dec == 3)
    {
        std::cout << "XXX";
    }
    if (dec == 4)
    {
        std::cout << "XL";
    }
    if (dec == 5)
    {
        std::cout << "L";
    }
    if (dec == 6)
    {
        std::cout << "LX";
    }
    if (dec == 7)
    {
        std::cout << "LXX";
    }
    if (dec == 8)
    {
        std::cout << "LXXX";
    }
    if (dec == 9)
    {
        std::cout << "XC";
    }

    if (ones == 1)
    {
        std::cout << "I";
    }
    if (ones == 2)
    {
        std::cout << "II";
    }
    if (ones == 3)
    {
        std::cout << "III";
    }
    if (ones == 4)
    {
        std::cout << "IV";
    }
    if (ones == 5)
    {
        std::cout << "V";
    }
    if (ones == 6)
    {
        std::cout << "VI";
    }
    if (ones == 7)
    {
        std::cout << "VII";
    }
    if (ones == 8)
    {
        std::cout << "VIII";
    }
    if (ones == 9)
    {
        std::cout << "IX";
    }

}
