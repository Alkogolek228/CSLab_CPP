#include "mainwindow.h"
#include "search.h"
#include "ui_mainwindow.h"
#include "list.cpp"
#include "libs.h"
#include "book.h"
#include "ui_search.h"

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

list <Book> admises;

int count = 0;

void MainWindow::on_add_clicked()
{

    Book new_admis;
    try
    {
        new_admis.set_regnumber(ui -> lineEdit -> text());
        new_admis.set_author(ui -> lineEdit_2 -> text());
        new_admis.set_name(ui -> lineEdit_3 -> text());
        new_admis.set_year(ui -> lineEdit_4 -> text());
        new_admis.set_publisher(ui -> lineEdit_5 -> text());
        new_admis.set_num_sheets(ui -> lineEdit_6 -> text());
        ui -> listWidget -> addItem(new_admis.get_regnumber() + "\t" + new_admis.get_author() + "\t" + new_admis.get_name() + "\t" + new_admis.get_year() + '\t' + new_admis.get_publisher() + "\t" + new_admis.get_num_sheets());
        admises.push_back(new_admis);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Something went wrong");
    }
    ui -> lineEdit -> clear();
    ui -> lineEdit_2 -> clear();
    ui -> lineEdit_3 -> clear();
    ui -> lineEdit_4 -> clear();
    ui -> lineEdit_5 -> clear();
    ui -> lineEdit_6 -> clear();
}


void MainWindow::on_clear_clicked()
{
    if (admises.size() == 0) QMessageBox::information(this,"info", "There is no data, so you can't clear it");
    else
    {
        ui -> listWidget -> clear();
        admises.clear();
    }
}


void MainWindow::on_delete_2_clicked()
{
    try
    {
        if (admises.size() == 0)
        {
            QMessageBox::critical (this, "Error", "No data to delete");
        }

        else if (admises.size() == 1)
        {
            ui -> listWidget -> clear();
            admises.clear();
        }

        else
        {
            ui -> listWidget ->takeItem(ui->listWidget->currentRow());
            int number = ui -> listWidget -> currentRow();

            if (number == -1)
            {
                throw "Error";
            }

            admises.erase(number - 1);
        }
        ui -> listWidget -> show();
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "choose the object to delete");
    }
}

void MainWindow::on_searching_clicked()
{
    if (admises.size() == 0)
        QMessageBox::warning(this, "Error", "No data");
    else
    {
        searchwindow = new class search;
        searchwindow -> setWindowTitle("Search");
        searchwindow -> show();
    }
}

void search::on_pushButton_clicked()
{
    try
    {
        QString regnumber = ui -> lineEdit -> text();
        QString author = ui -> lineEdit_2 -> text();
        QString name = ui -> lineEdit_3 -> text();
        QString year = ui -> lineEdit_4 -> text();

        int count = 0;

        for (int i = 0; i < admises.size(); i ++)
        {
            if (admises[i].get_regnumber() == regnumber)
            {
                count ++;
                ui -> listWidget -> addItem(admises[i].get_regnumber() + "\t" + admises[i].get_author() + "\t" + admises[i].get_name() + "\t" + admises[i].get_year() + '\t' + admises[i].get_publisher() + "\t" + admises[i].get_num_sheets());
            }
        }
        if (!count) QMessageBox::information(this, "info", "No data founded");

        count = 0;

        for (int i = 0; i < admises.size(); i ++)
        {
            if (admises[i].get_author() == author)
            {
                count ++;
                ui -> listWidget -> addItem(admises[i].get_regnumber() + "\t" + admises[i].get_author() + "\t" + admises[i].get_name() + "\t" + admises[i].get_year() + '\t' + admises[i].get_publisher() + "\t" + admises[i].get_num_sheets());
            }
        }
        if (!count) QMessageBox::information(this, "info", "No data founded");

        count = 0;

        for (int i = 0; i < admises.size(); i ++)
        {
            if (admises[i].get_name() == name && admises[i].get_year() == year )
            {
                count ++;
                ui -> listWidget -> addItem(admises[i].get_regnumber() + "\t" + admises[i].get_author() + "\t" + admises[i].get_name() + "\t" + admises[i].get_year() + '\t' + admises[i].get_publisher() + "\t" + admises[i].get_num_sheets());
            }
        }
        if (!count) QMessageBox::information(this, "info", "No data founded");
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Something went wrong");
    }

    ui -> lineEdit -> clear();
    ui -> lineEdit_2 -> clear();
    ui -> lineEdit_3 -> clear();
    ui -> lineEdit_4 -> clear();
}




