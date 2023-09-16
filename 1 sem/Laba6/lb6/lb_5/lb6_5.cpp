#include <iostream>
#include <string>
#include <cmath>

long long binpow(long long base, long long power, int module) 
{
    long long res = 1;
    base %= module;
    while (power) 
    {
        if (power & 1)
        {
            res *= base;     
            res %= module;
        }
        base *= base;
        base %= module;
        power >>= 1;
    }
    return res;
}

bool inter(std::string s1, std::string s2, long long L)
{
    long long raz = std::abs(s1.length() + s2.length() - L);
    std::string str1, str2;
    str1 = s1.substr(s1.length() - raz, s1.length());
    str2 = s2.substr(0, raz);

    if (str1 == str2)
    {
        return true;
    }
    return false;
}

long long solve(std::string s1, std::string s2, long long L, long long module)
{
    long long s1_len = s1.length();
    long long s2_len = s2.length();
    long long answer = 0;
    if ((L - s1_len - s2_len) >= 0)
    {
        answer = binpow(26, (L - s1_len - s2_len), module);

        if (s1 != s2)
        {
            answer = (2 * binpow(26, (L - s1_len - s2_len), module)) % module;
        }
    }

    else if ((L - s1_len - s2_len) < 0)
    {
        if (inter(s1, s2, L))
        {
            return  1;
        }
        else
        {
            return 0;
        }
    }
    return answer;
}

int main()
{
    std::string s1, s2;
    int k;
    std::cin >> k;
    long long L, m;
    for (int i = 0; i < k; i++)
    {
        std::cin >> L >> m;
        std::cin >> s1 >> s2;

        std::cout << solve(s1, s2, L, m) << "\n";
    }
    return 0;
}