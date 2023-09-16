#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "queue"
#include <ctime>
#include <cstdlib>

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

void copyQueue(std::queue<int>& q1, std::queue<int>& q2) {
    // создаем временную очередь для хранения копии
    std::queue<int> tmp;

    // копируем все элементы из q1 в tmp
    while (!q1.empty()) {
        int x = q1.front();
        q1.pop();
        tmp.push(x);
    }

    // копируем все элементы из tmp в q2 и возвращаем q1 в исходное состояние
    while (!tmp.empty()) {
        int x = tmp.front();
        tmp.pop();
        q1.push(x);
        q2.push(x);
    }
}

void MainWindow::on_pushButton_clicked()
{
    std::queue<int> q1;
    std::queue<int> q1buff;
    std::queue<int> q2;
    std::queue<int> q2buff;
    std::queue<int> q3;

    srand(time(NULL)); // Инициализируем генератор случайных чисел
    for (int i = 0; i < 10; i++) {
        q1.push(rand() % 100);
        q2.push(rand() % 100);
    }

    copyQueue(q1, q1buff);
    copyQueue(q2, q2buff);

    // поиск максимального элемента в первой очереди
       int max = q1.front();
       std::queue<int> tmp; // временная очередь для хранения элементов после максимального
       while (!q1.empty()) {
           int x = q1.front();
           q1.pop();
           if (x > max) max = x;
           if (x != max) tmp.push(x);
       }

       // вставка элементов второй очереди после максимального элемента в третью очередь
       q3.push(max);
       while (!q2.empty()) {
           int x = q2.front();
           q2.pop();
           q3.push(x);
       }
       while (!tmp.empty()) {
           int x = tmp.front();
           tmp.pop();
           q3.push(x);
       }

    QString queues1;
    while (!q1buff.empty())
    {
        queues1 += QString::number(q1buff.front()) + " ";
        q1buff.pop();
    }

    QString queues2;
    while (!q2buff.empty())
    {
        queues2 += QString::number(q2buff.front()) + " ";
        q2buff.pop();
    }

    QString queues3;
    while (!q3.empty())
    {
        queues3 += QString::number(q3.front()) + " ";
        q3.pop();
    }

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *itm0 = new QTableWidgetItem(queues1);
    ui->tableWidget->setItem(row, 0 ,itm0);

    QTableWidgetItem *itm1 = new QTableWidgetItem(queues2);
    ui->tableWidget->setItem(row, 1 ,itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(queues3);
    ui->tableWidget->setItem(row, 2 ,itm2);

    ui->tableWidget->update();
}

