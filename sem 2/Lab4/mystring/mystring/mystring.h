#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstddef>  // для size_t
#include <memory>   // для умных указателей
#include <iterator> // для итераторов
#include <iostream> // для ввода-вывода

class MyString {
public:
    // типы итераторов
    using iterator = char*;
    using const_iterator = const char*;

    // конструкторы
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other);

    // операторы присваивания
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other);
    MyString& operator=(const char* str);

    // деструктор
    ~MyString();

    // методы для работы с размером строки
    size_t size() const;
    bool empty() const;
    void resize(size_t newSize);

    // методы для работы с символами строки
    const char& operator[](size_t index) const;
    char& operator[](size_t index);
    const char& at(size_t index) const;
    char& at(size_t index);
    void push_back(char c);

    // методы для работы с итераторами
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    // операторы сравнения
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    // операторы конкатенации
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);

    // операторы ввода-вывода
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

private:
    // члены данных
    std::unique_ptr<char[]> m_data;
    size_t m_size;

    // вспомогательный метод для перевыделения памяти
    void reallocate(size_t newCapacity);
};

#endif // MY_STRING_H
