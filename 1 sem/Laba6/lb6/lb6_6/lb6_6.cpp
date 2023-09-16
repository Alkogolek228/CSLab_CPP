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

int main()
{
	char str[14], str1[14], num;
	std::cin >> str;
	sort(str);
	long long sum = 1, index = 0, count = 0, length = strlen(str), len = length;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (str[i] == str[j])
			{
				num = str[i];
				count++;
			}
		}

		for (int k = 0; k < len; k++)
		{
			if (num != str[k])
			{
				str1[index] = str[k];
				str[index] = str1[index];
				index++;
			}
		}

		len -= count;
		sum *= fact(count);
		count = 0;
		index = 0;
		i = 0;

		if (len == 1)
		{
			break;
		}
	}
	std::cout << fact(length) / sum;
}

