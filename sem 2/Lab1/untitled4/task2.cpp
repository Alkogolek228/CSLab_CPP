#include "task2.h"
#include "ui_task2.h"
#include <QFile>
#include <QTextStream>
#include <QString>

Task2::Task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task2)
{
    ui->setupUi(this);
}

Task2::~Task2()
{
    delete ui;
}

void *qs21(student *a, int first, int last)  {
    if (first < last) {
        int left = first;
        int right = last;
       double middle = a[(left + right) / 2].average_score;
        do {
            while (a[left].average_score < middle)
                ++left;
            while (a[right].average_score > middle)
                --right;
            if (left <= right) {
                student temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                ++left;
                --right;
            }
        } while (left < right);
        qs21(a, first, right);
        qs21(a, left, last);
    }
}

void Task2::on_pushButton_clicked()
{
    QFile file("D://untitled4//work.txt");
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
    qs21(a, 0, n - 1);
    QString temp = ui -> lineEdit -> text();
    QWidget *mainWidget1 = new QWidget;
    QVBoxLayout *mainLayout1 = new QVBoxLayout;
    QLabel *label1 = new QLabel;
    if (n != 0) {
        QString data;
        data.toUtf8();
        label1->setText("Топ студентов по среднему баллу:\n");
        for (int i = n - 1; i >= 0; --i)
        {
            if(a[i].group == temp)
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

