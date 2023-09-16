#include "pch.h"
std::string number(int number)
{
    int ones, dec, cent, mil;

    ones = number % 10;
    dec = (number / 10) % 10;
    cent = (number / 100) % 10;
    mil = (number / 1000) % 10;

    std::string str = "";

    if (mil == 1)
    {
        str += "M";
    }
    if (mil == 2)
    {
        str += "MM";
    }
    if (mil == 3)
    {
        str += "MMM";
    }
    if (cent == 1)
    {
        str += "C";
    }
    if (cent == 2)
    {
        str += "CC";
    }
    if (cent == 3)
    {
        str += "CCC";
    }
    if (cent == 4)
    {
        str += "CD";
    }
    if (cent == 5)
    {
        str += "D";
    }
    if (cent == 6)
    {
        str += "DC";
    }
    if (cent == 7)
    {
        str += "DCC";
    }
    if (cent == 8)
    {
        str += "DCCC";
    }
    if (cent == 9)
    {
        str += "CM";
    }

    if (dec == 1)
    {
        str += "X";
    }
    if (dec == 2)
    {
        str += "XX";
    }
    if (dec == 3)
    {
        str += "XXX";
    }
    if (dec == 4)
    {
        str += "XL";
    }
    if (dec == 5)
    {
        str += "L";
    }
    if (dec == 6)
    {
        str += "LX";
    }
    if (dec == 7)
    {
        str += "LXX";
    }
    if (dec == 8)
    {
        str += "LXXX";
    }
    if (dec == 9)
    {
        str += "XC";
    }

    if (ones == 1)
    {
        str += "I";
    }
    if (ones == 2)
    {
        str += "II";
    }
    if (ones == 3)
    {
        str += "III";
    }
    if (ones == 4)
    {
        str += "IV";
    }
    if (ones == 5)
    {
        str += "V";
    }
    if (ones == 6)
    {
        str += "VI";
    }
    if (ones == 7)
    {
        str += "VII";
    }
    if (ones == 8)
    {
        str += "VIII";
    }
    if (ones == 9)
    {
        str += "IX";
    }

    return str;
}


TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(test_max)
{
    std::string ans = number(3999);
    std::string a = "MMMCMXCIX";
    ASSERT_TRUE(a == ans);
}