#include "task1.h"
#include "ui_task1.h"
#include <QFile>
#include <QTextStream>

Task1::Task1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task1)
{
    ui->setupUi(this);
}

Task1::~Task1()
{
    delete ui;
}

void *qs1(student *a, int first, int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;

        double middle = a[(left + right) / 2].average_score;
        do
        {
            while (a[left].average_score > middle)
                ++left;
            while (a[right].average_score < middle)
                --right;

            if (left <= right)
            {
                student temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                ++left;
                --right;
            }
        } while (left < right);
        qs(a, first, right);
        qs(a, left, last);
    }
}

void *score(student *a, int n)
{
    for(int i=0; i<n; i++)
    {
        a[i].average_score = (a[i].mark1.toDouble() + a[i].mark3.toDouble() + a[i].mark3.toDouble()) / 3.0;
    }
}

void Task1::on_pushButton_clicked()
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
    student a[n];
    score(a,n);
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
    qs1(a, 0, n - 1);
    QWidget *mainWidget1 = new QWidget;
    QVBoxLayout *mainLayout1 = new QVBoxLayout;
    QLabel *label1 = new QLabel;

    if (n != 0)
    {
        QString data;
        data.toUtf8();
        label1->setText("Топ студентов:\n");

        for (int i = 0; i < n; ++i)
        {
            label1->setText(label1->text() + "------------------------------------------\n"
                                           "Студент № " + QString::number(i + 1) + '\n');
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
            data = a[i].average_score + '\n';
            label1->setText(label1->text() + data.toUtf8());
            data = "------------------------------------------\n\n";
            label1->setText(label1->text() + data.toUtf8());
        }
    }

    else
        label1->setText("Информация о студентах не найдена!\n"
                       "Добавьте информацию");
    mainLayout1->addWidget(label1);
    mainWidget1->setLayout(mainLayout1);
    mainWidget1->show();
}


