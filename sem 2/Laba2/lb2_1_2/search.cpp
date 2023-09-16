#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}


void search::on_pushButton_2_clicked()
{
    ui -> listWidget -> clear();
}

