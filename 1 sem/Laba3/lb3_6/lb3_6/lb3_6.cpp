#include <iostream>
#include <cmath>

int main() 
{

	long double fx, step, step0 = 0, fx0, min;
	int quastep;

	do 
	{
		std::cout << "Enter quality of steps (more than 1)" << '\n';
		std::cin >> quastep;
	} 
	while (quastep < 2);

	do 
	{
		std::cin.clear();
		std::cout << "Enter step (from 0.1 to 1)" << '\n';
		std::cin >> step;
		
	} 
	while (step <= 0 || step > 1);

	if (quastep * step > 1) 
	{
		std::cout << "stol'ko operaciy summarno vyhodyat cherez diapozon!";
		return 0;
	}

	
	fx0 = asin(step0) - step0 + pow(step0, 2) - 1;
	min = fx0;

	for (int i = 0; i <= quastep; i++) 
	{
		
		fx = asin(step0) - step0 + pow(step0, 2) - 1;
		if (fx < 0) 
		{
			fx = -fx;
		}

		if (min > fx) 
		{
			min = fx;
		}
		step0 = step0 + step;
	}
	std::cout << min << " - min koren' v diapozone";
	return 0;
}