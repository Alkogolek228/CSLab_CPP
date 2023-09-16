#include<cmath>
#include <iostream>

void reference11()
{
	std::cout << "Меня зовут Данила Альховик и я выполнил задание № 11" << "\n\n";
	std::cout << "Суть задания такова: написать тот самый сапер" << "\n\n";
}

int enter()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0 || std::cin.peek() == ' ' || a == 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "Некорректные значения. Повторите ввод :\n";
		}
	}

	return a;
}

int enterfield()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0 || (a!=1 && a!=0) || std::cin.peek() == ' ')
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

	while (!(std::cin >> a) || (std::cin.peek() != '\n') || (a != 1 && a != 2) || std::cin.peek() == ' ')
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


char bombs(short b)
{
	if (b == 0)
	{
		return '0';
	}

	if (b == 1)
	{
		return '1';
	}

	if (b == 2)
	{
		return '2';
	}

	if (b == 3)
	{
		return '3';
	}

	if (b == 4)
	{
		return '4';
	}

	if (b == 5)
	{
		return '5';
	}

	if (b == 6)
	{
		return '6';
	}

	if (b == 7)
	{
		return '7';
	}

	if (b == 8)
	{
		return '8';
	}
}

int main()
{
	std::setlocale(LC_ALL, "Russian");
	reference11();
	int n = 1;
	while (n)
	{
		long double g;
		long long rows, columns;

		std::cout << "Введите ЦЕЛОЕ количество строк" << "\n\n";

		rows = enter();

		std::cout << "Введите ЦЕЛОЕ количество столбцов" << "\n\n";

		columns = enter();

		char** mas = new char* [rows];

		for (int i = 0; i < rows; i++)
		{
			mas[i] = new char[columns];
		}

		srand(time(NULL));

		std::cout << "Введите 0 для бомбы или 1 для пустой клетки" << "\n\n";
		///создание поля
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0, a; j < columns; j++)
			{
				/*a = rand() % 2;*/
				
				a = enterfield();

				if (a == 0)
				{
					mas[i][j] = '*';
				}

				if (a == 1)
				{
					mas[i][j] = '0';
				}

				std::cout << mas[i][j] << " ";

			}

			std::cout << '\n';

		}
		std::cout << "\n\n\n";
		///обработка поля
		///неполноценное 
		///одна строка

		if (rows == 1 && columns > 1)
		{
			if (mas[0][1] == '*' && mas[0][0] == '0')
			{
				mas[0][0] = '1';
			}

			if (mas[0][columns - 2] == '*' && mas[0][columns - 1] == '0')
			{
				(mas[0][columns - 1] = '1');
			}

			for (long long i = 1; i < columns - 1; i++)
			{
				if (mas[0][i] == '0')
				{
					short b = 0;
					if (mas[0][i - 1] == '*')
					{
						b++;
					}

					if (mas[0][i + 1] == '*')
					{
						b++;
					}
					mas[0][i] = bombs(b);
				}

			}
			for (long long i = 0; i < columns; i++)
			{
				std::cout << mas[0][i] << " ";
			}
			return 0;
		}

		///один столбец
		if (rows > 1 && columns == 1)
		{
			if (mas[1][0] == '*' && mas[0][0] == '0')
			{
				mas[0][0] = '1';
			}

			if (mas[rows - 2][0] == '*' && mas[rows - 1][0] == '0')
			{
				(mas[rows - 1][0] = '1');
			}

			for (long long i = 1; i < rows - 1; i++)
			{
				if (mas[i][0] == '0')
				{

					short b = 0;
					if (mas[i - 1][0] == '*')
					{
						b++;
					}

					if (mas[i + 1][0] == '*')
					{
						b++;
					}

					mas[i][0] = bombs(b);
				}

			}

			for (long long i = 0; i < rows; i++)
			{
				std::cout << mas[i][0] << "\n";
			}
			return 0;
		}

		///полнеоценное
		if (rows > 1 && columns > 1)
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0, a; j < columns; j++)
				{
					if (mas[i][j] == '0')
					{
						///левый верхний
						if (i == 0 && j == 0)
						{
							short b = 0;
							if (mas[1][0] == '*')
							{
								b++;
							}

							if (mas[1][1] == '*')
							{
								b++;
							}

							if (mas[0][1] == '*')
							{
								b++;
							}
							mas[0][0] = bombs(b);
						}

						///правый верхний
						if (i == 0 && j == columns - 1)
						{
							short b = 0;
							if (mas[0][columns - 2] == '*')
							{
								b++;
							}

							if (mas[1][columns - 2] == '*')
							{
								b++;
							}

							if (mas[1][columns - 1] == '*')
							{
								b++;
							}
							mas[0][columns - 1] = bombs(b);
						}

						///правый нижний
						if (i == rows - 1 && j == columns - 1)
						{
							short b = 0;
							if (mas[rows - 1][columns - 2] == '*')
							{
								b++;
							}

							if (mas[rows - 2][columns - 2] == '*')
							{
								b++;
							}

							if (mas[rows - 2][columns - 1] == '*')
							{
								b++;
							}
							mas[rows - 1][columns - 1] = bombs(b);
						}

						///левый нижний
						if (i == rows - 1 && j == 0)
						{
							short b = 0;
							if (mas[rows - 1][1] == '*')
							{
								b++;
							}

							if (mas[rows - 2][1] == '*')
							{
								b++;
							}

							if (mas[rows - 2][0] == '*')
							{
								b++;
							}
							mas[rows - 1][0] = bombs(b);
						}

						///левая вертикаль
						if (i > 0 && i < rows - 1 && j == 0)
						{
							short b = 0;
							if (mas[i - 1][0] == '*')
							{
								b++;
							}

							if (mas[i - 1][1] == '*')
							{

							}

							if (mas[i][1] == '*')
							{
								b++;
							}

							if (mas[i + 1][1] == '*')
							{
								b++;
							}

							if (mas[i + 1][0] == '*')
							{
								b++;
							}
							mas[i][j] = bombs(b);
						}

						///правая вертикаль
						if (i > 0 && i < rows - 1 && j == columns - 1)
						{
							short b = 0;
							if (mas[i - 1][columns - 1] == '*')
							{
								b++;
							}

							if (mas[i - 1][columns - 2] == '*')
							{
								b++;
							}

							if (mas[i][columns - 2] == '*')
							{
								b++;
							}

							if (mas[i + 1][columns - 2] == '*')
							{
								b++;
							}
							if (mas[i + 1][columns - 1] == '*')
							{
								b++;
							}
							mas[i][j] = bombs(b);
						}

						///верхняя горизонталь
						if (i == 0 && j > 0 && j < columns - 1)
						{
							short b = 0;
							if (mas[i][j - 1] == '*')
							{
								b++;
							}

							if (mas[i + 1][j - 1] == '*')
							{
								b++;
							}

							if (mas[i + 1][j] == '*')
							{
								b++;
							}

							if (mas[i + 1][j + 1] == '*')
							{
								b++;
							}

							if (mas[i][j + 1] == '*')
							{
								b++;
							}
							mas[i][j] = bombs(b);
						}

						///нижняя горизонталь
						if (i == rows - 1 && j > 0 && j < columns - 1)
						{
							short b = 0;
							if (mas[i][j - 1] == '*')
							{
								b++;
							}

							if (mas[i - 1][j - 1] == '*')
							{
								b++;
							}

							if (mas[i - 1][j] == '*')
							{
								b++;
							}

							if (mas[i - 1][j + 1] == '*')
							{
								b++;
							}
							if (mas[i][j + 1] == '*')
							{
								b++;
							}
							mas[i][j] = bombs(b);
						}

						///центр
						if (i > 0 && i < rows - 1 && j > 0 && j < columns)
						{
							short b = 0;
							if (mas[i][j - 1] == '*')
							{
								b++;
							}

							if (mas[i - 1][j - 1] == '*')
							{
								b++;
							}

							if (mas[i - 1][j] == '*')
							{
								b++;
							}

							if (mas[i - 1][j + 1] == '*')
							{
								b++;
							}

							if (mas[i][j + 1] == '*')
							{
								b++;
							}

							if (mas[i + 1][j - 1] == '*')
							{
								b++;
							}

							if (mas[i + 1][j] == '*')
							{
								b++;
							}

							if (mas[i + 1][j + 1] == '*')
							{
								b++;
							}
							mas[i][j] = bombs(b);
						}
					}
				}
			}

		///вывод поля
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cout << mas[i][j] << " ";
			}
			std::cout << std::endl;
		}

		for (long long i = 0; i < rows; i++)
		{
			delete mas[i];
		}
		delete[] mas;

		n = NonStop();
	}
	return 0;
}

