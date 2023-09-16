#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_findButton_clicked();
    void on_authorButton_clicked();
    void on_titleButton_clicked();
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
    List bookList;

    void updateTable();
};

#endif // MAINWINDOW_H
