#include <iostream>

void reference1()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №1\n";
    std::cout << "Суть задания: создать матрицу с заданными элементами и посчитать сумму периметра\n";
}

int** create_din_matrix(int size)
{
    int** mas = (int**)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++)
    {
        mas[i] = (int*)malloc(size * sizeof(int));
    }
    return mas;
}

int** initialize_matrix1(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i <= 5)
            {
                mas[i][j] = 3 * i * j - 3;
            }

            else if (i > 5)
            {
                mas[i][j] = 2 * i * j - 2;
            }
        }
    }
    return mas;
}

int** initialize_matrix2(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i > 7)
            {
                mas[i][j] = 4 * i * j - 5;
            }

            else if (i <= 7)
            {
                mas[i][j] = 5 * i * j - 4;
            }
        }
    }
    return mas;
}

void print_matrixsum(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << mas[i][j] << "\t";
        }
        std::cout << '\n';
    }

    int s = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (((i == 0) || (i == size - 1)) || ((j == 0) || (j == size - 1)))
            {
                s += mas[i][j];
            }
        }
    }

    std::cout << "Sum = " << s << '\n';
}

int NonStop()
{
    int a;
    std::cout << "\nПовторить?\n1. Да\n2. Нет\n\n";
    while (scanf_s("%d", &a) != 1 || a < INT_MIN || a > INT_MAX || getchar() != '\n' || a != 1 && a != 2)     //проверка на ввод и ввод числа инт
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
    int x;
    while (scanf_s("%d", &x) != 1 || x < INT_MIN || x > INT_MAX || getchar() != '\n')    //проверка на ввод и ввод числа инт
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}