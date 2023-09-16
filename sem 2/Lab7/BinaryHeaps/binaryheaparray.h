#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H
#include <iostream>
#include <memory>
#include <vector>
#include "Shared_ptr.h"

template<typename T>
class BinaryHeapArray {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index])
                break;

            std::swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest])
                largest = leftChild;

            if (rightChild < size && heap[rightChild] > heap[largest])
                largest = rightChild;

            if (largest == index)
                break;

            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T extractMax() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty!");

        T maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElement;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

#endif // BINARYHEAPARRAY_H
