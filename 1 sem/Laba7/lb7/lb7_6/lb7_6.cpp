#include <iostream>
#include <cmath>

int NonStop()
{
	int a;
	std::cout << "Повторить?\n1. Да\n2. Нет\n\n";
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || (a != 1 && a != 2) || std::cin.peek() == ' ')
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "Некорректный ввод, введите снова:\n";
		}
	}

	if (a == 2)
	{
		return 0;
	}

	else
	{
		return 1;
	}
}

void reference6()
{
	std::cout << "Меня зовут Данила Альховик и я выполнил задание № 6" << "\n\n";
	std::cout << "Суть задания такова: проверить числа на делимость" << "\n\n";
}

int enter()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0 || std::cin.peek() == ' ')
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "Некорректный ввод, введите снова:\n";
		}
	}
	return a;
}

int main() // O(n) + const
{
	setlocale(LC_ALL, "russian");
	reference6();
	int count = 1;
	while (count)
	{
		std::cout << "Введите число\n";
		int k;
		k = enter();
		int k7 = k, k29 = k, k149 = k, r = 0;
		bool check = false;
		while (k7 > 13)
		{
			if (k7 & 1)
			{
				r = 4;
			}
			else
			{
				r = 0;
			}
			k7 >>= 1;
			if (k7 + r == 7)
			{
				check = true;
				break;
			}
			k7 = k7 + r;
		}
		if (check)
		{
			std::cout << "Да оно делится на 7\n";

		}
		else
		{

			std::cout << "Нет оно не делится на 7\n";
		}

		check = false;
		while (k29 > 57)
		{
			if (k29 & 1)
			{
				r = 15;
			}
			else
			{
				r = 0;
			}
			k29 >>= 1;
			if (k29 + r == 29)
			{
				check = true;
				break;
			}
			k29 = k29 + r;
		}
		if (check)
		{
			std::cout << "Да оно делится на 29\n";

		}
		else
		{

			std::cout << "Нет оно не делится на 29\n";
		}
		check = false;
		while (k149 > 297)
		{
			if (k149 & 1)
			{
				r = 75;
			}
			else
			{
				r = 0;
			}
			k149 >>= 1;
			if (k149 + r == 149)
			{
				check = true;
				break;
			}
			k149 = k149 + r;
		}
		if (check)
		{
			std::cout << "Да оно делится на 149\n";

		}
		else
		{
			std::cout << "Нет оно не делится на 149\n";
		}
		check = false;
		count = NonStop();
	}
}
