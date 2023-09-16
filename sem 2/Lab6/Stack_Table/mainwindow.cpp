#include "mainwindow.h"
#include "ui_mainwindow.h"

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

HashTable table;

void MainWindow::on_AddButton_clicked()
{
    std::string str = "";
    ui->listWidget->clear();
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }
    int value = ui->valueLineEdit->text().toInt();
    table.put(key, value);
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
    table.print(str);
    QString qstr = QString::fromStdString(str);
    ui->listWidget->addItem(qstr);
}

void MainWindow::on_RemoveButton_clicked()
{
    std::string str = "";
    ui->listWidget->clear();
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok)
    {
        return;
    }
    table.remove(key);
    table.print(str);
    QString qstr = QString::fromStdString(str);
    ui->listWidget->addItem(qstr);
}

void MainWindow::on_GetButton_clicked()
{
    ui->listWidget->clear();
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok)
    {
        return;
    }
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();

    int value = table.get(key);
    QString qstr = QString::number(value);
    ui->listWidget->addItem(qstr);
}

void MainWindow::on_SizeButton_clicked()
{
    ui->listWidget->clear();
    int value = table.size();
    QString qstr = QString::number(value);
    ui->listWidget->addItem(qstr);
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    RandomHashTable table1 = RandomHashTable(10);
    table1.removeEvenKeys();
    std::string str1 = "";
    table1.print(str1);
    QString qstr1 = QString::fromStdString(str1);
    ui->listWidget->addItem(qstr1);
}

