#include <iostream>

void swap_numbers(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int fMax(int mas[], int razmer)
{
	int max = mas[0];
	for (int i = 0; i < razmer; i++)
	{

		if (max < mas[i])
		{
			max = mas[i];
		}
	}
	return max;
}

int fMin(int mas[], int razmer)
{
	int min = mas[0];
	for (int i = 0; i < razmer; i++)
	{
		if (min > mas[i])
		{
			min = mas[i];
		}
	}
	return min;
}

int NonStop()
{
	int a;
	std::cout << "���������?\n1. ��\n2. ���\n\n";

	while (!(std::cin >> a) || (std::cin.peek() != '\n') || (a != 1 && a != 2) || std::cin.peek() == ' ')
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "������������ ����, ���������� ����:\n";
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

int search_value(int a[], int size, int value)
{
	int position = -1;      // ���� value � ������� �� ��������, ������ -1
	for (int i = 0; i < size && position < 0; i++)
	{
		if (a[i] == value)
		{
			position = i;
		}
	}
	return position;
}

void print_array(int mas[], int size)
{
	std::cout << "Result:" << "\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << mas[i] << "\n";
	}
	std::cout << std::endl;
}

void enter_array(int mas[], int size)
{

	for (int i = 0; i < size; i++)
	{
		while (true)
		{
	
			std::cin >> mas[i];
			if (!std::cin)
			{
				std::cout << "������������ ��������. ��������� ����\n";
				std::cin.clear();
				while (std::cin.get() != '\n');
			}

			else
			{
				break;
			}
			
		}
	}
}

void reference1()
{
	std::cout << "���� ����� ������ �������� � � �������� ������� � 1" << "\n\n";
	std::cout << "���� ������� ������: ����� � �������� ������� ������������ � ����������� ������� �������" << "\n\n";
	std::cout << "����������,������� ������������� �������� �������" << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	reference1();
	int n = 1;
	while (n)
	{
		const int k = 5;
		int mas[k];

		enter_array(mas, k);

		int min, max;

		max = fMax(mas, k);
		min = fMin(mas, k);
	
		std::cout << "MIN: " << min << " " << "MAX: " << max << "\n";

		int min_pos = search_value(mas, k, min);  // ������� ������� ����� � �������
		int max_pos = search_value(mas, k, max);

		if (min_pos >= 0 && max_pos >= 0 && min_pos != max_pos) // ������ �������
		{
			swap_numbers(&mas[min_pos], &mas[max_pos]);
		}

		print_array(mas, k);

		n = NonStop();
	}
	return 0;
}