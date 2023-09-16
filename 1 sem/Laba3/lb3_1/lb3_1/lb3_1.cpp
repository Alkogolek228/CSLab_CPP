#include <iostream>

int main()
{
	long double a, b, N = 0;
	int i = 1;

	while (i < 31) 
	{
		if (i % 2 == 0) 
		{
			a = i / 2;
			b = i * i * i;
		}

		else 
		{
			a = i;
			b = i * i;
		}

		N += pow(a - b, 2);
		i++;
	}
	std::cout << N;
	return 0;
}