#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_push_back_clicked();

    void on_push_front_clicked();

    void on_pop_back_clicked();

    void on_pop_front_clicked();

    void on_clear_clicked();

    void on_size_clicked();

    void on_empty_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
