#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"
#include <string>
#include <sstream>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int row = ui->table->rowCount();
    ui->table->insertRow(row);
    QString qstr;
    qstr = ui -> lineEdit -> text();
    std::string buffstr = qstr.toStdString();
    Mystring str = buffstr;
    const char* str1 = "Hello";
    const char* str2 = "World";

    QByteArray utf8Data = qstr.toUtf8();
    char* buffer = new char[utf8Data.size()];
    memcpy(buffer, utf8Data.constData(), utf8Data.size());
    QString buff = buffer;

    QTableWidgetItem *itm = new QTableWidgetItem(buff);
    ui->table->setItem(row,0,itm);

    utf8Data = qstr.toUtf8();
    buffer = new char[utf8Data.size()];

    memmove(buffer, qstr.data(), qstr.size());
    buff = buffer;

    utf8Data = qstr.toUtf8();
    buffer = new char[utf8Data.size()];

    QTableWidgetItem *itm1 = new QTableWidgetItem(buff);
    ui->table->setItem(row,1,itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(strcpy(buffer, qstr.toUtf8().constData()));
    ui->table->setItem(row,2,itm2);

    QTableWidgetItem *itm3 = new QTableWidgetItem(strncpy(buffer, qstr.toUtf8().constData(), 2));
    ui->table->setItem(row,3,itm3);

    QTableWidgetItem *itm4 = new QTableWidgetItem(strcat(buffer, "a"));
    ui->table->setItem(row,4,itm4);

    ui->table->update();

    int row1 = ui->table1->rowCount();
    ui->table1->insertRow(row1);

    QTableWidgetItem *itm5 = new QTableWidgetItem(strncat(buffer, "aaa", 11));
    ui->table1->setItem(row1,0,itm5);

    int res = memcmp(str1, str2, 2);

    QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(res));
    ui->table1->setItem(row1,1,itm6);

    res = strcmp(str1, str2);

    QTableWidgetItem *itm7 = new QTableWidgetItem(QString::number(res));
    ui->table1->setItem(row1,2,itm7);

    res = strcoll(str1, str2);

    QTableWidgetItem *itm8 = new QTableWidgetItem(QString::number(res));
    ui->table1->setItem(row1,3,itm8);

    res = strncmp(str1, str2, 1);

    QTableWidgetItem *itm9 = new QTableWidgetItem(QString::number(res));
    ui->table1->setItem(row1,4,itm9);

    ui->table1->update();


    int row2 = ui->table2->rowCount();
    ui->table2->insertRow(row2);
    const char* src = "apple";
    char dest[10];
    char test[] = "Hello";

    res = strxfrm(dest, src, 10);

    QTableWidgetItem *itm10 = new QTableWidgetItem(QString::number(res));
    ui->table2->setItem(row2,0,itm10);

    QTableWidgetItem *itm11 = new QTableWidgetItem(strtok(test, " "));
    ui->table2->setItem(row2,1,itm11);

    memset(test, 0, 5);
    std::stringstream ss;
    ss << static_cast<void*>(test);

    QString result;
    QTextStream(&result) << QString::fromStdString(ss.str());

    QTableWidgetItem *itm12 = new QTableWidgetItem(result);
    ui->table2->setItem(row2,2,itm12);

    int err = 2;

    QTableWidgetItem *itm13 = new QTableWidgetItem(strerror(err));
    ui->table2->setItem(row2,3,itm13);

    res = strlen(test);

    QTableWidgetItem *itm14 = new QTableWidgetItem(QString::number(res));
    ui->table2->setItem(row2,4,itm14);

    ui->table2->update();
}

