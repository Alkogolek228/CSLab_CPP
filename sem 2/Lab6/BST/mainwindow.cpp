#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateTreeWidget();
}

void MainWindow::updateTreeWidget()
{
    // Очистить содержимое QTreeWidget
    ui->treeWidget->clear();

    // Получить данные для отображения
    std::vector<std::pair<int, std::string>> data = bst.printAscending();

    // Добавить каждый элемент в QTreeWidget
    for (const auto& pair : data)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0, QString::number(pair.first));
        item->setText(1, QString::fromStdString(pair.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok) {
        return;
    }
    std::string value = ui->valueLineEdit->text().toStdString();
    bst.add(key, value);
    updateTreeWidget();
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
}

void MainWindow::on_searchButton_clicked()
{
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok)
    {
        return;
    }
    std::string value = bst.find(key);
    if (!value.empty())
    {
        ui->valueLineEdit->setText(QString::fromStdString(value));
    }
    else
    {
        ui->valueLineEdit->clear();
    }
}

void MainWindow::on_removeButton_clicked()
{
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);
    if (!ok)
    {
        return;
    }
    bst.del(key);
    updateTreeWidget();
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
}

void MainWindow::on_balanceButton_clicked()
{
    bst.toBalance();
    updateTreeWidget();
}


void MainWindow::on_printStraightButton_clicked()
{
    std::vector<std::pair<int, std::string>> vec = bst.printStraight();
    ui->treeWidget->clear();
    for (const auto& p : vec)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(p.first));
        item->setText(1, QString::fromStdString(p.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}


void MainWindow::on_printBackwardButton_clicked()
{
    std::vector<std::pair<int, std::string>> vec = bst.printBackward();
    ui->treeWidget->clear();
    for (const auto& p : vec)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(p.first));
        item->setText(1, QString::fromStdString(p.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}


void MainWindow::on_printAscendingButton_clicked()
{
    std::vector<std::pair<int, std::string>> vec = bst.printAscending();
    ui->treeWidget->clear();
    for (const auto& p : vec)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(p.first));
        item->setText(1, QString::fromStdString(p.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}

void MainWindow::on_pushButton_clicked()
{
    std::vector<std::pair<int, std::string>> vec = bst.printAscending();
    FindLeaf task(vec);
    int leaves = task.countLeaves();
    ui->label_2->setText(QString::number(leaves));
}

