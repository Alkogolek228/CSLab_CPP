#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bst.h"
#include "findleaf.h"
#include <QTreeWidgetItem>

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
    void on_addButton_clicked();

    void on_searchButton_clicked();

    void on_removeButton_clicked();

    void on_balanceButton_clicked();

    void on_printStraightButton_clicked();

    void on_printBackwardButton_clicked();

    void on_printAscendingButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    BST bst;

    void updateTreeWidget();
    void updatePlainTextEdit(const QStringList& list);
};
#endif // MAINWINDOW_H
