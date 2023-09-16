#include <iostream>
#include "Hashtable.h"

int main() {
    const int n16 = 16;
    int data16[n16];
    const int n64 = 64;
    int data64[n64];
    const int n128 = 128;
    int data128[n128];
    const int n2048 = 2048;
    int data2048[n2048];

    for (int i = 0; i < n16; i++) {
        data16[i] = rand();
    }

    HashTable<int, int> table1(n16);
    for (int i = 0; i < n16; i++)
    {
        table1.add(data16[i], i);
    }

    for (int i = 0; i < n64; i++) {
        data64[i] = rand();
    }

    HashTable<int, int> table2(n64);
    for (int i = 0; i < n64; i++)
    {
        table2.add(data64[i], i);
    }

    for (int i = 0; i < n128; i++) {
        data128[i] = rand();
    }

    HashTable<int, int> table3(n128);
    for (int i = 0; i < n128; i++)
    {
        table3.add(data128[i], i);
    }

    for (int i = 0; i < n2048; i++) {
        data2048[i] = rand();
    }

    HashTable<int, int> table4(n2048);
    for (int i = 0; i < n2048; i++)
    {
        table4.add(data2048[i], i);
    }


	table1.print();
	table2.print();
	table3.print();
	table4.print();

	std::cout << table1.searchTime(data16[n16 -1]) << "\n";
    std::cout << table2.searchTime(data64[n64 -1]) << "\n";
    std::cout << table3.searchTime(data128[n128 -1]) << "\n";
    std::cout << table4.searchTime(data2048[n2048 - 1]) << "\n";
	
    

	return 0;
}

