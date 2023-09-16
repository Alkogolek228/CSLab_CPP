#include "book.h"
#include "ui_bus.h"

bus::bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bus)
{
    ui->setupUi(this);
}

bus::~bus()
{
    delete ui;
}

void Book::set_regnumber(QString regnumber){
    if (regnumber == "") throw "error";
    this -> regnumber = regnumber;
}

void Book::set_name(QString name){
    if (name == "") throw "error";
    this ->name = name;
}

void Book::set_author(QString author){
    if (author == "") throw "error";
    this -> author = author;
}

void Book::set_num_sheets(QString num_sheets){
    if (num_sheets == "") throw "error";
    this -> num_sheets = num_sheets;
}

void Book::set_year(QString year){
    if (year == "") throw "error";
    this -> year = year;
}

void Book::set_publisher(QString publisher){
    if (publisher == "") throw "error";
    this -> publisher = publisher;
}

QString Book::get_regnumber() const{
    return regnumber;
}

QString Book::get_author() const{
    return author;
}

QString Book::get_name() const{
    return name;
}

QString Book::get_year() const{
    return year;
}

QString Book::get_publisher () const{
    return publisher;
}

QString Book::get_num_sheets () const{
    return num_sheets;
}


