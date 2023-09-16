#include <iostream> 

void reference4()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №4\n";
    std::cout << "Суть задания: найти нулевые элементы и вывести массив в обратном порядке\n";
}

void solve(long double* mas[], int* size1, int* size2)
{
    long double sum = 0, k = 0, counter = 0;
    std::cout << "индексы : \n";

    for (int i = 0; i < *size1; i++) 
    {
        for (int j = 0; j < *size2; j++) 
        {
            if (mas[i][j] == 0) 
            {
                std::cout << "mas[" << i << "]" << "[" << j << "]" << std::endl;
                counter++;
            }
        }
    }

    std::cout << "общее количество индексов - " << counter << std::endl;

    for (int i = *size2 - 1; i >= 0; --i) 
    {
        std::cout << std::endl;

        for (int j = *size1 - 1; j >= 0; --j) 
        {
            std::cout << mas[i][j] << "\t";
        }
    }
}

void destructor_x2(long double** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] mas[i];
    }
    delete[] mas;
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

long double** create_din_matrix(int size1, int size2)
{
    long double** mas = new long double* [size1];
    for (int i = 0; i < size1; i++)
    {
        mas[i] = new long double[size2];
    }

    return mas;
}

void print_din_matrix(long double** mas, int size1, int size2)
{
    for (int i = 0; i < size1; i++) 
    {
        std::cout << std::endl;
        for (int j = 0; j < size2; j++) 
        {
            std::cout << mas[i][j] << "\t";
        }
    }
}

long double** initialize_matrix(long double** mas, int size1, int size2)
{
    std::cout << "Введите элементы массива\n";
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            mas[i][j] = enter();  // check
        }
    }
    return mas;
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

int main()
{
    setlocale(0, "");
    reference4();

    int count = 1;

    while (count)
    {
        std::cout << "Введите размеры массива\n";
        int size1 = enter();
        int size2 = enter();

        long double** mas1 = create_din_matrix(size1, size2);

        mas1 = initialize_matrix(mas1, size1, size2);

        print_din_matrix(mas1, size1, size2);

        solve(mas1, &size1, &size2);

        destructor_x2(mas1, size1);

        count = NonStop();
    } 
    return 0;
}