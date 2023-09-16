#include <iostream>
#include <cmath>

int main()
{
    int h1, h2, m1, m2, t1, t2, t, h, m;
    std::cout << "Enter h1, m1 and h2, m2 \n";
    std::cin >> h1 >> m1 >> h2 >> m2;
    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    if (t2 < t1)
    {
        t = (24 * 60 - (t1 - t2));

    }
    else
    {
        t = t2 - t1;
    }

    h = t / 60;
    m = t % 60;
    std::cout << h << " hours " << m << " mins";
}
