#ifndef STANDARTCALC_H
#define STANDARTCALC_H

#include <string>

class StandartCalc
{
private:
    std::string str;
    int index = 0;
    double a, b, c, d, e;
    double factor();
    double skobki();
    double number();
public:
    StandartCalc(double a, double b, double c, double d, double e, std::string str);
    double expr();
};

#endif // STANDARTCALC_H
