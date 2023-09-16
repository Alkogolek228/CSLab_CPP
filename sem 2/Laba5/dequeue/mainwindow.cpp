#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deque.h"
#include <ctime>

QString dequeToString(const std::deque<int>& d) {
    QString result = "";
    for (int i = 0; i < d.size(); i++) {
        result += QString::number(d[i]);
        if (i != d.size() - 1) {
            result += " ";
        }
    }
    return result;
}

Deque<int> aa;
std::deque<int> a;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(100);

    srand(time(NULL)); // Инициализируем генератор случайных чисел
    for (int i = 0; i < 10; i++) {
        a.push_back(rand() % 100);
    }

    QString res = dequeToString(a);
    QTableWidgetItem* newitem1 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0,0,newitem1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int i = 1;

void MainWindow::on_push_back_clicked()
{
    a.push_back(42);
    QString res = dequeToString(a);
    QTableWidgetItem *itm0 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0, i,itm0);
    i++;
    ui->tableWidget->update();
}

void MainWindow::on_push_front_clicked()
{
    a.push_front(42);
    QString res = dequeToString(a);
    QTableWidgetItem *itm0 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0, i,itm0);
    i++;
    ui->tableWidget->update();
}

void MainWindow::on_pop_back_clicked()
{
    a.pop_back();
    QString res = dequeToString(a);
    QTableWidgetItem *itm0 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0, i,itm0);
    i++;
    ui->tableWidget->update();
}

void MainWindow::on_pop_front_clicked()
{
    a.pop_front();
    QString res = dequeToString(a);
    QTableWidgetItem *itm0 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0, i,itm0);
    i++;
    ui->tableWidget->update();
}

void MainWindow::on_clear_clicked()
{
    a.clear();
    QString res = dequeToString(a);
    QTableWidgetItem *itm0 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0, i,itm0);
    i++;
    ui->tableWidget->update();
}

void MainWindow::on_size_clicked()
{
    QString res = QString::number(a.size());
    QTableWidgetItem *itm0 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0, i,itm0);
    i++;
    ui->tableWidget->update();
}

void MainWindow::on_empty_clicked()
{
    QString res = QString::number(a.empty());
    QTableWidgetItem *itm0 = new QTableWidgetItem(res);
    ui->tableWidget->setItem(0, i,itm0);
    i++;
    ui->tableWidget->update();
}

