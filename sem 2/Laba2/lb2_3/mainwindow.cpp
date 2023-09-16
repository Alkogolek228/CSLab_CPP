#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString startText = "a/(b-c)*(d+e)\n";
    startText += "(a+b)*(c-d)/e\n";
    startText += "a-(b+c*d)/e\n";
    startText += "a/b-((c+d)*e)\n";
    startText += "a*(b-c+d)/e\n";
    startText += "(a+b)*(c-d)/e\n";
    startText += "a*(b-c)/(d+e)\n";
    startText += "a/(b*(c+d))-e\n";
    startText += "(a+(b/c-d))*e\n";
    startText += "a*(b+c)/(d-e)\n";
    startText += "a-(b/c*(d+e))\n";
    startText += "(a-b)/(c+d)*e\n";
    startText += "a/(b+c-d*e)\n";
    startText += "a*(b-c)/(d+e)\n";
    startText += "(a+b*c)/(d-e)\n";
    ui->textEdit->setText(startText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isNormalString(QString str)
{
    int countOfBrackets = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (countOfBrackets < 0)
        {
            return false;
        }
        if (str[i] == '(')
        {
            countOfBrackets++;
        }
        else if (str[i] == ')')
        {
            countOfBrackets--;
        }
        else if (str[i] != 'a' && str[i] != 'b' && str[i] != 'c' && str[i] != 'd' && str[i] != 'e' && str[i] != '%' && str[i] != '/' && str[i] != '*' && str[i] != '+' && str[i] != '-')
        {
            return false;
        }
    }

    if (countOfBrackets != 0)
    {
        return false;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            if (i == 0 && str[i + 1] != 'a' && str[i + 1] != 'b' && str[i + 1] != 'c' && str[i + 1] != 'd' && str[i + 1] != 'e' && str[i + 1] != '(')
            {
                return false;
            }
            else if (i != 0 && ((str[i + 1] != 'a' && str[i + 1] != 'b' && str[i + 1] != 'c' && str[i + 1] != 'd' && str[i + 1] != 'e' && str[i + 1] != '(') || (str[i - 1] != '/' && str[i - 1] != '%' && str[i - 1] != '*' && str[i - 1] != '-' && str[i - 1] != '+' && str[i - 1] != '(')))
            {
                return false;
            }
        }
        else if (str[i] == ')')
        {
            if (i == str.size() - 1 && str[i - 1] != 'a' && str[i - 1] != 'b' && str[i - 1] != 'c' && str[i - 1] != 'd' && str[i - 1] != 'e' && str[i - 1] != ')')
            {
                return false;
            }
            else if (i != str.size() - 1 && ((str[i - 1] != 'a' && str[i - 1] != 'b' && str[i - 1] != 'c' && str[i - 1] != 'd' && str[i - 1] != 'e' && str[i - 1] != ')') || (str[i + 1] != '/' && str[i + 1] != '*' && str[i + 1] != '%' && str[i + 1] != '-' && str[i + 1] != '+' && str[i + 1] != ')')))
            {
                return false;
            }
        }
        else if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e')
        {
            if (i == 0 && str[i + 1] != '/' && str[i + 1] != '%' && str[i + 1] != '*' && str[i + 1] != '+' && str[i + 1] != '-')
            {
                return false;
            }
            else if (i == str.size() - 1 && str[i - 1] != '/' && str[i - 1] != '%' && str[i - 1] != '*' && str[i - 1] != '+' && str[i - 1] != '-')
            {
                return false;
            }
            else if (i != str.size() - 1 && i != 0 && ((str[i - 1] != '/' && str[i - 1] != '*' && str[i - 1] != '%' && str[i - 1] != '+' && str[i - 1] != '-' && str[i - 1] != '(') || (str[i + 1] != '/' && str[i + 1] != '*' && str[i + 1] != '+' && str[i + 1] != '-' && str[i + 1] != ')')))
            {
                return false;
            }
        }
        else if (str[i] == '/' || str[i] == '*' || str[i] == '%' || str[i] == '-' || str[i] == '+')
        {
            if (i == 0 || i == str.size() - 1)
            {
                return false;
            }
            else if ((str[i - 1] != 'a' && str[i - 1] != 'b' && str[i - 1] != 'c' && str[i - 1] != 'd' && str[i - 1] != 'e' && str[i - 1] != ')') || (str[i + 1] != 'a' && str[i + 1] != 'b' && str[i + 1] != 'c' && str[i + 1] != 'd' && str[i + 1] != 'e' && str[i + 1] != '('))
            {
                return false;
            }
        }
    }
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    double a = ui->doubleSpinBox_9->value();
    double b = ui->doubleSpinBox_8->value();
    double c = ui->doubleSpinBox_7->value();
    double d = ui->doubleSpinBox_6->value();
    double e = ui->doubleSpinBox_5->value();
    Calculate* calc = nullptr;
    StandartCalc* calc2 = nullptr;
    QString Str = ui->textEdit->toPlainText();
    QString str2 = "", ans = "";

    for (int i = 0; i < Str.size(); i++)
    {
        if (Str[i] != '\n')
        {
            str2 += Str[i];
        }

        if (Str[i] == '\n' || i == Str.size() - 1)
        {
            if (isNormalString(str2))
            {
                calc = new Calculate(str2, a, b, c, d, e);
                calc2 = new StandartCalc(a, b, c, d, e, str2.toStdString());
                calc->Convert();
                ans += calc->getOPZ();
                calc->CalculateValue();
                double res = calc2->expr();
                if (calc->getOK())
                {
                    ans += "   (Ответ: " + QString::number(calc->getValue()) + "/" + QString::number(res) +")\n";
                }
                else
                {
                    ans += "   (Ответ: Ошибка)\n";
                }
            }
            else
            {
                ans += "Неверное выражение\n";
            }
            str2.clear();
        }
    }
    ui->textEdit_2->setText(ans);
}
