#pragma once
#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class Shared_ptr {
private:
    struct ControlBlock {
        T* ptr;
        size_t* refCount;
        size_t* weakCount;
    };

    ControlBlock* controlBlock;

public:
    Shared_ptr() : controlBlock(nullptr) {}

    explicit Shared_ptr(T* ptr) {
        if (ptr) {
            controlBlock = new ControlBlock;
            controlBlock->ptr = ptr;
            controlBlock->refCount = new size_t(1);
            controlBlock->weakCount = new size_t(0);
        }
        else {
            controlBlock = nullptr;
        }
    }

    Shared_ptr(const Shared_ptr& other) : controlBlock(other.controlBlock) {
        if (controlBlock) {
            ++(*controlBlock->refCount);
        }
    }

    Shared_ptr& operator=(const Shared_ptr& other) {
        if (this != &other) {
            release();

            controlBlock = other.controlBlock;
            if (controlBlock) {
                ++(*controlBlock->refCount);
            }
        }
        return *this;
    }

    ~Shared_ptr() {
        release();
    }

    T& operator*() const {
        return *(controlBlock->ptr);
    }

    T* operator->() const {
        return controlBlock->ptr;
    }

    operator bool() const {
        return controlBlock && controlBlock->ptr;
    }

private:
    void release() {
        if (controlBlock) {
            if (--(*controlBlock->refCount) == 0) {
                delete controlBlock->ptr;
                delete controlBlock->refCount;
                if (*controlBlock->weakCount == 0) {
                    delete controlBlock->weakCount;
                    delete controlBlock;
                }
                else {
                    --(*controlBlock->weakCount);
                }
            }
        }
    }
};


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

template <typename T>
class BinaryHeapList {
private:
    struct Node {
        T value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> leftChild;
        std::shared_ptr<Node> rightChild;

        Node(const T& val) : value(val) {}
    };

    std::shared_ptr<Node> root;

    void heapifyUp(std::shared_ptr<Node> node) {
        if (node->parent.expired()) {
            root = node;
            return;
        }

        auto parent = node->parent.lock();
        if (node->value < parent->value) {
            std::swap(node->value, parent->value);
            heapifyUp(parent);
        }
    }

    void heapifyDown(std::shared_ptr<Node> node) {
        auto smallest = node;

        if (node->leftChild && node->leftChild->value < smallest->value) {
            smallest = node->leftChild;
        }

        if (node->rightChild && node->rightChild->value < smallest->value) {
            smallest = node->rightChild;
        }

        if (smallest != node) {
            std::swap(node->value, smallest->value);
            heapifyDown(smallest);
        }
    }

public:
    void insert(const T& value) {
        auto newNode = std::make_shared<Node>(value);
        if (!root) {
            root = newNode;
        }
        else {
            std::shared_ptr<Node> parentNode;
            std::shared_ptr<Node> currentNode = root;

            while (currentNode) {
                parentNode = currentNode;
                currentNode = (value < currentNode->value) ? currentNode->leftChild : currentNode->rightChild;
            }

            newNode->parent = parentNode;
            if (value < parentNode->value) {
                parentNode->leftChild = newNode;
            }
            else {
                parentNode->rightChild = newNode;
            }
        }

        heapifyUp(newNode);
    }

    void removeMin() {
        if (!root) {
            return;
        }

        if (!root->leftChild && !root->rightChild) {
            root = nullptr;
            return;
        }

        std::shared_ptr<Node> lastNode = root;
        while (lastNode->leftChild || lastNode->rightChild) {
            if (lastNode->leftChild) {
                lastNode = lastNode->leftChild;
            }
            else {
                lastNode = lastNode->rightChild;
            }
        }

        if (lastNode->parent.lock()->leftChild == lastNode) {
            lastNode->parent.lock()->leftChild = nullptr;
        }
        else {
            lastNode->parent.lock()->rightChild = nullptr;
        }

        root->value = lastNode->value;
        heapifyDown(root);
    }

    const T& getMin() const {
        if (!root) {
            throw std::out_of_range("Heap is empty");
        }

        return root->value;
    }

    bool isEmpty() const {
        return !root;
    }
};

