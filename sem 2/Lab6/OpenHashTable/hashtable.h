#ifndef HASHTABLE_H
#define HASHTABLE_H

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <stdexcept>
#include <QDebug>

template <typename K, typename V>
class HashTable
{
private:
    struct Element
    {
        K key;
        V value;
        bool deleted;
        int h;
    };

    Element* table;
    int size;
    int count;

    // Генерация случайного числа в диапазоне [0, p-1]
    int random(int p)
    {
        return std::rand() % p;
    }

    // Хеш-функция универсального хеширования
    int hash(K key)
    {
        int a = rand() % size;
        int b = rand() % size;
        int p = generatePrime(size + 1, 2 * size);
        return ((a * key + b) % p) % size;
    }

    int generatePrime(int minVal, int maxVal)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(minVal, maxVal);
        int p = dis(gen);
        while (!isPrime(p))
        {
            p = dis(gen);
        }
        return p;
    }

    // Проверка, является ли число простым
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        if (n <= 3)
        {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0)
        {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table = new Element[size];

        for (int i = 0; i < size; i++)
        {
            table[i].deleted = true;
            table[i].h = random(size);
        }
        count = 0;
    }

    ~HashTable()
    {
        delete[] table;
    }

    void add(K key, V value)
    {
        int h = hash(key);
        while (!table[h].deleted && table[h].key != key)
        {
            h = (h + 1) % size;
        }
        if (table[h].deleted)
        {
            count++;
        }
        table[h].key = key;
        table[h].value = value;
        table[h].deleted = false;
    }

    double searchTime(K key)
    {
        auto start = std::chrono::high_resolution_clock::now();
        get(key);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        return elapsed.count();
    }

    V get(K key)
    {
        int h = hash(key);
        size_t c = 0;
        while (!table[h].deleted && table[h].key != key)
        {
            h = (h + 1) % size;
            qDebug() << table[h].key << " " << key <<"\n";
            ++c;
            if (c == size)
            {
                break;
            }


        }

        if (table[h].deleted || table[h].key != key)
        {
            throw std::out_of_range("Key not found");
        }
        return table[h].value;
    }

    void remove(K key)
    {
        int h = hash(key);
        while (!table[h].deleted && table[h].key != key)
        {
            h = (h + 1) % size;
        }
        if (!table[h].deleted && table[h].key == key)
        {
            table[h].deleted = true;
            count--;
        }
    }

    bool contains(K key)
    {
        int h = hash(key);
        while (!table[h].deleted && table[h].key != key)
        {
            h = (h + 1) % size;
        }
        return !table[h].deleted && table[h].key == key;
    }

    void print()
    {
        qDebug() << "HashTable(size=" << size << ", count=" << count << "):" << "\n";
        for (int i = 0; i < size; i++)
        {
            if (!table[i].deleted)
            {
                qDebug() << "[" << i << "] = (" << table[i].key << ", " << table[i].value << ")" << "\n";
            }
        }
    }
};

#endif // HASHTABLE_H
