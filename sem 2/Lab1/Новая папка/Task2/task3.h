#ifndef TASK3_H
#define TASK3_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Task3;
}

void *qs21(student *a, int first, int last);

class Task3 : public QDialog
{
    Q_OBJECT

public:
    explicit Task3(QWidget *parent = nullptr);
    ~Task3();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Task3 *ui;
};

#endif // TASK3_H
