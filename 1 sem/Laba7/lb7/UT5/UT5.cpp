#include "pch.h"

int FuncNotFrom7_2(int interval_end)
{
    int res = 0;

    for (int i = 1; i <= interval_end; i++)
    {
        if (i % 10 == 9)
        {
            res++;
        }
    }
    return res;
}

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(test_big_num)
{
    ASSERT_EQ(10000000, FuncNotFrom7_2(100000000));
}