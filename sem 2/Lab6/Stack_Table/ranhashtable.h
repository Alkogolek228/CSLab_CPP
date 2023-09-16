#ifndef RANHASHTABLE_H
#define RANHASHTABLE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hashtable.h"

using namespace std;

class RandomHashTable : public HashTable
{
public:
    RandomHashTable(int TABLE_SIZE) : HashTable()
    {
        srand(time(0));
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int key = rand() % 100 + 1;
            int value = rand() % 1000 + 1;
            put(key, value);
        }
    }

    void removeEvenKeys()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Node* node = table[i];
            Node* prev = nullptr;
            while (node) {
                if (node->key % 2 == 0)
                {
                    if (prev)
                    {
                        prev->next = node->next;
                    }
                    else
                    {
                        table[i] = node->next;
                    }
                    Node* temp = node;
                    node = node->next;
                    delete temp;
                }
                else
                {
                    prev = node;
                    node = node->next;
                }
            }
        }
    }
};

#endif // RANHASHTABLE_H
