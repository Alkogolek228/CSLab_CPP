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
    void on_AddButton_clicked();

    void on_conButton_clicked();

    void on_findButton_clicked();

    void on_sizeButton_clicked();

    void on_eraseButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
