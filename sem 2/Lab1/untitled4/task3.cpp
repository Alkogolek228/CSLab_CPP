#include "task3.h"
#include "ui_task3.h"
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

Task3::Task3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task3)
{
    ui->setupUi(this);
}

Task3::~Task3()
{
    delete ui;
}

void Task3::on_pushButton_clicked()
{
    /*QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open file!"));
        return;
    } */

    QFile file("D:/untitled4/work.txt");
    checkFileForVoidStrings("D://untitled4//work.txt");
    file.open(QIODevice::ReadWrite);
    int n = 0;
    QString line;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line = in.readLine();
        if (line != 0)
            n++;
    }
    n /= 6;
    student *a = new student [n];
    QTextStream q(&file);
    int i = 0;
    q.seek(0);
    while (!q.atEnd())
    {
       a[i].name = q.readLine().toUtf8();
       a[i].speciality = q.readLine().toUtf8();
       a[i].group = q.readLine().toUtf8();
       a[i].mark1 = q.readLine().toUtf8();
       a[i].mark2 = q.readLine().toUtf8();
       a[i].mark3 = q.readLine().toUtf8();
       ++i;
    }

    QWidget *mainWidget1 = new QWidget;
    QVBoxLayout *mainLayout1 = new QVBoxLayout;
    QLabel *label1 = new QLabel;
    if (n != 0) {
        QString data;
        data.toUtf8();
        label1->setText("Студенты не отчисленные:\n");
        for (int i = n - 1; i >= 0; --i)
        {
            if(a[i].mark1.toInt() >= 4 && a[i].mark2.toInt() >= 4 && a[i].mark1.toInt() >= 4)
            {
                label1->setText(label1->text() + "------------------------------------------\n"
                                               "Студент № " + QString::number(n - i) + '\n');
                data = a[i].name + '\n';
                label1->setText(label1->text() + data.toUtf8());
                data = a[i].speciality + '\n';
                label1->setText(label1->text() + data.toUtf8());
                data = a[i].group + '\n';
                label1->setText(label1->text() + data.toUtf8());
                data = a[i].mark1 + '\n';
                label1->setText(label1->text() + data.toUtf8());
                data = a[i].mark2 + '\n';
                label1->setText(label1->text() + data.toUtf8());
                data = a[i].mark3 + '\n';
                label1->setText(label1->text() + data.toUtf8());
                data = "------------------------------------------\n\n";
                label1->setText(label1->text() + data.toUtf8());
            }
        }
    }
    else
        label1->setText("Информация о студентах не найдена!\n"
                       "Добавьте информацию");
    delete [] a;
    mainLayout1->addWidget(label1);
    mainWidget1->setLayout(mainLayout1);
    mainWidget1->show();
}

