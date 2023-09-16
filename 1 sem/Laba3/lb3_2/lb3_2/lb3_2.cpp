#include <iostream>
#include <cmath>

int main() 
{
	int n = 1;
	long double e, d, S = 0;
	e = pow(10, -3);

	do 
	{
		d = (1 / pow(2, n)) + (1 / pow(3, n));
		std::cout << d << '\n';
		n++;
		S += d;
	} 
	
	while (d >= e);

	std::cout << S << '\n';
	return 0;
}