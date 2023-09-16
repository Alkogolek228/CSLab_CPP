#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "un_map.h"
#include <unordered_map>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
std::unordered_map<int,int> map;
MainWindow::~MainWindow()
{
    delete ui;
}

template<class KeyType, class ValueType>
std::string unorderedMapToString(const std::unordered_map<KeyType, ValueType>& map) {
    std::string result;
    for (const auto& pair : map) {
        result += "(" + std::to_string(pair.first) + ", " + std::to_string(pair.second) + ") ";
    }
    return result;
}

un_map<int,int> umap;

void MainWindow::on_AddButton_clicked()
{
    ui->listWidget->clear();
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }
    int value = ui->valueLineEdit->text().toInt();
    map.insert({key, value});
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
    std::string str = unorderedMapToString(map);
    QString qstr = QString::fromStdString(str);
    ui->listWidget->addItem(qstr);
}

void MainWindow::on_conButton_clicked()
{
    ui->listWidget->clear();
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
    std::string str = "";

    if (auto search = map.find(key); search != map.end())
            str = "Found " + std::to_string(search->first) + " " + std::to_string(search->second) + '\n';
        else
            str = "Not found\n";

    if(str != "Not found\n")
    {
        ui->listWidget->addItem("YES");
    }
    else
    {
        ui->listWidget->addItem("NO");
    }
}

void MainWindow::on_findButton_clicked()
{
    ui->listWidget->clear();
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }
    std::string str = "";
    if (auto search = map.find(key); search != map.end())
            str = "Found " + std::to_string(search->first) + " " + std::to_string(search->second) + '\n';
        else
            str = "Not found\n";

    QString qstr = QString::fromStdString(str);
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
    ui->listWidget->addItem(qstr);
}


void MainWindow::on_sizeButton_clicked()
{
    ui->listWidget->clear();

    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
    std::string str = std::to_string(map.size());
    QString qstr = QString::fromStdString(str);
    ui->listWidget->addItem(qstr);
}

void MainWindow::on_eraseButton_clicked()
{
    ui->listWidget->clear();
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }
    for (auto it = map.begin(); it != map.end();)
    {
        if (it->first == key)
            it = map.erase(it);
        else
            ++it;
    }
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
    std::string str = unorderedMapToString(map);
    QString qstr = QString::fromStdString(str);
    ui->listWidget->addItem(qstr);
}

void MainWindow::on_clearButton_clicked()
{
    ui->listWidget->clear();
    map.clear();
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
}

