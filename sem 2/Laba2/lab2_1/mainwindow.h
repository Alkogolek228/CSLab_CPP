#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "list.h"
#include<QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void sort(Student *, int );
private slots:
    void on_Open_file_button_clicked();

    void on_Add_button_clicked();

    void on_show_list_button_clicked();

    void on_find_button_clicked();

    void on_Add_in_file_button_clicked();

    void on_radioButton_toggled(bool checked);

    void on_delete_button_clicked();

    void on_Change_clicked();

    void on_write_in_file_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QString fileName1;
    QFile file;
    QFile file1;
    bool flag=1;
    List list;
    int size=0;
    float average_mark;
    int counter=0;
    QString memory;
    int res=0;
    void sort(struct Node**);
    void frontBackSplit(struct Node*, struct Node**, struct Node**);
    struct Node* sortedMerge(struct Node* , struct Node* );
    Student arr[10];
    int arr_size;
};
#endif // MAINWINDOW_H
