#ifndef LIST_H
#define LIST_H

#include <QString>

struct Book {
    QString registrationNumber;
    QString author;
    QString title;
    int yearOfPublication;
    QString publisher;
    int numberOfPages;
};

class List {
public:
    List();

    void addBook(const Book &book);
    void deleteBook(const QString &registrationNumber);
    Book *findBook(const QString &registrationNumber);
    void printAllBooks() const;
    void printBooksByAuthor(const QString &authorLastName) const;
    void printBooksByTitleAndYear(const QString &title, int year) const;

private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int numBooks;
};

#endif // LIST_H
