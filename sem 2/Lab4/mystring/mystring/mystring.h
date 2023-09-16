#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstddef>  // ��� size_t
#include <memory>   // ��� ����� ����������
#include <iterator> // ��� ����������
#include <iostream> // ��� �����-������

class MyString {
public:
    // ���� ����������
    using iterator = char*;
    using const_iterator = const char*;

    // ������������
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other);

    // ��������� ������������
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other);
    MyString& operator=(const char* str);

    // ����������
    ~MyString();

    // ������ ��� ������ � �������� ������
    size_t size() const;
    bool empty() const;
    void resize(size_t newSize);

    // ������ ��� ������ � ��������� ������
    const char& operator[](size_t index) const;
    char& operator[](size_t index);
    const char& at(size_t index) const;
    char& at(size_t index);
    void push_back(char c);

    // ������ ��� ������ � �����������
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    // ��������� ���������
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    // ��������� ������������
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);

    // ��������� �����-������
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

private:
    // ����� ������
    std::unique_ptr<char[]> m_data;
    size_t m_size;

    // ��������������� ����� ��� ������������� ������
    void reallocate(size_t newCapacity);
};

#endif // MY_STRING_H
