#include <iostream>
#include <string>

long long checkpalindrom(std::string str)
{
    long long same = 0;

    for (int i = 0; i < (str.size() / 2); i++)
    {
        if (str[i] == str[str.size() - (i + 1)])
        {
            same++;
        }
    }
    return same;
}

long long checkstring(std::string str)
{
    long long same = 0;

    for (int i = 0; i < (str.size()); i++)
    {
        if (str[0] == str[str.size() - (i + 1)])
        {
            same++;
        }
    }
    return same;
}

int main()
{
    std::string str;
    std::cin >> str;

    long long count1 = checkpalindrom(str);
    long long count2 = checkstring(str);
    long long answer = str.size() - 1;

    if (count2 == str.size())
    {
        std::cout << "-1";
        return 0;
    }

    if (count1 == str.size() / 2)
    {
        std::cout << answer;
    }

    else
    {
        std::cout << str.size();
    }

    return 0;
}