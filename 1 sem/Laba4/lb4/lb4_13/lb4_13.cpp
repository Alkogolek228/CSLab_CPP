#include <iostream>
#include <cmath>

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

int NonStop() 
{
    int a;
    std::cout << "Повторить?\n1. Да\n2. Нет\n\n";
    while (!(std::cin >> a) || (std::cin.peek() != '\n') || (a != 1 && a != 2) || std::cin.peek() == ' ')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "Некорректный ввод, введите снова:\n";
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

void reference13()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание № 13" << "\n\n";
    std::cout << "Суть задания такова: написать магический квадрат" << "\n\n";
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int count = 1;
    reference13(); 

    while (count)
    {
        std::cout << "Введите порядок квадрата: ";
        int n = enter();

        if (n == 2)
        {
            std::cout << "Магического квадрата заданного размера не существует.\n";
            count = NonStop();
        }

        else if ((n - 2) % 4 == 0)
        {
            unsigned int** mas = (unsigned int**)malloc(n * sizeof(unsigned int*));

            for (int i = 0; i < n; i++) 
            {
                mas[i] = (unsigned int*)malloc(n * sizeof(unsigned int));
            }

            int k = ((n - 2) / 4), nomer = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i][j] = -2;
                }
            }
                   
            for (int i = 0; i < n; i++)
            {
                mas[i][i] = -1;
                mas[i][n - 1 - i] = -1;
            }

            for (int i = 0; i < 2 * k; i++)
            {
                for (int j = i; j < 2 * k; j++)
                {
                    mas[i][j + 1] = -3;
                    mas[i][n - j - 2] = -3;
                    mas[n - 1 - i][j + 1] = -3;
                    mas[n - 1 - i][n - j - 2] = -3;
                }
            }

            for (int i = 0; i < k + 1; i++)
            {
                for (int j = i; j < 2 * k + 1 - i; j++)
                {
                    mas[k + j][i] = -4;
                    mas[k + j][n - 1 - i] = -4;
                    mas[i][k + j] = -4;
                    mas[n - 1 - i][k + j] = -4;
                }
            }

            for (int i = 0; i < k; i++)
            {
                for (int j = i; j < k; j++)
                {
                    mas[k + 1 + j][i] = -3;
                    mas[n - k - 2 - j][i] = -3;
                    mas[i][k + 1 + j] = -2;
                    mas[i][n - k - 2 - j] = -2;
                }
            }

            for (int i = 0; i < k - 1; i++)
            {
                for (int j = i; j < k - 1; j++)
                {
                    mas[k + 2 + j][n - 1 - i] = -3;
                    mas[n - k - 3 - j][n - 1 - i] = -3;
                    mas[n - 1 - i][k + 2 + j] = -2;
                    mas[n - 1 - i][n - k - 3 - j] = -2;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    nomer++;
                    if (mas[j][i] == -1)
                    {
                        mas[j][i] = nomer;
                    }
                    
                    if (mas[n - 1 - j][i] == -2)
                    {
                        mas[n - 1 - j][i] = nomer;
                    }

                    if (mas[j][n - 1 - i] == -3)
                    {
                        mas[j][n - 1 - i] = nomer;
                    }

                    if (mas[n - 1 - j][n - 1 - i] == -4)
                    {
                        mas[n - 1 - j][n - 1 - i] = nomer;
                    }
                }
            }

            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << mas[i][j] << '\t';
                }

                std::cout << '\n';
            }

            for (int i = 0; i < n; i++)
            {
                free(mas[i]);
            }
            free(mas);
        }

        else if (n % 2 == 1)
        {
            unsigned int** mas = (unsigned int**)calloc(n, sizeof(unsigned int*));

            for (int i = 0; i < n; i++) 
            {
                mas[i] = (unsigned int*)calloc(n, sizeof(unsigned int));
            }

            unsigned int X = 0, Y = n / 2;
            mas[X][Y] = 1;

            for (unsigned int i = 2; i <= n * n; i++)
            { 
                if (X == 0 && Y == n - 1)
                {
                    X += 1;
                }

                else if (X == 0 && Y != n - 1)
                {
                    Y += 1;
                    X = n - 1;
                }

                else if (X != 0 && Y == n - 1)
                {
                    X -= 1;
                    Y = 0;
                }

                else if (mas[X - 1][Y + 1] != 0)
                {
                    X += 1;
                }

                else
                {
                    X -= 1;
                    Y += 1;
                }
                mas[X][Y] = i;
            }


            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << mas[i][j] << '\t';
                }

                std::cout << '\n';
            }

            for (int i = 0; i < n; i++)
            {
                free(mas[i]);
            }
            free(mas);
        }

        else if (n % 4 == 0)
        {
            unsigned int** mas = (unsigned int**)malloc(n * sizeof(unsigned int*));

            for (int i = 0; i < n; i++) 
            {
                mas[i] = (unsigned int*)malloc(n * sizeof(unsigned int));
            }

            int k = n / 4, nomer = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i][j] = i * n + j + 1;
                }
            }
                
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    for (int g = 0; g < 4; g++)
                    {
                        mas[4 * i + g][(j * 4) + g] = 0;
                        mas[(i + 1) * 4 - g - 1][(j * 4) + g] = 0;
                    }
                }
            }
                
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    nomer++;
                    if (mas[i][j] == 0)
                    {
                        mas[i][j] = nomer;
                    }   
                }
            }
                
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << mas[i][j] << '\t';
                }
                    
                std::cout << '\n';
            }
            for (int i = 0; i < n; i++)
            {
                free(mas[i]);
            }
                
            free(mas);
        }
        count = NonStop();
    }
    return 0;
}