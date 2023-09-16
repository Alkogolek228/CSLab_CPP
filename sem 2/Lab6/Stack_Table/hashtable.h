#ifndef HASHTABLE_H
#define HASHTABLE_H

#pragma once
#include <iostream>

const int TABLE_SIZE = 10;

class HashTable
{
protected:
    struct Node
    {
        int key;
        int value;
        Node* next;
    };

    Node* table[TABLE_SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Node* curr = table[i];
            while (curr != nullptr)
            {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            table[i] = nullptr;
        }
    }

    int hash(int key)
    {
        return key % TABLE_SIZE;
    }

    void put(int key, int value)
    {
        int index = hash(key);
        Node* curr = table[index];
        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = table[index];
        table[index] = newNode;
    }

    int get(int key)
    {
        int index = hash(key);
        Node* curr = table[index];
        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key)
    {
        int index = hash(key);
        Node* curr = table[index];
        Node* prev = nullptr;
        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    int size()
    {
        int count = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Node* curr = table[i];
            while (curr != nullptr)
            {
                count++;
                curr = curr->next;
            }
        }
        return count;
    }

    void print(std::string& str)
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            str += "[" + std::to_string(i) + "]: ";
            Node* curr = table[i];
            while (curr != nullptr)
            {
                str+= "(" + std::to_string(curr->key) + ", " + std::to_string(curr->value) + ")";
                curr = curr->next;
                if (curr != nullptr)
                {
                    str+= " -> ";
                }
            }
            str += "\n";
        }
    }
};
#endif // HASHTABLE_H
