#include "mystring.h"
#include <cstring>

// Конструктор по умолчанию создает пустую строку
MyString::MyString()
    : m_data(new char[1]), m_size(0)
{
    m_data[0] = '\0';
}

// Конструктор копирования создает новую строку,
// которая является копией другой строки
MyString::MyString(const MyString& other)
    : m_data(new char[other.m_size + 1]), m_size(other.m_size)
{
    std::memcpy(m_data.get(), other.m_data.get(), m_size + 1);
}

// Конструктор перемещения переносит данные из
// другой строки в новую строку
MyString::MyString(MyString&& other)
    : m_data(std::move(other.m_data)), m_size(other.m_size)
{
    other.m_size = 0;
}

// Конструктор от C-style строки создает новую строку,
// которая является копией переданной строки
MyString::MyString(const char* str)
    : m_data(new char[std::strlen(str) + 1]), m_size(std::strlen(str))
{
    std::memcpy(m_data.get(), str, m_size + 1);
}

// Оператор присваивания копированием
MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        m_data.reset(new char[other.m_size + 1]);
        std::memcpy(m_data.get(), other.m_data.get(), other.m_size + 1);
        m_size = other.m_size;
    }
    return *this;
}

// Оператор присваивания перемещением
MyString& MyString::operator=(MyString&& other)
{
    if (this != &other)
    {
        m_data = std::move(other.m_data);
        m_size = other.m_size;
        other.m_size = 0;
    }
    return *this;
}

// Оператор присваивания от C-style строки
MyString& MyString::operator=(const char* str)
{
    m_data.reset(new char[std::strlen(str) + 1]);
    std::memcpy(m_data.get(), str, std::strlen(str) + 1);
    m_size = std::strlen(str);
    return *this;
}

// Деструктор освобождает выделенную память
MyString::~MyString()
{
}

// Метод size возвращает количество символов в строке
size_t MyString::size() const
{
    return m_size;
}

// Метод empty возвращает true, если строка пустая, и false в противном случае
bool MyString::empty() const
{
    return m_size == 0;
}

// Метод resize изменяет размер строки
void MyString::resize(size_t newSize)
{
    if (newSize > m_size)
    {
        // Выделяем новый буфер, копируем в него старые данные и заполняем остаток нулями
        char* newData = new char[newSize + 1];
        std::memcpy(newData, m_data.get(), m_size);
        std::memset(newData + m_size, '\0', newSize - m_size);
        m_data.reset(newData);
        m_size = newSize;
    }
    else
    {
        // Обрезаем строку до нового размера
        m_data.get()[newSize] = '\0';
        m_size = newSize;
    }
}

// Метод push_back добавляет символ в конец строки
void MyString::push_back(char c)
{
    // Выделяем новый буфер, копируем в него старые данные и добавляем новый символ в конец
    char* newData = new char[m_size + 2];
    std::memcpy(newData, m_data.get(), m_size);
    newData[m_size] = c;
    newData[m_size + 1] = '\0';
    m_data.reset(newData);
    ++m_size;
}

// Оператор доступа к элементам строки по индексу
char& MyString::operator[](size_t index)
{
    return m_data.get()[index];
}

// Константный оператор доступа к элементам строки по индексу
const char& MyString::operator[](size_t index) const
{
    return m_data.get()[index];
}

// Метод begin возвращает итератор на первый символ строки
MyString::iterator MyString::begin()
{
    return iterator(m_data.get());
}

// Метод end возвращает итератор на символ, следующий за последним символом строки
MyString::iterator MyString::end()
{
    return iterator(m_data.get() + m_size);
}

// Метод begin возвращает константный итератор на первый символ строки
MyString::const_iterator MyString::begin() const
{
    return const_iterator(m_data.get());
}

// Метод end возвращает константный итератор на символ, следующий за последним символом строки
MyString::const_iterator MyString::end() const
{
    return const_iterator(m_data.get() + m_size);
}

// Оператор сравнения строк на равенство
bool operator==(const MyString& lhs, const MyString& rhs)
{
    return lhs.size() == rhs.size() && std::strcmp(lhs.data(), rhs.data()) == 0;
}

// Оператор сравнения строк на неравенство
bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs == rhs);
}

// Оператор сравнения строк на меньше
bool operator<(const MyString& lhs, const MyString& rhs)
{
    return std::strcmp(lhs.m_data.get(), rhs.m_data.get()) < 0;
}

// Оператор сравнения строк на больше
bool operator>(const MyString& lhs, const MyString& rhs)
{
    return rhs < lhs;
}

// Оператор сравнения строк на меньше или равно
bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return !(rhs < lhs);
}

// Оператор сравнения строк на больше или равно
bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs < rhs);
}

// Оператор конкатенации строк
MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString result(lhs);
    result += rhs;
    return result;
}

// Оператор ввода строки из потока
std::istream& operator>>(std::istream& is, MyString& str)
{
    std::string temp;
    is >> temp;
    str = MyString(temp.c_str());
    return is;
}

// Оператор вывода строки в поток
std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.c_str();
    return os;
}


int main()
{
  
}