#include <iostream>
#include <cmath>

int main() 
{
	long double  A, B, M, y, X = 0, H;
	long double PI = acos(-1.0);
	A = 0;
	B = PI / 2;
	M = 20;
	H = (B - A) / M;

	for (int i = 0; X < B && X >= A; i++) 
	{
		X = A + i * H;
		y = sin(X) - cos(X);

		std::cout << y << '\n';
	}

	return 0;
}