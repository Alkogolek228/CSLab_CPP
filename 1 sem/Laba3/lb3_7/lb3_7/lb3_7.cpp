#include <iostream>
#include <iomanip>
#include <locale.h>

unsigned long long fact(long long N) 
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


long double labLog(long double x) 
{
	long double ln_2 = 0.693147180559945309417232121458176568, z = 0;
	const long double e = 1e-9, a = ln_2;
	int k = 0;

	if (x < 1e-1) 
	{
		x = x / x / x;
		z = 1;
	}

	while (x >= 2.0) 
	{
		x /= 2.0;
		k++;
	}

	x -= 1;
	long double s = 0, an = x;
	int n = 1;

	while (abs(an) > e) 
	{
		s += an;
		n++;
		an *= -x * (n - 1) / n;
	}

	s += k * a;

	if (z == 1) 
	{
		s = -s;
	}
	return s;
}

long double labSin(long double x) 
{
	long double a = 0, b = 0, c = 0, m = 0;
	long long n = 0;

	if (x > 0) 
	{
		b = floor(x / (2 * (acos(-1))) + 0.5);
		x -= b * 2 * acos(-1);
	}

	else 
	{
		a = floor(-x / (2 * (acos(-1))) + 0.5);
		x += a * 2 * acos(-1);
	}

	while (n <= 10) 
	{
		a = pow(-1, n) * (pow(x, 2.0 * n + 1.0) / fact(2 * n + 1));
		m += a;
		n++;
	}
	return m;
}

long double labCos(long double x) 
{
	int n = 0;
	long double k = 0, a = 0, b = 0, c = 0;

	if (x > 0) 
	{
		a = floor(x / (2 * (acos(-1))) + 0.5);
		x -= a * 2 * acos(-1);
	}

	else 
	{
		a = floor(-x / (2 * (acos(-1))) + 0.5);
		x += a * 2 * acos(-1);
	}

	while (n <= 10) 
	{
		b = pow(-1, n) * (pow(x, 2 * n) / fact(2 * n));
		k += b;
		n++;
	}
	return k;
}

int main() 
{
	long long n = 0, N = 2 * n + 1;
	long double x, min;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите х: ";
	std::cin >> x;
	min = labSin(x);

	if (labCos(x) < min) 
	{
		min = labCos(x);
	}

	if (labLog(x) < min) 
	{
		min = labLog(x);
	}

	std::cout << std::setprecision(14) << "Синус: " << labSin(x) << std::endl << "Косинус: " << labCos(x) << std::endl << "Логарифм: " << labLog(x) << std::endl << "Минимальное значение: " << min;
	return 0;
}