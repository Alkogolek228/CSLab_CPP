#include <iostream>

int FuncNotFrom7_2(int interval_end)
{
    int res = 0;

    for (int i = 1; i <= interval_end; i++)
    {
        if (i % 10 == 9)
        {
            res++;
        }
    }
    return res;
}

int main() // O(k*n)
{
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n;
        std::cin >> n;

        std::cout << FuncNotFrom7_2(n);
    }
}