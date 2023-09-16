#include "pch.h"
#include <iostream>
#include <cmath>

long long binpow(long long base, long long power, int module)
{
    long long res = 1;
    base %= module;
    while (power)
    {
        if (power & 1)
        {
            res *= base;
            res %= module;
        }
        base *= base;
        base %= module;
        power >>= 1;
    }
    return res;
}

bool inter(std::string s1, std::string s2, long long L)
{
    long long raz = std::abs(s1.length() + s2.length() - L);
    std::string str1, str2;
    str1 = s1.substr(s1.length() - raz, s1.length());
    str2 = s2.substr(0, raz);

    if (str1 == str2)
    {
        return true;
    }
    return false;
}

long long solve(std::string s1, std::string s2, long long L, long long module)
{
    long long s1_len = s1.length();
    long long s2_len = s2.length();
    long long answer = 0;
    if ((L - s1_len - s2_len) >= 0)
    {
        answer = binpow(26, (L - s1_len - s2_len), module);

        if (s1 != s2)
        {
            answer = (2 * binpow(26, (L - s1_len - s2_len), module)) % module;
        }
    }

    else if ((L - s1_len - s2_len) < 0)
    {
        if (inter(s1, s2, L))
        {
            return  1;
        }
        else
        {
            return 0;
        }
    }
    return answer;
}

TEST(TestCaseName, TestName)
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(test_solve1)
{
    ASSERT_EQ(solve("ans", "wer", 10000000, 10), 2);
}

TEST(test_solve2)
{
    ASSERT_EQ(solve("cup", "russia", 14, 1000), 752);
}

TEST(test_inter)
{
    if (inter("cup", "cup", 6))
    {
        SUCCEED();
    }
}

TEST(test_binpow)
{
    ASSERT_EQ(binpow(2, 2, 10), 4);
}