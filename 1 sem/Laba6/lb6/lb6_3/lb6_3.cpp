#include <iostream>
#include <conio.h>
#include <stdio.h>

char** createtext(int size)
{
	char** str = new char* [size];
	for (int i = 0; i < size; i++)
	{
		str[i] = new char[81];
	}
	return str;
}

char** entertext(int size, char** str)
{
	char x = getchar();
	while (x != '\n')
	{
		x = getchar();
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << "Введите строку (" << i + 1 << ") : ";
		char a;
		int j = 0;
		while (j < 80)
		{
			a = getchar();
			if (a != '\n')
			{
				str[i][j] = a;
			}
			else
			{
				break;
			}
			j++;
		}
		str[i][j] = '\0';
		while (a != '\n')
		{
			a = getchar();
		}
	}
	return str;
}

void counter(int n, char **str)
{
	int i, j, sr = 0, z = 0, m = 0;
	for (i = 0; i < n; i++)
	{
		j = 1;

		while (str[i][j] != '\0')
		{
			if ((str[i][j - 1] == 'o' && str[i][j] == ' ') || (str[i][j] == 'o' && str[i][j + 1] == '\0'))
			{
				sr++;
			}

			else if (((str[i][j - 1] == 'a' || str[i][j - 1] == 'e') && str[i][j] == ' ') || (str[i][j + 1] == '\0' && (str[i][j] == 'a' || str[i][j] == 'e')))
			{
				z++;
			}

			else if (str[i][j] == ' ' || str[i][j + 1] == '\0')
			{
				m++;
			}

			j++;
		}
	}

	std::cout << "Результат:\n";
	std::cout << "Средний род: " << sr << " раз\n";
	std::cout << "Мужской род: " << m << " раз\n";
	std::cout << "Женский род: " << z << " раз\n";
}

int NonStop()
{
	int a;
	std::cout << "\nПовторить?\n1. Да\n2. Нет\n\n";
	while (scanf_s("%d", &a) != 1 || a < INT_MIN || a > INT_MAX || getchar() != '\n' || a != 1 && a != 2)
	{
		printf("Error\n");
		rewind(stdin);
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

int enter()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0 || std::cin.peek() == ' ')
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "Некорректный ввод, введите снова:\n";
		}
	}
	return a;
}

void reference3()
{
	std::cout << "Меня зовут Данила Альховик и выполнил задание №3\n";
	std::cout << "Суть задания: посчиать кол-во слов мужского, женского и среднего родов в тексте\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, n, j;
	int sr = 0, m = 0, z = 0, count = 1;
	while(count)
	{
		std::cout << "Введите кол-во строк:\n";
		n = enter();

		char** str = createtext(n);
		str = entertext(n, str);

		counter(n, str);
		count = NonStop();
	}
	return 0;
}