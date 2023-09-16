#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene;
    rect = new QGraphicsRectItem(0, 0, 100, 100);
    scene->addItem(rect);

    QGraphicsView *view = new QGraphicsView(scene);

    setCentralWidget(view);

    QDockWidget *dock = new QDockWidget(tr("Controls"), this);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    QWidget *widget = new QWidget;
    dock->setWidget(widget);

    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);

    buttonGroup = new QButtonGroup;

    QRadioButton *moveButton = new QRadioButton(tr("Move"));
    layout->addWidget(moveButton);
    buttonGroup->addButton(moveButton);

    QRadioButton *scaleButton = new QRadioButton(tr("Scale"));
    layout->addWidget(scaleButton);
    buttonGroup->addButton(scaleButton);

    QRadioButton *rotateButton = new QRadioButton(tr("Rotate"));
    layout->addWidget(rotateButton);
    buttonGroup->addButton(rotateButton);

    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(modeChanged(QAbstractButton*)));
    qDebug() << "Button group connection status:" << connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(modeChanged(QAbstractButton*)));


}

MainWindow::~MainWindow()
{

}

void MainWindow::modeChanged(QAbstractButton *button)
{
    qDebug() << "modeChanged called with button:" << button->text();

    if (moveButton->isChecked())
    {
        rect->setFlag(QGraphicsItem::ItemIsMovable, true);
        qDebug() << "Move button selected, item is movable";
    }

    else
    {
        rect->setFlag(QGraphicsItem::ItemIsMovable, false);
        qDebug() << "Scale button selected, item is not movable";
    }
}






