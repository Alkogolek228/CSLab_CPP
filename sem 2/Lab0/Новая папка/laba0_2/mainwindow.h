#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QRadioButton>
#include <QButtonGroup>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    QRadioButton *moveButton;
    QRadioButton *scaleButton;
    QRadioButton *rotateButton;
    QButtonGroup *buttonGroup;
    QDockWidget *dock;
    QVBoxLayout *layout;

private slots:
    void modeChanged(QAbstractButton *button);
};
#endif // MAINWINDOW_H

