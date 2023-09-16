#include <iostream>
#include <climits>
#include <cmath>

long double labSin(long double x)
{
	long double answer = x;
	long double fact = 6;
	long double curNum = 4;
	long double pow = -x * x * x;

	for (int i = 0; i < 20; i++)
	{
		answer += pow / fact;
		fact *= curNum * (curNum + 1);
		curNum += 2;
		pow *= -x * x;
	}
	return answer;
}

long double labCos(long double x)
{
	long double answer = 1;
	long double fact = 2;
	long double curNum = 3;
	long double pow = -x * x;

	for (int i = 0; i < 20; i++)
	{
		answer += pow / fact;
		fact *= curNum * (curNum + 1);
		curNum += 2;
		pow *= -x * x;
	}
	return answer;
}

int main() 
{
	long double x, S = 0, Y, Y1, e = 2.71828, PI = acos(-1.0);
	int n, numx;

	std::cout << "Enter numx" << '\n';
	std::cin >> numx;

	if (numx < 1) 
	{
		std::cout << "Enter correct numx" << '\n';
		return 0;
	}

	std::cout << "Enter n" << '\n';
	std::cin >> n;

	if (n < 0) 
	{
		std::cout << "Enter correct n" << '\n';
		return 0;
	}

	for (int h = 1; h <= numx; h++) 
	{
		std::cout << "Enter x from 0.1 to 1" << '\n';
		std::cin >> x;

		if (x < 0.1 || x > 1) 
		{
			std::cout << "Enter correct x" << '\n';
			return 0;
		}

		Y =  powl(e, (x * cos(PI / 4))) * cos(x * sin(PI / 4));
		std::cout << "Y(x) = " << Y << '\n';

		Y1 = powl(e, (x * labCos(PI / 4))) * labCos(x * labSin(PI / 4));
		std::cout << "Y1(x) = " << Y1 << '\n';

		long double res = 1;
		long double constX = x;
		long double constF = 1;
		long double curNum = 2;
		for (int i = 1; i <= n; i++)
		{
			res += labCos(i * (PI / 4)) * constX / constF;
			constX *= x;
			constF *= curNum;
			curNum++;
		}

		std::cout << "S(x) = " << res << "\n";
		
		/*long double constX = cos(n * (PI / 4)) * powl(x, n);
		long double constF = 1;
		long double curNum = 1;
		long double res = constX / constF;

		for (int i = 1; i < n; i++)
		{
			constX *= (cos(n * (PI / 4)) * powl(x, n));
			constF *= (constF * (curNum) * (curNum + 2));
			curNum += 2;
			res += constX / constF;
		}

		std::cout << "S(x) = " << res << '\n';*/
	}
	return 0;
}

