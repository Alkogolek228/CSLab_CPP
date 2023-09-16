#include "calculate.h"
#include "stack.h"
#include <iostream>

Calculate::Calculate(QString str, double a, double b, double c, double d, double e)
{
    Ariphmetic = str;
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
    this->str = str.toStdString();
}

void Calculate::Convert()
{
    Stack<QChar> OPZString;
    for (int i = 0; i < Ariphmetic.size(); i++)
    {
        if (Ariphmetic[i] == '(')
        {
            OPZString.push('(');
        }
        else if (Ariphmetic[i] == ')')
        {
            QChar Open;
            do
            {
                Open = OPZString.top();
                OPZString.pop();
                if (Open != '(')
                {
                    OPZ += Open;
                }
            } while (Open != '(');
        }
        else if (Ariphmetic[i] == 'a' || Ariphmetic[i] == 'b' || Ariphmetic[i] == 'c' || Ariphmetic[i] == 'd' || Ariphmetic[i] == 'e')
        {
            OPZ += Ariphmetic[i];
        }
        else if (Ariphmetic[i] == '+' || Ariphmetic[i] == '-')
        {
            if (!OPZString.empty())
            {
                QChar Open = OPZString.top();
                while (Open != '(' && !OPZString.empty())
                {
                    OPZString.pop();
                    OPZ += Open;
                    if (!OPZString.empty())
                    {
                        Open = OPZString.top();
                    }
                }
            }
            OPZString.push(Ariphmetic[i]);
        }
        else if (Ariphmetic[i] == '*' || Ariphmetic[i] == '/' || Ariphmetic[i] == '%')
        {
            if (!OPZString.empty())
            {
                QChar Open = OPZString.top();
                while (Open != '+' && Open != '-' && Open != '(' && !OPZString.empty())
                {
                    OPZString.pop();
                    OPZ += Open;
                    if (!OPZString.empty())
                    {
                        Open = OPZString.top();
                    }
                }
            }
            OPZString.push(Ariphmetic[i]);
        }
    }
    QChar temp ;
    while (!OPZString.empty())
    {
        temp = OPZString.top();
        OPZString.pop();
        OPZ += temp;
    }
}

QString Calculate::getOPZ()
{
    return OPZ;
}

void Calculate::CalculateValue()
{
    OK = true;
    Stack<double> answer;
    for (int i = 0; i < OPZ.size(); i++)
    {
        if (OPZ[i] == 'a')
        {
            answer.push(a);
        }
        else if (OPZ[i] == 'b')
        {
            answer.push(b);
        }
        else if (OPZ[i] == 'c')
        {
            answer.push(c);
        }
        else if (OPZ[i] == 'd')
        {
            answer.push(d);
        }
        else if (OPZ[i] == 'e')
        {
            answer.push(e);
        }
        else if (OPZ[i] == '+')
        {
            double First = answer.top();
            answer.pop();
            double Second = answer.top();
            answer.pop();
            answer.push(Second + First);
        }
        else if (OPZ[i] == '-')
        {
            double First = answer.top();
            answer.pop();
            double Second = answer.top();
            answer.pop();
            answer.push(Second - First);
        }
        else if (OPZ[i] == '*')
        {
            double First = answer.top();
            answer.pop();
            double Second = answer.top();
            answer.pop();
            answer.push(Second * First);
        }
        else if (OPZ[i] == '/')
        {
            double First = answer.top();
            answer.pop();
            double Second = answer.top();
            answer.pop();
            if (First != 0)
            {
                answer.push(Second / First);
            }
            else
            {
                OK = false;
                break;
            }
        }
        else if (OPZ[i] == '%')
        {
            double First = answer.top();
            int first = First;
            answer.pop();
            double Second = answer.top();
            int second = Second;
            answer.pop();

            if (!(second != Second || First != first))
            {
                answer.push(second % first);
            }
            else
            {
                OK = false;
                break;
            }
        }
    }
    if (OK)
    {
        Value = answer.top();
    }
}

double Calculate::getValue()
{
    return Value;
}

bool Calculate::getOK()
{
    return OK;
}
