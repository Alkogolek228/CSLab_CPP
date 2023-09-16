#include "taskinfo.h"
#include "ui_taskinfo.h"

TaskInfo::TaskInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskInfo)
{
    ui->setupUi(this);
}

TaskInfo::~TaskInfo()
{
    delete ui;
}
