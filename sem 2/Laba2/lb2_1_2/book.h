#ifndef BOOK_H
#define BOOK_H

#include <QDialog>
#include "QTime"

namespace Ui {
class bus;
}

class bus : public QDialog
{
    Q_OBJECT

public:
    explicit bus(QWidget *parent = nullptr);
    ~bus();

private:
    Ui::bus *ui;
};

#endif // BOOK_H

class Book{
private:
    QString regnumber;
    QString author;
    QString name;
    QString year;
    QString publisher;
    QString num_sheets;
public:
    void set_regnumber(QString regnumber);
    void set_name(QString name);
    void set_author(QString author);
    void set_num_sheets(QString num_sheets);
    void set_year(QString year);
    void set_publisher(QString publisher);


    QString get_regnumber() const;
    QString get_author() const;
    QString get_name() const;
    QString get_year() const;
    QString get_publisher() const;
    QString get_num_sheets() const;
};
