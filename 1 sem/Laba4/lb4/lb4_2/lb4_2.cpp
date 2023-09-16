#include <iostream>

int enter()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "Некорректные значения. Повторите ввод :\n";
		}
	}

	return a;
}

int NonStop()
{
	int a;
	std::cout << "Повторить?\n1. Да\n2. Нет\n\n";

	while (!(std::cin >> a) || (std::cin.peek() != '\n') || (a != 1 && a != 2))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "Некорректный ввод, повтрорите ввод:\n";
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

void reference2()
{
	std::cout << "Меня зовут Данила Альховик и я выполнил задание № 2" << "\n\n";
	std::cout << "Суть задания такова: определить сумму отрицательных элементов матрицы, расположенных выше побочной диагонали" << "\n\n";
	std::cout << "Пожалуйста,введите ЦЕЛОЧИСЛЕННЫЕ элементы матрицы" << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	reference2();
	const int n = 4;
	const int m = 4;

	int q = 1;
	while (q)
	{


		int mas[n][m];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mas[i][j] = enter();
			}
		}

		int sum = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 0; j < m - i - 1; ++j)
			{
				if (mas[i][j] < 0)
				{
					sum += mas[i][j];
				}

			}
		}

		std::cout << "Результат:  ";
		std::cout << sum;

		q = NonStop();
	}
}