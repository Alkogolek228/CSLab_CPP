#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load book data from file
    QFile file("books.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 6) {
                Book book;
                book.registrationNumber = fields[0];
                book.author = fields[1];
                book.title = fields[2];
                book.yearOfPublication = fields[3].toInt();
                book.publisher = fields[4];
                book.numberOfPages = fields[5].toInt();
                bookList.addBook(book);
            }
        }
        file.close();
    }

    updateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    // Get book data from user input
    QString registrationNumber = ui-LineEdit->text();
    QString author = ui->authorLineEdit->text();
    QString title = ui->titleLineEdit->text();
    int yearOfPublication = ui->yearSpinBox->value();
    QString publisher = ui->publisherLineEdit->text();
    int numberOfPages = ui->pagesSpinBox->value();

    // Add book to list
    Book book;
    book.registrationNumber = registrationNumber;
    book.author = author;
    book.title = title;
    book.yearOfPublication = yearOfPublication;
    book.publisher = publisher;
    book.numberOfPages = numberOfPages;
    bookList.addBook(book);

    // Save book data to file
    QFile file("books.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << registrationNumber << "," << author << "," << title << "," << yearOfPublication << "," << publisher << "," << numberOfPages << "\n";
        file.close();
    }

    updateTable();

    // Reset input fields
    ui->regNumLineEdit->clear();
    ui->authorLineEdit->clear();
    ui->titleLineEdit->clear();
    ui->yearSpinBox->setValue(QDate::currentDate().year());
    ui->publisherLineEdit->clear();
    ui->pagesSpinBox->setValue(0);
}

void MainWindow::on_deleteButton_clicked()
{
    // Get registration number of book to delete from user input
    QString registrationNumber = ui->deleteLineEdit->text();

    // Remove book from list
    bookList.deleteBook(registrationNumber);

    // Save updated book data to file
    QFile file("books.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < bookList.getNumBooks(); i++) {
            const Book &book = bookList.getBook(i);
            out << book.registrationNumber << "," << book.author << "," << book.title << "," << book.yearOfPublication << "," << book.publisher << "," << book.numberOfPages << "\n";
        }
        file.close();
    }

    updateTable();

    // Reset input field
    ui->deleteLineEdit->clear();
}

void MainWindow::on_findButton_clicked()
{
    // Get registration number of book to find from user input
    QString registrationNumber = ui->findLineEdit->text();

    // Search for book with matching registration number
    const Book *book = bookList.findBook(registrationNumber);

    if (book != nullptr) {
        // Display book data
        ui->outputTextEdit->setText(QString("Registration Number: %1\nAuthor: %2\nTitle: %3\nYear of Publication: %4\nPublisher: %5\nNumber of Pages: %6")
                                     .arg(book->registrationNumber)
                                     .arg(book->author)
                                     .arg(book->title)
                                     .arg(book->yearOfPublication)
                                     .arg(book->publisher)
                                     .arg(book->numberOfPages));
    } else {
        // Book not found
        QMessageBox::information(this, "Book not found", "The book with the specified registration number could not be found.");
    }

    // Reset input field
    ui->findLineEdit->clear();
}

void MainWindow::on_searchButton_clicked()
{
// Get author name to search for from user input
QString author = ui->searchLineEdit->text();
// Search for books by author
QList<const Book*> books = bookList.searchBooksByAuthor(author);

if (books.isEmpty()) {
    // No books found
    QMessageBox::information(this, "No books found", "No books were found by the specified author.");
} else {
    // Display book data for all found books
    QString output;
    for (const Book *book : books) {
        output += QString("Registration Number: %1\nAuthor: %2\nTitle: %3\nYear of Publication: %4\nPublisher: %5\nNumber of Pages: %6\n\n")
                  .arg(book->registrationNumber)
                  .arg(book->author)
                  .arg(book->title)
                  .arg(book->yearOfPublication)
                  .arg(book->publisher)
                  .arg(book->numberOfPages);
    }
    ui->outputTextEdit->setText(output);
}

// Reset input field
ui->searchLineEdit->clear();
}

void MainWindow::on_checkButton_clicked()
{
// Get title and year of publication to search for from user input
QString title = ui->titleLineEdit_2->text();
int year = ui->yearSpinBox_2->value();
// Search for books by title and year of publication
QList<const Book*> books = bookList.searchBooksByTitleAndYear(title, year);

if (books.isEmpty()) {
    // No books found
    QMessageBox::information(this, "No books found", "No books were found by the specified title and year of publication.");
} else {
    // Display book data for all found books
    QString output;
    for (const Book *book : books) {
        output += QString("Registration Number: %1\nAuthor: %2\nTitle: %3\nYear of Publication: %4\nPublisher: %5\nNumber of Pages: %6\n\n")
                  .arg(book->registrationNumber)
                  .arg(book->author)
                  .arg(book->title)
                  .arg(book->yearOfPublication)
                  .arg(book->publisher)
                  .arg(book->numberOfPages);
    }
    ui->outputTextEdit->setText(output);
}

// Reset input fields
ui->titleLineEdit_2->clear();
ui->yearSpinBox_2->setValue(QDate::currentDate().year());
}

void MainWindow::updateTable()
{
// Clear table
ui->bookTableWidget->setRowCount(0);
// Populate table with book data
for (int i = 0; i < bookList.getNumBooks(); i++) {
    const Book &book = bookList.getBook(i);
    QTableWidgetItem *regNumItem = new QTableWidgetItem(QString::number(book.registrationNumber));
    QTableWidgetItem *authorItem = new QTableWidgetItem(book.author);
    QTableWidgetItem *titleItem = new QTableWidgetItem(book.title);
    QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(book.yearOfPublication));
    QTableWidgetItem *publisherItem = new QTableWidgetItem(book.publisher);
    QTableWidgetItem *numPagesItem = new QTableWidgetItem(QString::number(book.numberOfPages));
    ui->bookTableWidget->insertRow(i);
    ui->bookTableWidget->setItem(i, 0, regNumItem);
    ui->bookTableWidget->setItem(i, 1, authorItem);
    ui->bookTableWidget->setItem(i, 2, titleItem);
    ui->bookTableWidget->setItem(i, 3, yearItem);
    ui->bookTableWidget->setItem(i, 4, publisherItem);
    ui->bookTableWidget->setItem(i, 5, numPagesItem);
    }
    }

    void MainWindow::on_addButton_clicked()
    {
    // Get book data from user input
    int registrationNumber = ui->regNumSpinBox->value();
    QString author = ui->authorLineEdit->text();
    QString title = ui->titleLineEdit->text();
    int yearOfPublication = ui->yearSpinBox->value();
    QString publisher = ui->publisherLineEdit->text();
    int numberOfPages = ui->numPagesSpinBox->value();
    // Add book to list
    if (bookList.addBook(registrationNumber, author, title, yearOfPublication, publisher, numberOfPages)) {
        // Book added successfully
        QMessageBox::information(this, "Book added", "The book was added to the library.");
        updateTable();
        saveToFile();
    } else {
        // Book already exists
        QMessageBox::warning(this, "Book already exists", "The book with the specified registration number already exists in the library.");
    }

    // Reset input fields
    ui->regNumSpinBox->setValue(1);
    ui->authorLineEdit->clear();
    ui->titleLineEdit->clear();
    ui->yearSpinBox->setValue(QDate::currentDate().year());
    ui->publisherLineEdit->clear();
    ui->numPagesSpinBox->setValue(1);
    }

    void MainWindow::on_deleteButton_clicked()
    {
    // Get registration number of book to delete from user input
    int registrationNumber = ui->deleteSpinBox->value();
    // Delete book from list
    if (bookList.deleteBook(registrationNumber)) {
        // Book deleted successfully
        QMessageBox::information(this, "Book deleted", "The book was deleted from the library.");
        updateTable();
        saveToFile();
    } else {
        // Book not found
        QMessageBox::warning(this, "Book not found", "The book with the specified registration number could not be found in the library.");
    }

    // Reset input field
    ui->deleteSpinBox->setValue(1);

    }

    void MainWindow::loadFromFile()
    {
    // Open file for reading
    QFile file("library.txt");
    if (!file.open(QIODevice::ReadOnly)) {
    QMessageBox::warning(this, "Error", "Could not open file for reading.");
    return;
    }

    // Read data from file and add to book list
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("|");
        if (fields.size() == 6) {
            int registrationNumber = fields[0].toInt();
            QString author = fields[1];
            QString title = fields[2];
            int yearOfPublication = fields[3].toInt();
            QString publisher = fields[4];
            int numberOfPages = fields[5].toInt();
            bookList.addBook(registrationNumber, author, title, yearOfPublication, publisher, numberOfPages);
        }
        }

    // Close file
    file.close();

    // Update table with loaded data
    updateTable();
    }

    void MainWindow::saveToFile()
    {
    // Open file for writing
    QFile file("library.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QMessageBox::warning(this, "Error", "Could not open file for writing.");
    return;
    }

    // Write data from book list to file
    QTextStream out(&file);
    for (int i = 0; i < bookList.getSize(); i++) {
        Book book = bookList.getBook(i);
        out << book.registrationNumber << "|"
            << book.author << "|"
            << book.title << "|"
            << book.yearOfPublication << "|"
            << book.publisher << "|"
            << book.numberOfPages << "\n";
    }

    // Close file
    file.close();

    }

    void MainWindow::on_actionSave_triggered()
    {
    // Save book list to file
    saveToFile();
    }

    void MainWindow::on_actionLoad_triggered()
    {
    // Load book list from file
    loadFromFile();
    }

    void MainWindow::on_actionExit_triggered()
    {
    // Exit the program
    QApplication::exit();
    }

    void MainWindow::saveToFile()
    {
    QFile file("books.txt");
    if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::warning(this, "Error", "Could not save data to file.");
    return;
    }
    QTextStream out(&file);
    for (int i = 0; i < bookList.getSize(); i++) {
        Book book = bookList.getBook(i);
        out << book.registrationNumber << "," << book.author << ","
            << book.title << "," << book.yearOfPublication << ","
            << book.publisher << "," << book.numberOfPages << "\n";
    }

    file.close();

    void MainWindow::saveToFile()
    {
    QFile file("books.txt");
    if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::warning(this, "Error", "Could not save data to file.");
    return;
    }

    bash
    Copy code
    QTextStream out(&file);
    for (int i = 0; i < bookList.getSize(); i++) {
        Book book = bookList.getBook(i);
        out << book.registrationNumber << "," << book.author << ","
            << book.title << "," << book.yearOfPublication << ","
            << book.publisher << "," << book.numberOfPages << "\n";
    }

    file.close();
    }

    void MainWindow::loadFromFile()
    {
    QFile file("books.txt");
    if (!file.open(QIODevice::ReadOnly)) {
    return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 6) {
            QString regNumber = fields.at(0);
            QString author = fields.at(1);
            QString title = fields.at(2);
            int year = fields.at(3).toInt();
            QString publisher = fields.at(4);
            int pages = fields.at(5).toInt();
            Book book(regNumber, author, title, year, publisher, pages);
            bookList.addBook(book);
        }
    }

    file.close();
    }

    void MainWindow::closeEvent(QCloseEvent *event)
    {
    // Save data to file before closing
    saveToFile();

    event->accept();
    }

    MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    {
    ui->setupUi(this);

    // Load data from file
    loadFromFile();

    // Update table
    updateTable();
    }

    MainWindow::~MainWindow()
    {
    delete ui;
    }


