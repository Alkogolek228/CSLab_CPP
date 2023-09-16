#include "widget.h"
#include "ui_widget.h"

#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
#include <QDebug>

#include "hashtable.h"
using namespace QtCharts;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QChart *chart = new QChart();
    chart->setTitle("Search Time vs Table Size");

    QLineSeries *series = new QLineSeries(chart);

    const int n16 = 16;
    int data16[n16];
    const int n64 = 64;
    int data64[n64];
    const int n128 = 128;
    int data128[n128];
    const int n2048 = 2048;
    int data2048[n2048];

    for (int i = 0; i < n16; i++) {
        data16[i] = rand();
    }

    HashTable<int, int> table1(n16);
    for (int i = 0; i < n16; i++)
    {
        table1.add(data16[i], i);
    }

    for (int i = 0; i < n64; i++) {
        data64[i] = rand();
    }

    HashTable<int, int> table2(n64);
    for (int i = 0; i < n64; i++)
    {
        table2.add(data64[i], i);
    }

    for (int i = 0; i < n128; i++) {
        data128[i] = rand();
    }

    HashTable<int, int> table3(n128);
    for (int i = 0; i < n128; i++)
    {
        table3.add(data128[i], i);
    }

    for (int i = 0; i < n2048; i++) {
        data2048[i] = rand();
    }

    HashTable<int, int> table4(n2048);
    for (int i = 0; i < n2048; i++)
    {
        table4.add(data2048[i], i);
    }

    double time16 = table1.searchTime(data16[n16 - 1]);
    double time64 = table2.searchTime(data16[n64 - 1]);
    double time128 = table3.searchTime(data16[n128 - 1]);
    double time2048 = table4.searchTime(data16[n2048 - 1]);

    qDebug() << time16;
    qDebug() << time64;
    qDebug() << time128;
    qDebug() << time2048;

    series->append(16, time16);
    series->append(n64, time64);
    series->append(n128, time128);
    series->append(n2048, time2048);

    chart->addSeries(series);

    // Установим оси координат
    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%d");
    axisX->setTitleText("Table Size");
    axisX->setTickCount(16);
    axisX->setRange(16, 2048);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.3f s");
    axisY->setTitleText("Search Time");
    axisY->setTickCount(5);
    axisY->setRange(0, 10);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Отобразим график
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->show();
}

Widget::~Widget()
{
    delete ui;
}

