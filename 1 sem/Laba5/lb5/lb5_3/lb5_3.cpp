#include <iostream>

void reference3()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №3\n";
    std::cout << "Суть задания: Создать динамический массив из элементов, расположенных на главной диагонали матрицы и имеющих четное значение. Вычислить произведение элементов динамического массива\n";
}

void print_din_array(int mas[], int size)
{
    std::cout << "Вы ввели массив:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << mas[i] << " ";
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

void destructor_x2(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] mas[i];
    }
    delete[] mas;
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

int** create_din_matrix(int size1, int size2)
{
    int** mas = new int* [size1];
    for (int i = 0; i < size1; i++)
    {
        mas[i] = new int[size2];
    }

    return mas;
}

int** initialize_matrix(int** mas, int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            mas[i][j] = enter();
        }
    }
    return mas;
}

int* create_din_array(int size)
{
    int* mas = new int[size];

    return mas;
}

int main()
{
    long long int gran, size1, size2, ans = 0, j = 0;
    bool tr = false;
    setlocale(LC_ALL, "rus");
    reference3();

    int count = 1;

    while (count)
    {
        std::cout << "Введите size1, size2: ";

        size1 = enter();
        size2 = enter();

        int** mas1 = create_din_matrix(size1, size2);
        mas1 = initialize_matrix(mas1, size1, size2);
        int* mas2 = create_din_array(size2);

        gran = size2;

        if (size2 > size1)
        {
            int* mas2 = create_din_array(size2 - size1);
            gran = size1;
        }

        for (int i = 0; i < gran; i++)
        {
            if (mas1[i][i] % 2 == 0)
            {
                tr = true;
                mas2[j] = mas1[i][i];
                if (ans != 0)
                {
                    ans *= mas2[j];
                }

                else
                {
                    ans = mas2[j];
                }
                j++;
            }
        }

        if (tr)
        {
            std::cout << "Элементы диагонали: \n";
            print_din_array(mas2, j);
            std::cout << "\n" << "Произведение элементов: " << ans;
        }

        else
        {
            std::cout << "Четных элементов не найдено.";
        }

        destructor_x2(mas1, size1);
        delete[] mas2;
        count = NonStop();
    }
    return 0;
}