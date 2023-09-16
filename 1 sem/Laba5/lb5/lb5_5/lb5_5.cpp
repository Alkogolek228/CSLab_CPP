#include <iostream> 

void reference5()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №5\n";
    std::cout << "Суть задания: Создать динамический массив из элементов,  расположенных в четных столбцах данного массива и имеющих нечетное значение.Вычислить среднее арифметическое элементов динамическогомассива\n";
}

void solve(int* mas[], int* size1, int* size2) 
{
    int n = *(size1), m = *(size2), sum = 0, k = 0;
    int** arr1 = new int* [n]();

    for (int i = 0; i < n; i++) 
    {
        arr1[i] = new int[m]();
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 1; j < m; j += 2) 
        {
            if (mas[i][j] % 2 != 0) 
            {
                arr1[i][j] = mas[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (arr1[i][j] != 0)
            {
                sum += arr1[i][j];
                k++;
            }
        }
    }
    if (k == 0) 
    {
        std::cout << "0";
    }

    else 
    {
        std::cout << (long double)(sum / k);
    }

    for (int i = 0; i < *(size1); i++)
    {
        delete[] arr1[i];
    }
    delete[] arr1;

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

int enter()
{
    long double a;
    while (scanf_s("%d", &a) != 1 || a < LLONG_MIN || a > LLONG_MAX || getchar() != '\n')    //проверка на ввод и ввод числа инт
    {
        printf("Error\n");
        rewind(stdin);
    }
    return a;
}

int** initialize_matrix(int** mas, int size1, int size2)
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

int main()
{
    setlocale(0, "");
    reference5();
    int count = 1;
    while (count)
    {
        std::cout << "Введите размеры массива\n";
        int size1 = enter();
        int size2 = enter();

        int** mas = create_din_matrix(size1, size2);

        mas = initialize_matrix(mas, size1, size2);

        solve(mas, &size1, &size2);

        destructor_x2(mas, size1);

        count = NonStop();
    }
    return 0;
}