#ifndef MYSTRING_H
#define MYSTRING_H

#include "mystring_global.h"
#include <iostream>
#include <cstdio>
#include <cerrno>
#include <cstring>

template<typename T>
class MyUniquePtr
{
public:
    MyUniquePtr(T* ptr = nullptr) : m_ptr(ptr) { }

    ~MyUniquePtr()
    {
        if (m_ptr)
        {
            delete m_ptr;
        }
    }

    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept
    {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            if (m_ptr)
            {
                delete m_ptr;
            }
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    T* get() const
    {
        return m_ptr;
    }

    T& operator*() const
    {
        return *m_ptr;
    }

    T* operator->() const
    {
        return m_ptr;
    }

    void reset(T* ptr = nullptr)
    {
        if (m_ptr)
        {
            delete m_ptr;
        }
        m_ptr = ptr;
    }

    void swap(MyUniquePtr& other) noexcept
    {
        T* tmp = m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = tmp;
    }

    operator bool() const
    {
        return m_ptr != nullptr;
    }

private:
    T* m_ptr;
};

class MyStringIterator
{
public:

    MyStringIterator(){ }
    MyStringIterator(char* ptr) : m_ptr(ptr) { }
    ~MyStringIterator(){ }

    MyStringIterator& operator++()
    {
        ++m_ptr;
        return *this;
    }

    MyStringIterator operator++(int)
    {
        MyStringIterator tmp = *this;
        ++m_ptr;
        return tmp;
    }

    MyStringIterator& operator--()
    {
        --m_ptr;
        return *this;
    }


    MyStringIterator operator--(int)
    {
        MyStringIterator tmp = *this;
        --m_ptr;
        return tmp;
    }

    char& operator*() const
    {
        return *m_ptr;
    }

    char* operator->() const
    {
        return m_ptr;
    }

    bool operator==(const MyStringIterator& other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const MyStringIterator& other) const
    {
        return m_ptr != other.m_ptr;
    }

    MyStringIterator& operator=(const MyStringIterator &tmp)
    {
        m_ptr=tmp.m_ptr;
    }

    operator char*() const
    {
        return m_ptr;
    }

    MyStringIterator& begin();
    MyStringIterator& end();


private:
    char* m_ptr;
};

class MYSTRING_EXPORT Mystring : public MyStringIterator
{
public:
        // Конструкторы

    Mystring() : m_size(0)
    {
        m_data = MyUniquePtr<char>(new char[1]);
        m_data.get()[0] = '\0';
    }

    Mystring(const char* str) : m_size(mystrlen(str))
    {
        m_data = MyUniquePtr<char>(new char[m_size + 1]);
        mystrcpy(m_data.get(), str);
    }

    Mystring(const Mystring& other) : m_size(other.m_size)
    {
        m_data = MyUniquePtr<char>(new char[m_size + 1]);
        mystrcpy(m_data.get(), other.m_data.get());
    }

    Mystring(const std::string& str) : m_size(str.length())
    {
        m_data = MyUniquePtr<char>(new char[m_size + 1]);
        mystrcpy(m_data.get(), str.c_str());
    }

    Mystring& operator=(const Mystring& other)
    {
        if (this != &other)
        {
            m_size = other.m_size;
            m_data = MyUniquePtr<char>(new char[m_size + 1]);
            mystrcpy(m_data.get(), other.m_data.get());
        }
        return *this;
    }

    // Деструктор
    ~Mystring() = default;

    // Доступ к символам
    char& operator[](int index)
    {
        return m_data.get()[index];
    }

    const char& operator[](int index) const
    {
        return m_data.get()[index];
    }


    // Доступ к данным
    const char* c_str() const
    {
        return m_data.get();
    }

    // Размер строки
    int size() const
    {
        return m_size;
    }

    // Операторы сравнения
    bool operator==(const Mystring& other) const
    {
        return mystrcmp(m_data.get(), other.m_data.get()) == 0;
    }

    bool operator!=(const Mystring& other) const
    {
        return !(*this == other);
    }
    bool operator<(const Mystring& other) const
    {
            return mystrcmp(m_data.get(), other.m_data.get()) < 0;
    }

    bool operator>(const Mystring& other) const
    {
        return mystrcmp(m_data.get(), other.m_data.get()) > 0;
    }

    // Добавление символа в конец строки
        void push_back(const char c)
        {
            MyUniquePtr<char> new_data(new char[m_size + 2]);
            mystrcpy(new_data.get(), m_data.get());
            new_data.get()[m_size] = c;
            new_data.get()[m_size + 1] = '\0';
            m_data = std::move(new_data);
            ++m_size;
        }



    typedef MyStringIterator iterator;

    iterator begin()
    {
        return iterator(m_data.get());
    }

    iterator end()
    {
        return iterator(m_data.get() + m_size);
    }

    int mystrcmp(const char* s1, const char* s2) const
    {
        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
        {
            ++s1;
            ++s2;
        }
        return static_cast<int>(*s1) - static_cast<int>(*s2);
    }

    char* mystrcpy(char* s1, const char* s2)
    {
        if(s1==NULL) return s1;
        int i=0;
        while(s2[i]!='\0')

        {        s1[i]=s2[i];
            i++;
        }
        s1[i]='\0';

        return s1;
    }

    size_t mystrlen(const char* s)
    {
        size_t counter = 0;
        while (true)
         {
           if (s[counter] == '\0')
           {
              break;
           }
           counter++;
         }
        return counter;
    }

    void* mymemset(void* s,int c,size_t n)
    {
        size_t i;
        char* ss=(char*)s;

        for(i=0;i<n;i++)
        {
            ss[i]=c;
        }
        return s;
    }

    void* mymemcpy(void* s1, const void* s2, size_t n)
    {
        if(s1==nullptr) return NULL;

        uint8_t* ptr = (uint8_t*) s1;
        uint8_t* ptr1 = (uint8_t*) s2;

        for(size_t i=0;i<n;i++)
        {
            ptr[i]=ptr1[i];
        }
        return s1;
    }

    void* mymemmove(void* s1, const void* s2, size_t n)
    {
        uint8_t* d = (uint8_t*)s1;
        const uint8_t* s = (uint8_t*)s2;
        if (d < s)
         while (n--)
            *d++ = *s++;
        else
        {
            uint8_t* lasts = (uint8_t*)s + (n - 1);
            uint8_t* lastd = d + (n - 1);
              while (n--)
                 *lastd-- = *lasts--;
        }
        return s1;
    }


    char* mystrncpy(char* s1, const char* s2, size_t n)
    {
        if(s1==NULL || s2==NULL || n==0)
        {
            return s1;
        }

        size_t i=0;
        while(i<n && s2[i]!='\0')
        {
            s1[i]=s2[i];
            i++;
        }

        while(i<n)
        {
            s1[i]='\0';
            i++;
        }

        return s1;
    }

    char* mystrcat(char* s1, const char* s2)
    {
        size_t i=0,j=0;
        while(s1[i]!='\0')
        {
            i++;
        }

        while(s2[j]!='\0')
        {
            s1[i]=s2[j];
            i++;
            j++;
        }

        s1[i]='\0';

        return s1;
    }

    char* mystrncat(char* s1, const char* s2, size_t n)
    {
        char* temp = s1;
        while (*s1)
        {
            s1++;
        }
        while (n-- && *s2)
        {
            *s1++ = *s2++;
        }
        *s1 = '\0';
        return temp;

    }


    int mystrncmp(const char* s1, const char* s2, size_t n)
    {
        while (--n && *s1==*s2)
        {
            if (*s1=='\0')
                return 1;
            //else {}
            s1++;
            s2++;
        }

        return (*s1 - *s2);

    }

    int mymemcmp(const void* s1, const void* s2, size_t n)
    {
        const char* str1 = (char*)s1;
        const char* str2 = (char*)s2;

        while ((n--) > 0)
        {
            if (*str1++ != *str2++)
                return str1[-1] < str2[-1] ? -1 : 1;
        }
        return 0;
    }

    int mystrcoll(const char* s1, const char* s2)
    {
        while (*s1 != '\0' && *s2 != '\0')
        {
            if (*s1 < *s2)
            {
                return -1;
            }
            else if (*s1 > *s2)
            {
                return 1;
            }
            s1++;
            s2++;
        }
        if (*s1 == '\0' && *s2 == '\0')
        {
            return 0;
        }
        else if (*s1 == '\0')
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    size_t mystrxfrm(char* s1, const char* s2, size_t n)
    {
        size_t i = 0;
        while (*s2 != '\0' && i < n)
        {
            *s1 = *s2;
            s1++;
            s2++;
            i++;
        }
        *s1 = '\0';
        return i;
    }

    char* mystrchr(const char* str, int ch)
    {
        while (*str != '\0')
        {
            if (*str == ch)
            {
                return const_cast<char*>(str);
            }
            ++str;
        }
        return nullptr;
    }

    size_t mystrspn(const char* s1, const char* s2)
    {
        size_t count = 0;
        while (*s1 != '\0' && mystrchr(s2, *s1) != nullptr)
        {
            ++count;
            ++s1;
        }
        return count;
    }

    size_t mystrcspn(const char* s1, const char* s2)
    {
        const char* p = s1;
        while (*p != '\0')
        {
            if (mystrchr(s2, *p) != nullptr)
            {
                return p - s1;
            }
            ++p;
        }
        return p - s1;
    }

    char* mystrtok(char* s1, const char* s2)
    {
        static char* p = nullptr;
        if (s1 != nullptr)
        {
            p = s1;
        }
        else if (p == nullptr)
        {
            return nullptr;
        }

        // Пропустить разделители в начале строки
        p += mystrspn(p, s2);
        if (*p == '\0')
        {
            return nullptr;
        }

        // Найти конец токена
        char* token = p;
        p += mystrcspn(p, s2);
        if (*p != '\0')
        {
            *(p++) = '\0';
        }

        return token;
    }

    char* mystrerror(int errnum)
    {
        static char buf[256];
        char* str = strerror(errnum);
        if (str != nullptr)
        {
            strncpy(buf, str, sizeof(buf) - 1);
            buf[sizeof(buf) - 1] = '\0';
            return buf;
        }
        snprintf(buf, sizeof(buf), "Unknown error: %d", errnum);
        return buf;
    }

private:
    MyUniquePtr<char> m_data;
    int m_size;
};

#endif // MYSTRING_H
