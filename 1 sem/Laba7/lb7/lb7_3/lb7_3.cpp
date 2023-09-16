#include <iostream>
#include <string>

void reference3()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №3" << "\n\n";
    std::cout << "Суть задания такова: сложить и отнять числа в н системе исчисления" << "\n\n";
}

int NonStop()
{
    int a;
    std::cout << "\nПовторить?\n1. Да\n2. Нет\n\n";
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

std::string enterstring(int base)
{
    long long index = 0;
    std::string buff;
    const char* DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (true)
    {
        bool check = true;
        long times = 0;
        std::cout << "Введите вашу строку:\n";
        std::cin >> buff;
        while (times < buff.length())
        {
            if (times > base)
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

int enter()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 2 || a > 36 || std::cin.peek() == ' ')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "Некорректный ввод, введите снова:\n";
        }
    }
    return a;
}

std::string SUM(std::string num1, std::string num2, int base)
{
    char DIGITS[37] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    for (int i = base; i < 37; i++)
    {
        DIGITS[i] = '-';
    }
    std::string ans;
    int kost = 0;
    if (num1.length() > num2.length())
    {
        while (num2.length() != num1.length())
        {
            num2.insert(0, 1, '0');
        }
        num2.insert(0, 1, '0');
        num1.insert(0, 1, '0');

        for (int i = num2.length() - 1; i >= 0; i--)
        {
            if (num2[i] >= '0' && num2[i] <= '9' && num1[i] >= '0' && num1[i] <= '9')
            {
                int x = num2[i] - 48 + num1[i + num1.length() - num2.length()] - 48 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= '0' && num2[i] <= '9' && num1[i] >= 'A' && num1[i] <= 'Z')
            {
                int x = num2[i] - 55 + num1[i + num1.length() - num2.length()] - 48 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= 'A' && num2[i] <= 'Z' && num1[i] >= '0' && num1[i] <= '9')
            {
                int x = num2[i] - 48 + num1[i + num1.length() - num2.length()] - 55 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= 'A' && num2[i] <= 'Z' && num1[i] >= 'A' && num1[i] <= 'Z')
            {
                int x = num2[i] - 55 + num1[i + num1.length() - num2.length()] - 55 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
        }
    }
    else if (num1.length() < num2.length())
    {
        while (num2.length() != num1.length())
        {
            num1.insert(0, 1, '0');
        }
        num2.insert(0, 1, '0');
        num1.insert(0, 1, '0');
        for (int i = num2.length() - 1; i >= 0; i--)
        {
            if (num2[i] >= '0' && num2[i] <= '9' && num1[i] >= '0' && num1[i] <= '9')
            {
                int x = num2[i] - 48 + num1[i + num1.length() - num2.length()] - 48 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= '0' && num2[i] <= '9' and num1[i] >= 'A' && num1[i] <= 'Z')
            {
                int x = num2[i] - 55 + num1[i + num1.length() - num2.length()] - 48 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= 'A' and num2[i] <= 'Z' and num1[i] >= '0' and num1[i] <= '9')
            {
                int x = num2[i] - 48 + num1[i + num1.length() - num2.length()] - 55 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= 'A' and num2[i] <= 'Z' and num1[i] >= 'A' and num1[i] <= 'Z')
            {
                int x = num2[i] - 55 + num1[i + num1.length() - num2.length()] - 55 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
        }
    }
    else if (num1.length() == num2.length())
    {
        num2.insert(0, 1, '0');
        num1.insert(0, 1, '0');
        for (int i = num2.length() - 1; i >= 0; i--)
        {
            if (num2[i] >= '0' and num2[i] <= '9' and num1[i] >= '0' and num1[i] <= '9')
            {
                int x = num2[i] - 48 + num1[i + num1.length() - num2.length()] - 48 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= '0' and num2[i] <= '9' and num1[i] >= 'A' and num1[i] <= 'Z')
            {
                int x = num2[i] - 55 + num1[i + num1.length() - num2.length()] - 48 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= 'A' and num2[i] <= 'Z' and num1[i] >= '0' and num1[i] <= '9')
            {
                int x = num2[i] - 48 + num1[i + num1.length() - num2.length()] - 55 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
            else if (num2[i] >= 'A' and num2[i] <= 'Z' and num1[i] >= 'A' and num1[i] <= 'Z')
            {
                int x = num2[i] - 55 + num1[i + num1.length() - num2.length()] - 55 + kost;
                if (x < base)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 0;
                }
                else
                {
                    x -= base;
                    ans.insert(0, 1, DIGITS[x]);
                    kost = 1;
                }
            }
        }
    }

    if (ans[0] == '0')
    {
        ans.erase(0, 1);
    }
    return ans;
}

bool findMax(std::string num1, std::string num2)
{
    for (int i = 0; i < num1.length(); i++)
    {
        if (num1[i] != num2[i])
        {
            return (num1[i] > num2[i]);
            break;
        }
    }
    return 1;
}

std::string DIFF(std::string num1, std::string num2, int base)
{
    char DIGITS[37] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    for (int i = base; i < 37; i++)
    {
        DIGITS[i] = '-';
    }
    std::string ans;
    int k = 0;
    if (num1.length() >= num2.length())
    {
        while (num2.length() != num1.length())
        {
            num2.insert(0, 1, '0');
        }
        num2.insert(0, 1, '0');
        num1.insert(0, 1, '0');
        for (int i = num2.length() - 1; i >= 0; i--)
        {
            if (num2[i] >= '0' && num2[i] <= '9' && num1[i] >= '0' && num1[i] <= '9')
            {
                int x = (num2[i] - 48 - (num1[i + num1.length() - num2.length()] - 48) + k) * -1;
                if (x >= 0)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    k = 0;
                }
                else
                {
                    x += base;
                    ans.insert(0, 1, DIGITS[x]);
                    k = 1;
                }
            }
            else if (num2[i] >= '0' && num2[i] <= '9' && num1[i] >= 'A' && num1[i] <= 'Z')
            {
                int x = (num2[i] - 48 - (num1[i + num1.length() - num2.length()] - 55) + k) * -1;
                if (x >= 0)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    k = 0;
                }
                else
                {
                    x += base;
                    ans.insert(0, 1, DIGITS[x]);
                    k = 1;
                }
            }
            else if (num2[i] >= 'A' && num2[i] <= 'Z' && num1[i] >= '0' && num1[i] <= '9')
            {
                int x = (num2[i] - 55 - (num1[i + num1.length() - num2.length()] - 48) + k) * -1;
                if (x >= 0)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    k = 0;
                }
                else
                {
                    x += base;
                    ans.insert(0, 1, DIGITS[x]);
                    k = 1;
                }
            }
            else if (num2[i] >= 'A' && num2[i] <= 'Z' && num1[i] >= 'A' && num1[i] <= 'Z')
            {
                int x = (num2[i] - 55 - (num1[i + num1.length() - num2.length()] - 55) + k) * -1;
                if (x >= 0)
                {
                    ans.insert(0, 1, DIGITS[x]);
                    k = 0;
                }
                else
                {
                    x += base;
                    ans.insert(0, 1, DIGITS[x]);
                    k = 1;
                }
            }
        }
    }
    if (ans[0] == '0')
    {
        ans.erase(0, 1);
    }
    return ans;
}

void ans(std::string a1, std::string a2)
{
    if (a1[0] == '0')
    {
        a1.erase(0, 1);
    }
    if (a1[0] == '-' and a1[1] == '0')
    {
        a1.erase(1, 1);
    }
    if (a2[0] == '0')
    {
        a2.erase(0, 1);
    }
    if (a2[0] == '-' and a2[1] == '0')
    {
        a2.erase(1, 1);
    }

    std::cout << "Сумма двух чисел: " << a1 << "\n";
    std::cout << "Разность двух чисел: " << a2;
}


int main() // O(n) very very big const
{
    setlocale(LC_ALL, "russian");
    reference3();
    int count = 1;
    while (count)
    {
        int base;
        std::string ANS1, ANS2;
        std::cout << "Введите основание системы\n";
        base = enter();
        std::string NUM1 = enterstring(base);
        std::string NUM2 = enterstring(base);

        if (NUM1[0] == '-' && NUM2[0] == '-')
        {
            NUM1.erase(0, 1);
            NUM2.erase(0, 1);
            ANS1 = SUM(NUM1, NUM2, base);

            if (NUM1.length() > NUM2.length())
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans("-" + ANS1, "-" + ANS2);
            }
            else if (NUM1.length() < NUM2.length())
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans("-" + ANS1, ANS2);
            }
            else if (findMax(NUM1, NUM2))
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans("-" + ANS1, "-" + ANS2);
            }
            else
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans("-" + ANS1, ANS2);
            }
        }

        else if (NUM1[0] != '-' && NUM2[0] == '-')
        {
            NUM2.erase(0, 1);
            ANS1 = SUM(NUM1, NUM2, base);
            if (NUM1.length() > NUM2.length())
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans(ANS2, ANS1);
            }
            else if (NUM1.length() < NUM2.length())
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans("-" + ANS2, ANS1);
            }
            else if (findMax(NUM1, NUM2))
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans(ANS2, ANS1);
            }
            else
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans("-" + ANS2, ANS1);
            }
        }
        else if (NUM1[0] == '-' && NUM2[0] != '-')
        {
            NUM1.erase(0, 1);
            ANS1 = SUM(NUM1, NUM2, base);
            ANS1 = SUM(NUM1, NUM2, base);
            if (NUM1.length() > NUM2.length())
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans("-" + ANS2, "-" + ANS1);
            }
            else if (NUM1.length() < NUM2.length())
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans(ANS2, "-" + ANS1);
            }
            else if (findMax(NUM1, NUM2))
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans("-" + ANS2, "-" + ANS1);
            }
            else
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans(ANS2, "-" + ANS1);
            }
        }
        else
        {
            ANS1 = SUM(NUM1, NUM2, base);
            if (NUM1.length() > NUM2.length())
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans(ANS1, ANS2);
            }
            else if (NUM1.length() < NUM2.length())
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans(ANS1, "-" + ANS2);
            }
            else if (findMax(NUM1, NUM2))
            {
                ANS2 = DIFF(NUM1, NUM2, base);
                ans(ANS1, ANS2);
            }
            else
            {
                ANS2 = DIFF(NUM2, NUM1, base);
                ans(ANS1, "-" + ANS2);
            }
        }
        count = NonStop();
    }
    return 0;
}