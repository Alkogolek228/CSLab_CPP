#include <iostream>

int main()
{
    long double W, H, x1, y1, x2, y2, w, h, r1, r2, r3, r4;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    if (w <= W && h <= H)
    {
        if (w <= x1 || h <= y1 || h <= H - y2 || w <= W - x2)
        {
            std::cout << 0 << std::endl;
        }

        else if (w + (x2 - x1) <= W || h + (y2 - y1) <= H)
        {
            r1 = w - x1;

            if (r1 < 0)
            {
                r1 = r1 * (-1);
                r2 = w + x2 - W;
            }

            if (r2 < 0)
            {
                r2 = r2 * (-1);
                r3 = y2 - y1 - h;
            }

            if (r3 < 0)
            {
                r3 = r3 * (-1);
                r4 = h - (H - y2);
            }

            if (r4 < 0)
            {
                r4 = r4 * (-1);
            }

            if (w == W)
            {

                if (r3 <= r4)
                {
                    if (r3 + h <= H)
                    {
                        std::cout << r3 << std::endl;
                    }
                }
                else if (r4 <= r3)
                {
                    if (r4 + h <= H)
                    {
                        std::cout << r4 << std::endl;
                    }
                }
            }

            if (h == H)
            {
                if (r1 <= r2)
                {
                    if (r1 + w <= W)
                    {
                        std::cout << r1 << std::endl;
                    }
                }

                else if (r2 <= r1)
                {
                    if (r2 + w <= W)
                    {
                        std::cout << r2 << std::endl;
                    }
                }

            }
            else if (w != W && h != H)
            {
                if (r1 <= r2 && r1 <= r3 && r1 <= r4)
                {
                    if (r1 + w <= W)
                    {
                        std::cout << r1 << std::endl;
                        exit(0);
                    }
                }
                else if (r2 <= r1 && r2 <= r3 && r2 <= r4)
                {
                    if (r2 + w <= W)
                    {
                        std::cout << r2 << std::endl;
                        exit(0);
                    }
                }
                else if (r3 <= r1 && r3 <= r2 && r3 <= r4)
                {
                    if (r3 + h <= H)
                    {

                        std::cout << r3 << std::endl;
                        exit(0);
                    }
                }
                else if (r4 <= r1 && r4 <= r2 && r4 <= r3)
                {
                    if (r4 + h <= H)
                    {
                        std::cout << r4 << std::endl;
                        exit(0);
                    }
                }
            }

        }

        else
        {
            std::cout << -1 << std::endl;
        }
    }
    else
    {
        std::cout << -1 << std::endl;
    }
    return 0;
}