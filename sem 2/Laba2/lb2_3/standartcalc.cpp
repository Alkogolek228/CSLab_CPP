#include "standartcalc.h"

StandartCalc::StandartCalc(double a, double b, double c, double d, double e, std::string str)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
    this->str = str;
}

double StandartCalc::expr()
{
    double x = factor();
    while(1)
    {
        index++;
        if(str[index - 1] == '+')
        {
            x += factor();
            break;
        }
        else if (str[index - 1] =='-')
        {
            x -= factor();
            break;
        }
        else
        {
            index--;
            return x;
        }
    }
}

double StandartCalc::factor()
{
    double x = skobki();
    while(1)
    {
        index++;

        if(str[index - 1] == '*')
        {
            x *= skobki();
            break;
        }
        else if(str[index - 1] == '/')
        {
            x /= skobki();
            break;
        }
        else if(str[index - 1] =='%')
        {
            int q1 = x;
            int q2 = skobki();
            q1 %= q2;
            x = q1;
            break;
        }
        else
        {
            index--;
            return x;
        }
    }
}

double StandartCalc::skobki()
{
    if (str[index] == '(')
    {
        index++;
        double x = expr();
        index++;
        return x;
    }
    else
    {
        return number();
    }
}

double StandartCalc::number()
{
    if (str[index] == 'a')
    {
        index++;
        return a;
    }
    else if (str[index] == 'b')
    {
        index++;
        return b;
    }
    else if (str[index] == 'c')
    {
        index++;
        return c;
    }
    else if (str[index] == 'd')
    {
        index++;
        return d;
    }
    else if (str[index] == 'e')
    {
        index++;
        return e;
    }
}
