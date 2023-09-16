#include "pch.h"
#include <iostream>
#include <string.h>

long long fact(int N)
{
	if (N < 0)
	{
		return 0;
	}

	if (N == 0)
	{
		return 1;
	}

	else
	{
		return N * fact(N - 1);
	}
}

void swap(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void sort(char* str)
{
	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			if (*(str + i) > *(str + j))
			{
				swap(str + i, str + j);
			}
		}
	}
}


TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(factorial)
{
	ASSERT_EQ(fact(7), 5040);
}

TEST(sortirovka)
{
	char str[] = "SOLO";
	sort(str);
	ASSERT_STRNE(str, "OSLO");
}