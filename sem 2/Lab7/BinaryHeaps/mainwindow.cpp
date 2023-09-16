#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "binaryheaparray.h"
#include "binaryheaplist.h"
#include <Qstring>
#include <QDebug>

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

std::string binaryHeapArrayToString(BinaryHeapArray<int> heap) {
    std::string result;

    while (!heap.isEmpty()) {
        result += std::to_string(heap.extractMax()) + " ";
    }

    return result;
}

std::string binaryHeapListToString(BinaryHeapList<int> heap) {
    std::string result;

    while (!heap.isEmpty()) {
        result += std::to_string(heap.getMin()) + " ";
        heap.removeMin();
    }

    return result;
}

BinaryHeapArray<int> heapArray;
BinaryHeapList<int> heapList;

void MainWindow::on_addButton_clicked()
{
    ui->listWidget_1->clear();
    ui->listWidget_2->clear();

    std::string str1 = binaryHeapArrayToString(heapArray);
    std::string str2 = binaryHeapListToString(heapList);
    QString qstr1 = QString::fromStdString(str1);
    QString qstr2 = QString::fromStdString(str2);

    ui->listWidget_1->addItem(qstr1);
    ui->listWidget_2->addItem(qstr2);
    ui->lineEdit->clear();
}


void MainWindow::on_adddataButton_clicked()
{
    ui->listWidget_1->clear();
    ui->listWidget_2->clear();

    bool ok;
    int val = ui->lineEdit->text().toInt(&ok);

    heapArray.insert(val);
    heapList.insert(val);

    ui->lineEdit->clear();
}

