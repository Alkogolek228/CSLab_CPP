#include <iostream>
#include <string>

void reference9()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №9" << "\n\n";
    std::cout << "Суть задания такова: найти отравленную бочку" << "\n\n";
}

std::string dectoany(long long number, const unsigned int& base)
{
    const char* DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
    bool flag_of_inversion = false;
    std::string reversString, stringInBase;

    stringInBase += DIGITS[number % base];
    number = number / base;

    while (number)
    {
        stringInBase += DIGITS[number % base];
        number = number / base;
    }

    if (flag_of_inversion == true)
    {
        reversString = "1";
    }

    for (int i = stringInBase.length() - 1; i >= 0; i--)
    {
        reversString += stringInBase[i];
    }

    return reversString;
}

void repair(std::string &NUMBER)
{
    while (NUMBER.length() < 5)
    {
        NUMBER.insert(0, 1, '0');
    }
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

int enter()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0 || a > 240 || std::cin.peek() == ' ')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "Некорректный ввод, введите снова:\n";
        }
    }
    return a;
}

int main() // O(n*k) + const
{
    setlocale(LC_ALL, "Russian");
    int count = 1;
    while (count)
    {
        reference9();
        std::string slave = "XXXXX", k;
        int barrel, dead[5] = { 0,0,0,0,0 };
        std::cout << "Ввелите номер отравленной бочки\n";
        barrel = enter();

        for (int i = 1; i < 241; i++)
        {
            k = dectoany(i, 3);
            repair(k);
            for (int j = 0; j < 5; j++)
            {
                if (k[j] == '1' && i == barrel)
                {
                    slave[j] = '1';
                    dead[j] = 1;
                }
            }
        }

        for (int i = 1; i < 241; i++)
        {
            k = dectoany(i, 3);
            repair(k);
            for (int j = 0; j < 5; j++)
            {
                if (k[j] == '2' && i == barrel && dead[j] != 1)
                {
                    slave[j] = '2';
                }
            }
        }

        std::cout << slave << "\n";

        for (int i = 0; i < 5; i++)
        {
            if (slave[i] == 'X')
            {
                slave[i] = '0';
            }
        }

        std::cout << slave << "\n";

        int c0 = slave[0] - 48;
        int c1 = slave[1] - 48;
        int c2 = slave[2] - 48;
        int c3 = slave[3] - 48;
        int c4 = slave[4] - 48;

        int result = c0 * 81 + c1 * 27 + c2 * 9 + c3 * 3 + 1 * c4;

        std::cout << "отравленная бочка:" << result;
        count = NonStop();
    }
}
