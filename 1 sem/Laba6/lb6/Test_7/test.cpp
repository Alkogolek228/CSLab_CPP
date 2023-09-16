#include "pch.h"
#include <iostream>
#include <string>

long long checkpalindrom(std::string str)
{
    long long same = 0;

    for (int i = 0; i < (str.size() / 2); i++)
    {
        if (str[i] == str[str.size() - (i + 1)])
        {
            same++;
        }
    }
    return same;
}

long long checkstring(std::string str)
{
    long long same = 0;

    for (int i = 0; i < (str.size()); i++)
    {
        if (str[0] == str[str.size() - (i + 1)])
        {
            same++;
        }
    }
    return same;
}


TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(test_check)
{
	ASSERT_EQ(checkpalindrom("aaaaaaaaaaaabbbbbbbbbbbaaaaaaaaaaaa"), 17);
}

TEST(test_checkstring)
{
    ASSERT_EQ(checkstring("aaaaaaaaaaaabbbbbbbbbbbaaaaaaaaaaaa"), 24);
}