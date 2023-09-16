#include <iostream>
#include <string>
#include <cmath>

long long reversetodec(std::string NUMBER) 
{
    long long result = 0;
    for (long long i = NUMBER.length() - 1; i >= 0; i--)
    {
        if (NUMBER[i] == '1')
        {
            result += pow(2, i);
        }
    }

    if (NUMBER[NUMBER.length()] == '1')
    {
        result = 0 - result;
    }

    return result;
}

void reference1()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №1" << "\n\n";
    std::cout << "Суть задания такова: перевести из обратного в десятичный" << "\n\n";
}

std::string enterbin()
{
    long long index = 0, dlina = 0;
    std::string buff;
    std::string sign = "-";

    while (true)
    {
        bool check = true;
        long times = 0;
        std::cout << "Введите вашу строку из 0 и 1:\n";
        std::cin >> buff;
        while (times < buff.length())
        {
            if (buff[times] != '0' && buff[times] != '1')
            {
                check = false;
                break;
            }
            times++;
        }
        if (check)
        {
            break;
        }
        std::cout << "Некорректный ввод, попробуйте снова!\a\n";
    }
    return buff;
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

int main() // O(n) + normal const
{
    setlocale(LC_ALL, "Russian");
    reference1();
    int count = 1;
    while (count)
    {
        std::string NUMBER = enterbin();

        std::cout << reversetodec(NUMBER) << "\n";
        count = NonStop();
    }
}
