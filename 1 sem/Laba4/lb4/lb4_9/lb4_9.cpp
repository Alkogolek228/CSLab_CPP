#include <iostream>
#include <ctime> 

int enter()
{
    srand(time(NULL));
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0 || a == 0)
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

void reference9()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание № 9" << "\n\n";
    std::cout << "Суть задания такова: Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел." << "\n\n";
    std::cout << "Необходимо определить диагональ с наибольшейсуммой чисел. Для обхода диагоналей нельзя использовать вложенные циклы" << "\n\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    reference9();
    int n = 1;
    while (n) 
    {
        int size, d1 = 0, d2 = 0, d3 = 0, d4 = 0;
        std::cout << "Введите размер массива: ";
        size = enter();

        int*** mas = (int***)malloc(size * sizeof(int**));
        for (int i = 0; i < size; i++) 
        {
            mas[i] = (int**)malloc(size * sizeof(int*));

            for (int j = 0; j < size; j++)
            {
                mas[i][j] = (int*)malloc(size * sizeof(int));
            }
        }

        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                for (int k = 0; k < size; k++) 
                {
                    std::cout << "Введите " << i * size * size + j * size + k + 1 << "-й элемент массива:\n";
                    mas[i][j][k] = enter();
                   /* mas[i][j][k] = rand() % 50;*/
                }
            }
        }

        for (int i = 0; i < size; i++) 
        {
            d1 += mas[i][i][i];
            d2 += mas[size - i - 1][i][i];
            d3 += mas[i][size - i - 1][i];
            d4 += mas[size - i - 1][size - i - 1][i];
        }

        std::cout << '\n' << "Наибольшая сумма элементов диагонали: " << std::max(std::max(d1, d2), std::max(d3, d4)) << "\n\n";

        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++)
            {
                free(mas[i][j]);
            }
            free(mas[i]);
        }

        free(mas);

        n = NonStop();
    }

    return 0;
}