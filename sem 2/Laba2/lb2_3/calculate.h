#ifndef CALCULATE_H
#define CALCULATE_H

#include <QString>
#include <stack>
#include <QMessageBox>
#include <string>

class Calculate
{
public:
    Calculate(QString str, double a, double b, double c, double d, double e);
public:
    double a, b, c, d, e;
    QString Ariphmetic;
    std::string str;
    QString OPZ = "";
    bool OK;
    double Value;

public:
    void Convert();
    QString getOPZ();
    void CalculateValue();
    double getValue();
    bool getOK();
};

#endif // CALCULATE_H
