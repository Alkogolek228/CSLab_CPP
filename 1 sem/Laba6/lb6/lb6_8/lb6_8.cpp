 #include <iostream>  
#include <string> 

int main()
{
    int q;
    std::string s, t;
    std::cin >> q;

    for (int a = 0; a < q; a++)
    {
        int count = 0, num = 0, index = 0, index1 = 0;
        bool flag = false;
        std::cin >> s >> t;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[0])
            {
                index = i;
                ++count;
                ++num;
                flag = true;
            }

            if (flag)
            {
                break;
            }
        }

        flag = false;

        if (index == s.length() - 1 && s.length() == t.length())
        {
            index -= 2;
        }
        ++index;

        for (index; index < s.length(); index++)
        {
            if (s[index] == t[num])
            {
                ++count;
                ++num;
            }

            if (count == t.length())
            {
                flag = true;
            }

            if (flag)
            {
                break;
            }
            index1 = index;
        }

        if (count == t.length())
        {
            std::cout << "YES\n";
            continue;
        }
        index1--;

        for (index1; index1 > -1; index1--)
        {
            if (s[index1] == t[num])
            {
                ++count;
                num++;
            }
        }

        if (count == t.length())
        {
            std::cout << "YES\n";
            continue;
        }
        std::cout << "NO\n";
    }
    return 0;
}