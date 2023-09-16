#ifndef TASKINFO_H
#define TASKINFO_H

#include <QDialog>

namespace Ui {
class TaskInfo;
}

class TaskInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TaskInfo(QWidget *parent = nullptr);
    ~TaskInfo();

private:
    Ui::TaskInfo *ui;
};

#endif // TASKINFO_H
