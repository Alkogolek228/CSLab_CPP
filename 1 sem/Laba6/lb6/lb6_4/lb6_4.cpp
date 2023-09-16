#include <iostream>
#include <string>

std::string change(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] == 'q' || str[i] == 'Q') && (str[i + 1] == 'u' || str[i + 1] == 'U'))
        {
            if (isupper(str[i]))
            {
                str[i] = 'K';
                str[i + 1] = 'v';
            }

            else
            {
                str[i] = 'k';
                str[i + 1] = 'v';
            }
        }

        if ((str[i] == 'c' || str[i] == 'C') && (str[i + 1] == 'e'|| str[i + 1] == 'E' || str[i + 1] == 'i' || str[i + 1] == 'I' || str[i + 1] == 'y' || str[i + 1] == 'Y'))
        {
            if (isupper(str[i]))
            {
                str[i] = 'S';
            }

            else
            {
                str[i] = 's';
            }
            
        }

        else if (str[i] == 'c' || str[i] == 'C')
        {
            if (isupper(str[i]))
            {
                str[i] = 'K';
            }

            else
            {
                str[i] = 'k';
            }
           
        }

        if (str[i] == 'q' || str[i] == 'Q')
        {
            if (isupper(str[i]))
            {
                str[i] = 'K';
            }
           
            else
            {
                str[i] = 'k';
            }
        }

        if (str[i] == 'w' || str[i] == 'W')
        {
            if (isupper(str[i]))
            {
                str[i] = 'V';
            }
            
            else
            {
                str[i] = 'v';
            }
        }

        if (tolower(str[i]) == tolower(str[i + 1]) && (str[i] == 'k' || str[i] == 'r' || str[i] == 't' || str[i] == 'p' || str[i] == 's' || str[i] == 'd' || str[i] == 'f' || str[i] == 'g' || str[i] == 'h' || str[i] == 'j' || str[i] == 'l' || str[i] == 'z' || str[i] == 'v' || str[i] == 'b' || str[i] == 'n' || str[i] == 'm'))
        {
            str.erase(i + 1, 1);
        }

        if (toupper(str[i]) == toupper(str[i + 1]) && (str[i] == 'K' || str[i] == 'R' || str[i] == 'T' || str[i] == 'P' || str[i] == 'S' || str[i] == 'D' || str[i] == 'F' || str[i] == 'G' || str[i] == 'H' || str[i] == 'J' || str[i] == 'L' || str[i] == 'Z' || str[i] == 'V' || str[i] == 'B' || str[i] == 'N' || str[i] == 'M'))
        {
            str.erase(i + 1, 1);
        }
        
        if (str[i] == str[i + 1] && (str[i] == 'e' || str[i] == 'E') || str[i] == 'E' && str[i + 1] == 'e' || str[i] == 'e' && str[i + 1] == 'E')
        {
            if (isupper(str[i]))
            {
                str[i] = 'I';
            }

            else
            {
                str[i] = 'i';
            }

            str.erase(i + 1, 1);
        }

        if (str[i] == str[i + 1] && (str[i] == 'o' || str[i] == 'O') || str[i] == 'O' && str[i + 1] == 'o' || str[i] == 'o' && str[i + 1] == 'O')
        {
            if (isupper(str[i]))
            {
                str[i] = 'U';
            }

            else
            {
                str[i] = 'u';
            }

            str.erase(i + 1, 1);
        }

        if (str[i] == 'p' || str[i] == 'P' && (str[i + 1] == 'h' || str[i + 1] == 'H'))
        {
            if (isupper(str[i]))
            {
                str[i] = 'F';
            }

            else
            {
                str[i] = 'f';
            }
           
            str.erase(i + 1, 1);
        }

        if ((str[i] == 't' || str[i] == 'T') && (str[i + 1] == 'h' || str[i + 1] == 'H'))
        {
            if (isupper(str[i]))
            {
                str[i] = 'Z';
            }

            else
            {
                str[i] = 'z';
            }

            str.erase(i + 1, 1);
        }

         if (str[i] == 'y' || str[i] == 'Y' && (str[i + 1] == 'o' || str[i + 1] == 'O' && str[i + 2] == 'u' || str[i + 2] == 'U'))
         {
             if (isupper(str[i]))
             {
                 str[i] = 'U';
             }

             else
             {
                 str[i] = 'u';
             }

             str.erase(i + 1, 2);
         }

        if (str[i] == 'x' || str[i] == 'X')
        {
            if (isupper(str[i]))
            {
                str[i] = 'K';
            }

            else
            {
                str[i] = 'k';
            }
            
            str.insert(i + 1, "s");
        }
    }

    return str;
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

void reference4()
{
    std::cout << "Меня зовут Данила Альховик и выполнил задание №4\n";
    std::cout << "Суть задания: провести реформу английского языка\n";
    std::cout << "Введите строку:\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    reference4();
    std::string str, str_buff;
    int count = 1;
    while (count)
    {
        std::getline(std::cin, str);

        for (int a = 0; a < str.length(); a++)
        {
            if (isdigit(str[a]) || str[a] == '*' || str[a] == '@' || str[a] == '#' || str[a] == '$' || str[a] == '%' || str[a] == '^' || str[a] == '<' || str[a] == '>' || str[a] == '(' || str[a] == ')' || str[a] == '-' || str[a] == '_' || str[a] == '=' || str[a] == '+' || str[a] == '{' || str[a] == '}' || str[a] == '[' || str[a] == ']' || str[a] == '&' || str[a] == '~' || str[a] == '`')
            {
                str.erase(a, 1);
            }
        }
        do
        {
            str_buff = str;
            str = change(str);
        } while (str != str_buff);

        std::cout << str;

        count = NonStop();
    }
}
 
