#include <iostream>

void reference3()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание № 4" << "\n\n";
    std::cout << "Суть задания такова: найти максимальный элемент в вещественном массива и переставить его в верхний левый угол" << "\n\n";
    std::cout << "Пожалуйста,введите размер массива" << "\n\n";
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

int main()
{
    setlocale(LC_ALL, "Russian");
    reference3();
    int i, j, n1, m1;
    int n, m;
    n = enter();
    m = enter();
    double max, cur;
    double** mas = new double* [n];

    for (int i = 0; i < n; ++i)
    {
        mas[i] = new double[m];
    }

    std::cout << "Пожалуйста,введите ЦЕЛОЧИСЛЕННЫЕ или ВЕЩЕСТВЕННЫЕ элементы массива" << "\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            while (true)
            {
                std::cin >> mas[i][j];
                if (!std::cin)
                {
                    std::cout << "Некорректные значения. Повторите ввод\n";
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

    std::cout << "Вы ввели:" << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << mas[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    max = mas[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mas[i][j] > max)
            {
                max = mas[i][j];
                n1 = i, m1 = j;
            }
        }
    }

    std::cout << "Max = mas" << "[" << n << "][" << m << "] = " << max << std::endl;

    //обмен верхнего левого и найденного максимального элементов
    cur = mas[0][0];
    mas[0][0] = max;
    mas[n1][m1] = cur;

    std::cout << "Result:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << mas[i][j] << "\t";
        }

        std::cout << std::endl;
    }

    delete[] mas;
    return 0;
}
