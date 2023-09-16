#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <iostream>
#include "Stack.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int row = 1, column = 0;
    Stack <QChar> st;
    Stack <int> stRow;
    Stack <int> stColumn;
    bool ok = true;
    QString block = ui->textEdit->toPlainText();

    for (int  i = 0; i < block.size(); i++)
    {
        column++;
        if (block[i] == '(' || block[i] == '{' || block[i] == '[')
        {
            st.push(block[i]);
            stRow.push(row);
            stColumn.push(column);
        }
        else if (block[i] == ')' || block[i] == '}' || block[i] == ']')
        {
            if (st.empty() || (block[i] == ')' && st.top() != '(') || (block[i] == '}' && st.top() != '{') || (block[i] == ']' && st.top() != '['))
            {
                ui->mistake->setText("Ошибка в строке " + QString::number(row) + " и столбце " + QString::number(column));
                ok = false;
                break;
            }
            else
            {
                st.pop();
                stRow.pop();
                stColumn.pop();
            }
        }
        if (block[i] == '\n')
        {
            row++;
            column = 0;
        }
    }
    if (ok)
    {
        if (st.empty())
        {
            QMessageBox::warning(this, "Вывод", "Success");
        }
        else
        {
            ui->mistake->setText("Ошибка в строке " + QString::number(stRow.top()) + " и столбце " + QString::number(stColumn.top()));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Open file"),"D:/");
    if (FileName.contains(".txt"))
    {
        QFile file(FileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            return;
        }

        QString str = file.readAll();

        if (str.size() == 0)
        {
            ui->mistake->setText("Файл пустой выберите другой файл");
        }
        else
        {
            ui->textEdit->setText(str);
            ui->pushButton->setEnabled(true);
        }

        file.close();
    }
    else
    {
        ui->mistake->setText("Файл некорректен");
    }
}

void MainWindow::on_textEdit_textChanged()
{
    ui->pushButton->setEnabled(true);
}

