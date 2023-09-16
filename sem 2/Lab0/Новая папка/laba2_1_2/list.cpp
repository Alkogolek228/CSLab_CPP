#include "list.h"
#include <QDebug>

List::List() {
    numBooks = 0;
}

void List::addBook(const Book &book) {
    books[numBooks] = book;
    numBooks++;
}

void List::deleteBook(const QString &registrationNumber) {
    for (int i = 0; i < numBooks; i++) {
        Book &book = books[i];
        if (book.registrationNumber == registrationNumber) {
            // Move all books after the deleted book one position to the left
            for (int j = i; j < numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            numBooks--;
            break;
        }
    }
}

Book *List::findBook(const QString &registrationNumber) {
    for (int i = 0; i < numBooks; i++) {
        Book &book = books[i];
        if (book.registrationNumber == registrationNumber) {
            return &book;
        }
    }
    return nullptr;
}

void List::printAllBooks() const {
    for (int i = 0; i < numBooks; i++) {
        const Book &book = books[i];
        qDebug() << book.registrationNumber << book.author << book.title << book.yearOfPublication << book.publisher << book.numberOfPages;
    }
}

void List::printBooksByAuthor(const QString &authorLastName) const {
    for (int i = 0; i < numBooks; i++) {
        const Book &book = books[i];
        if (book.author.endsWith(authorLastName)) {
            qDebug() << book.registrationNumber << book.author << book.title << book.yearOfPublication << book.publisher << book.numberOfPages;
        }
    }
}

void List::printBooksByTitleAndYear(const QString &title, int year) const {
    for (int i = 0; i < numBooks; i++) {
        const Book &book = books[i];
        if (book.title == title && book.yearOfPublication == year) {
            qDebug() << book.registrationNumber << book.author << book.title << book.yearOfPublication << book.publisher << book.numberOfPages;
        }
    }
}
