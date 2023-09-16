#ifndef TASK2_H
#define TASK2_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Task2;
}

void *qs11(student *a, int first, int last);

class Task2 : public QDialog
{
    Q_OBJECT

public:
    explicit Task2(QWidget *parent = nullptr);
    ~Task2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Task2 *ui;
};

#endif // TASK2_H
