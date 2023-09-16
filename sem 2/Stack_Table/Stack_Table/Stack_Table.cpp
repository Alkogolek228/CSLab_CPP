#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
    HashTable hashTable;

    // добавление элементов
    hashTable.put(1, 11);
    hashTable.put(2, 22);
    hashTable.put(3, 33);
    hashTable.put(4, 44);
    hashTable.put(5, 55);
    hashTable.put(6, 66);

    // вывод размера таблицы
    std::cout << "Size: " << hashTable.size() << std::endl;

    // вывод таблицы
    std::cout << "Table:" << endl;
    hashTable.print();

    // изменение значения элемента
    hashTable.put(4, 444);

    cout << "Table after updating element with key 4:" << endl;
    hashTable.print();

    // удаление элемента
    hashTable.remove(3);

    // вывод таблицы
    cout << "Table after removing element with key 3:" << endl;
    hashTable.print();

    // поиск элемента
    int keyToFind = 2;
    int value = hashTable.get(keyToFind);
    if (value != -1) {
        cout << "Found element with key " << keyToFind << " and value " << value << endl;
    }
    else {
        cout << "Element with key " << keyToFind << " not found" << endl;
    }

    // попытка найти несуществующий элемент
    int nonExistentKey = 10;
    value = hashTable.get(nonExistentKey);
    if (value != -1) {
        cout << "Found element with key " << nonExistentKey << " and value " << value << endl;
    }
    else {
        cout << "Element with key " << nonExistentKey << " not found" << endl;
    }

    return 0;
}

