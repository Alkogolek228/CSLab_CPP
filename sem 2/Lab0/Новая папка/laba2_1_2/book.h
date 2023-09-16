#ifndef BOOK_H
#define BOOK_H

#include <QtWidgets>

class Book
{
public:
    Book();
    QString registrationNumber;
    QString author;
    QString title;
    QString yearOfPublication;
    QString publisher;
    QString numberOfPages;
    bool available;
};

#endif // BOOK_H
