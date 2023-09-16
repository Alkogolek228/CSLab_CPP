#include "mainwindow.h"
#include <set>
#include <map>
#include "ui_mainwindow.h"
#include "rb_map.h"
#include "rb_set.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
std::set<int> mySet;
std::map<int, int> myMap;
MainWindow::~MainWindow()
{
    delete ui;
}
std::pair<int,int> p;

std::string setToString(const std::set<int>& mySet) {
    std::string result = "{";

    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        result += std::to_string(*it);
        if (std::next(it) != mySet.end()) {
            result += ", ";
        }
    }

    result += "}";
    return result;
}

template<typename Key, typename Value>
std::string mapToString(const std::map<Key, Value>& myMap) {
    std::string result = "{";

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        result += std::to_string(it->first) + ": " + std::to_string(it->second);
        if (std::next(it) != myMap.end()) {
            result += ", ";
        }
    }

    result += "}";
    return result;
}

void MainWindow::on_addButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    bool ok;
    int key = ui->lineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }

    int value = ui->lineEdit_2->text().toInt();

    mySet.insert(value);
    myMap.insert(std::pair<int, int>(key, value));
    std::string str1 = setToString(mySet);
    std::string str2 = mapToString(myMap);

    ui->listWidget->addItem(QString::fromStdString(str1));
    ui->listWidget_2->addItem(QString::fromStdString(str2));

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_deleteButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    bool ok;
    int key = ui->lineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }

    int value = ui->lineEdit_2->text().toInt();

    mySet.erase(value);
    myMap.erase(key);
    std::string str1 = setToString(mySet);
    std::string str2 = mapToString(myMap);

    ui->listWidget->addItem(QString::fromStdString(str1));
    ui->listWidget_2->addItem(QString::fromStdString(str2));

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_clearButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    mySet.clear();
    myMap.clear();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_findButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    bool ok;
    int key = ui->lineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }
    std::string str = "";
    if (auto search = myMap.find(key); search != myMap.end())
            str = "Found " + std::to_string(search->first) + " " + std::to_string(search->second) + '\n';
        else
            str = "Not found\n";

    QString qstr = QString::fromStdString(str);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->listWidget->addItem(qstr);
}

