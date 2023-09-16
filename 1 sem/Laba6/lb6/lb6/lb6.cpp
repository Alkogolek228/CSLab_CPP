#include <iostream>

int max(char *str)
{
    int len, maxlen;
    for (int i = 1, len = maxlen = 1; str[i]; i++)
    {
        if (str[i] == str[i - 1])
        {
            len++;
            maxlen = len > maxlen ? len : maxlen;
        }

        else
        {
            len = 1;
        }
    }
    return maxlen;
}

void reference1()
{
    std::cout << "Меня зовут Данила Альховик и выполнил задание №1\n";
    std::cout << "В строке, состоящей из групп нулей и единиц, подсчитать количество символов в самой длинной группе\n";
    std::cout << "Введите строку:\n";
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
        setlocale(LC_ALL, "Russian");
        reference1();
        char* str = new char[80];
        char ch;
        int count = 1, i;
        while (count)
        {

            i = 0;
            while ((ch = getchar()) != '\n' && i < 80 - 1)
            {
                if ((ch == '1' || ch == '0') && !isalpha(ch))  
                {
                    str[i] = ch;
                    i++;
                }
            }

            str[i] = '\0';

            std::cout << max(str);
            count = NonStop();
        }

        delete[] str;
        return 0;
}

