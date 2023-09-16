#include <iostream>
#include <string>
#include "BinaryHeap.h"

std::string binaryHeapArrayToString(BinaryHeapArray<int>& heap) {
	std::string result;

	while (!heap.isEmpty()) {
		result += std::to_string(heap.extractMax()) + " ";
	}

	return result;
}

std::string binaryHeapListToString(BinaryHeapList<int>& heap) {
	std::string result;

	while (!heap.isEmpty()) {
		result += std::to_string(heap.getMin()) + " ";
		heap.removeMin();
	}

	return result;
}

int main() {
	/*BinaryHeapArray<int> heapArray;
	heapArray.insert(10);
	heapArray.insert(20);
	heapArray.insert(15);
	heapArray.insert(30);
	std::string str = binaryHeapArrayToString(heapArray);
	
	std::cout << str << std::endl;*/

	BinaryHeapList<int> heap;
	int a = 1;
	while (a)
	{
		std::cin >> a;
		heap.insert(a);
	}
	
	std::string str = binaryHeapListToString(heap);
	std::cout << str;

	return 0;
}

