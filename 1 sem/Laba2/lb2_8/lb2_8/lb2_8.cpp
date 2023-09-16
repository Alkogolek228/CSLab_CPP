#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");
    int option;
    std::cout << "Введите номер уравнения: ";
    std::cin >> option;
    long double a, b, c, D, y1, y2, p, q, Q, f;

    switch (option)
    {

    case 1:

        std::cout << "ax^4 + bx^2 + c = 0\n";
        std::cout << "Введите a, b, c:\n";
        std::cin >> a >> b >> c;

        D = powl(b, 2.0) - 4.0 * a * c;

        if (a == 0 && b == 0 && c == 0)
        {
            std::cout << "Бесконечное число корней.";
        }

        else if (a == 0 && b == 0)
        {
            std::cout << "Бан.";
        }
        else if (a == 0 && c == 0 || b == 0 && c == 0)
        {
            std::cout << "Корни уравнения: 0";
        }
        /*else if (b == 0 && c == 0)
        {
            std::cout << "Корни уравнения: 0";
        }*/
        else if (a == 0) 
        {
            if ((-c / b) >= 0) 
            {
                y1 = sqrtl(-c / b);

                if (y1 == 0)
                {
                    std::cout << "Корни уравнения: 0";
                }

                else
                {
                    std::cout << "Корни уравнения: " << y1 << " " << -y1;
                }
            }

            else
            {
                std::cout << "Нет корней.";
            }
        }
        else if (b == 0) 
        {
            if ((-c / a) >= 0) 
            {
                y1 = sqrtl(sqrtl(-c / a));

                if (y1 == 0)
                {
                    std::cout << "Корни уравнения: 0";
                }
                else
                {
                    std::cout << "Корни уравнения: " << y1 << " " << -y1;
                }
            }

            else
            {
                std::cout << "Нет корней.";
            }
        }
        else if (c == 0) 
        {
            D = powl(b, 2.0);
            if (D > 0)
            {
                std::cout << "Корни уравнения: " << sqrtl((-b + sqrtl(D)) / (2.0 * a)) << " " << -sqrtl((-b + sqrtl(D)) / (2.0 * a)) << " " << sqrtl((-b - sqrtl(D)) / (2.0 * a)) << " " << -sqrtl((-b - sqrtl(D)) / (2.0 * a));
            }

            if (D == 0) 
            {
                std::cout << "Корни уравнения: " << sqrtl(-b / (2.0 * a)) << " " << -sqrtl(-b / (2.0 * a));
            }

            else 
            { 
                std::cout << "Нет корней."; 
            }
        }
        else 
        {
            if (D > 0) 
            {
                y1 = (-b + sqrtl(D)) / (2.0 * a);
                y2 = (-b - sqrtl(D)) / (2.0 * a);

                if (y1 > 0)
                {
                    std::cout << "Корни уравнения: " << sqrtl(y1) << " " << (-1.0 * sqrtl(y1)) << " ";
                }

                else if (y1 == 0)
                {
                    std::cout << "Корни уравнения: " << 0; 
                }

                if (y2 > 0) 
                { 
                    std::cout << "Корни уравнения: " << sqrtl(y2) << " " << (-1.0 * sqrtl(y2)); 
                }

                else if (y2 == 0)
                {
                    std::cout << "Корни уравнения: " << 0;
                }

                if (y1 == 0 && y2 == 0)
                {
                    std::cout << "Нет корней.";
                }
            }
            else if (D == 0) 
            {
                y1 = (-b) / (2.0 * a);

                if (y1 > 0)
                {
                    std::cout << "Корни уравнения: " << sqrtl(y1) << " " << (-1.0 * sqrtl(y1)) << " ";
                }

                else if (y1 == 0)
                {
                    std::cout << "Корни уравнения: " << 0;
                }

                else
                {
                    std::cout << "Нет корней.";
                }
            }

            else
            {
                std::cout << "Нет корней.";
            }
        }
        break;

    case 2:
        std::cout << "ax^4 + bx^3 + cx^2 + bx + a = 0\n";
        std::cout << "Введите a, b, c:\n";
        std::cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0) 
        {
            std::cout << "Бесконечное число корней.";
        }

        else if (a == 0 && b == 0) 
        {
            std::cout << "Корни уравнения: 0";
        }

        else if (b == 0 && c == 0) 
        {
            std::cout << "Условие неверно.";
        }

        else if (a == 0 && c == 0)
        {
            std::cout << "Корни уравнения: 0";
        }

        else if (a == 0) 
        {
            D = powl(c, 2.0) - 4.0 * powl(b, 2.0);

            if (D > 0) 
            {
                std::cout << "Корни уравнения: 0 " << (-c + sqrtl(D)) / (2.0 * b) << " " << (-c - sqrtl(D)) / (2.0 * b);
            }

            if (D == 0) 
            {
                std::cout << "Корни уравнения: 0 " << -c / (2.0 * b);
            }

            if (D < 0) 
            {
                std::cout << "Корни уравнения: 0 ";
            }
        }

        else if (b == 0) 
        {
            D = powl(c, 2.0) - 4.0 * powl(a, 2.0);

            if (D > 0) 
            {
                std::cout << "Корни уравнения: " << sqrtl((-c + sqrtl(D)) / (2.0 * a)) << " " << -sqrtl((-c + sqrtl(D)) / (2.0 * a)) << " " << sqrtl((-c - sqrtl(D)) / (2.0 * a)) << " " << -sqrtl((-c + sqrtl(D)) / (2.0 * a));
            }
        }

        else 
        {
            std::cout << "y = x + (1.0 / x)\n";
            std::cout << "ay^2 + by + c – 2a = 0\n";

            D = powl(b, 2.0) - (4.0 * a * (c - (2.0 * a)));
            std::cout << "Корни уравнения: ";

            if (D > 0) 
            {
                y1 = (-b + sqrtl(D)) / (2.0 * a);
                y2 = (-b - sqrtl(D)) / (2.0 * a);

                std::cout << "x^2 - yx + 1 = 0\n";

                D = powl(y1, 2.0) - 4.0;

                if (D > 0)
                {
                    std::cout << (((y1) + sqrtl(D)) / 2.0) << " " << (((y1) - sqrtl(D)) / 2.0) << " ";
                }

                else if (D == 0)
                {
                    std::cout << ((y1) / 2.0) << " ";
                }

                D = powl(y2, 2.0) - 4.0;

                if (D > 0)
                {
                    std::cout << (((y2) + sqrtl(D)) / 2.0) << " " << (((y2) - sqrtl(D)) / 2.0);
                }

                else if (D == 0)
                {
                    std::cout << ((y2) / 2.0);
                }
            }
            else if (D == 0) 
            {
                y1 = (-b) / (2.0 * a);
                D = powl(y1, 2.0) - 4.0;

                if (D > 0)
                {
                    std::cout << (((y1) + sqrtl(D)) / 2.0) << " " << (((y1) - sqrtl(D)) / 2.0) << " ";
                }

                else if (D == 0)
                {
                    std::cout << ((y1) / 2.0) << " ";
                }
            }
        }
        break;

    case 3:

        std::cout << "x^3 + px + q = 0\n";
        std::cout << "Введите p, q:\n";
        std::cin >> p >> q;

        if (p == 0 && q == 0) 
        {
            std::cout << "Корни уравнения: 0";
        }

        else if (p == 0) 
        {
            std::cout << "Корни уравнения: " << cbrtl(-q) << " " << -cbrtl(-q);
        }

        else if (q == 0) 
        {
            std::cout << "Корни уравнения: 0";
        }

        else 
        {
            Q = (p / 3.0) * (p / 3.0) * (p / 3.0) + (q / 2.0) * (q / 2.0);

            std::cout << "Корни уравнения: ";

            if (Q < 0) 
            {
                f = acos(-(q / 2.0) * sqrtl((3.0 / (-p)) * (3.0 / (-p)) * (3.0 / (-p))));
                std::cout << 2.0 * sqrtl(-p / 3.0) * cos(f / 3.0) << " " << 2 * sqrtl(-p / 3.0) * cos(f / 3.0 + 2.0 * acos(-1) / 3.0) << " " << 2.0 * sqrtl(-p / 3.0) * cos(f / 3.0 - 2.0 * acos(-1) / 3.0);
            }

            else 
            {
                std::cout << cbrtl(-q / 2 + sqrtl(Q)) + cbrtl(-q / 2 - sqrtl(Q));
            }
        }
        break;
    }           
}
