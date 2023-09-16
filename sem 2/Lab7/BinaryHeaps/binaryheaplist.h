#ifndef BINARYHEAPLIST_H
#define BINARYHEAPLIST_H
#include <memory>
#include "Shared_ptr.h"
#include <iostream>

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
#endif // BINARYHEAPLIST_H
