#include <iostream>
#include <string>

void reference2()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №3" << "\n\n";
    std::cout << "Суть задания такова: сложение  в обратном коде. Ответ выразите в естественной форме." << "\n\n";
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

std::string tobin(int n)
{
    std::string BiCod;
    if (n < 0)
    {
        BiCod.insert(0, 1, '1');
    }

    else
    {
        BiCod.insert(0, 1, '0');
    }

    if (n < 0)
    {
        n = n * -1;
    }

    while (n)
    {
        if (n % 2 == 1)
        {
            BiCod.insert(1, 1, '1');
        }

        else
        {
            BiCod.insert(1, 1, '0');
        }

        n = n / 2;
    }

    while (BiCod.length() != 9)
    {
        BiCod.insert(1, 1, '0');
    }
    return BiCod;
}
std::string sum(const std::string s1, const std::string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    std::string ls1 = len1 < len2 ? s1 : s2;
    std::string ls2 = len1 < len2 ? s2 : s1;
    for (int i = ls1.size(); i < ls2.size(); ++i)
    {
        ls1 = '0' + ls1;
    }
    std::string result;
    int carry = 0;
    for (int i = ls2.size() - 1; i >= 0; --i) 
    {
        int bit1 = ls1.at(i) - '0';
        int bit2 = ls2.at(i) - '0';
        char sum = (bit1 ^ bit2 ^ carry) + '0';
        result = sum + result;
        carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
    }
    if (carry)
    {
        result = '1' + result;
    }
    return result;
}
int todec(int res)
{
    int i = 0, digitT = res, rest = 1;
    while (digitT >= 1 and rest <= 1)
    {
        rest = digitT % 10;
        digitT = digitT / 10;
        i++;
    }
    int two = 1, sum = 0;
    digitT = res;
    if (rest > 1)
    {
        std::cout << "Это не двоичная система счисления!";
    }
    else
    {
        while (i > 0)
        {
            rest = digitT % 10;
            digitT = digitT / 10;
            sum = sum + rest * two;
            two = two * 2;
            i = i - 1;
        }
    }
    return sum;
}
std::string revers(std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            str[i] = '1';
        }
        else
        {
            str[i] = '0';
        }
    }
    return str;
}

void toreverce(int num1, std::string ObCod, std::string ans1, std::string BiNum1)
{
    if (num1 < 0)
    {
        ObCod = ans1;
        ObCod[0] = '1';
        int l = ObCod.length();
        for (int i = 1; i < l; i++)
        {
            if (ObCod[i] == '1')
            {
                ObCod[i] = '0';
            }
            else
            {
                ObCod[i] = '1';
            }
        }
        std::cout << ObCod << "\n";
        BiNum1 = ObCod;
    }
    else
    {
        std::cout << ans1 << "\n";
        BiNum1 = ans1;
    }
}

int enter()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0 || std::cin.peek() == ' ')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "Некорректный ввод, введите снова:\n";
        }
    }
    return a;
}


int main() // O(n) + big const
{
    setlocale(LC_ALL, "russian");
    reference2();
    int count = 1;
    while (count)
    {
        int num1 = 0, num2 = 0, resdec = 0, findec = 0;
        std::string ans1, ans2, ObCod, BiNum1, BiNum2, res;
        std::cout << "Введите число 1: " << "\n";
        num1 = enter();
        std::cout << "Введите число 2: " << "\n";
        num2 = enter();

        ans1 = tobin(num1);
        ans2 = tobin(num2);

        std::cout << "Двоичный вид числа 1: " << "\n";
        std::cout << ans1;

        std::cout << "Двоичный вид числа 2: " << "\n";
        std::cout << ans2;

        std::cout << "Перевод в обратный код числа 1: " << "\n";
        toreverce(num1, ObCod, ans1, BiNum1);

        std::cout << "Перевод в обратный код числа 2: " << "\n";
        toreverce(num2, ObCod, ans2, BiNum2);

        if (num1 < 0 || num2 < 0)
        {
            res = sum(BiNum1, BiNum2);
            res = revers(res);
        }
        else
        {
            res = sum(BiNum1, BiNum2);
        }
        std::cout << "Сумма двоичных чисел: " << res << "\n";
        resdec = stoll(res);
        findec = todec(resdec);
        std::cout << "Сумма двоичных чисел (в естественной форме): " << "\n";
        if (num1 - num2 < 0 || num2 - num1 < 0)
        {
            std::cout << -1 * findec << "\n";
        }
        else
        {
            std::cout << findec << "\n";
        }
        count = NonStop();
    }
    return 0;
}