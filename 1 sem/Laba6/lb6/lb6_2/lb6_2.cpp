#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

void solve(char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        { // если буква
            str[i] = tolower(str[i]); // преобразовываем к нижнему регистру (вдруг там большая буква)
            printf(" %d", str[i] - 'a' + 1); // 'a' имеет код 97, значит (буква-97+1) получим номер буквы в алфавите
        }
    }
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

void reference2()
{
    std::cout << "Меня зовут Данила Альховик и выполнил задание №2\n";
    std::cout << "Суть задания: в тексте каждую букву заменить ее номером в алфавите\n";
    std::cout << "Введите строку:\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    reference2();
    char* str = new char[80];
    int count = 1, i;
    char ch;
    while (count)
    {
        i = 0;
        while ((ch = getchar()) != '\n' && i < 80 - 1)
        {
            if (isalpha(ch))
            {
                str[i] = ch;
                i++;
            }
        }

        str[i] = '\0';

        solve(str);

        printf("\r\n");
        count = NonStop();
    }

    return 0;
}
