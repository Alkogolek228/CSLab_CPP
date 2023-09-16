#pragma once

#include <iostream>
#include <string>
#include <vector>

class Node {
public:
    int key;
    std::string data;
    Node* left;
    Node* right;
};

class BST {
public:
    BST();
    BST(std::vector<std::pair<int, std::string>> vec);
    ~BST();
    void toBalance();
    void add(int key, std::string data);
    std::string find(int key);

    std::vector<std::pair<int, std::string>> printStraight();
    std::vector<std::pair<int, std::string>> printBackward();
    std::vector<std::pair<int, std::string>> printAscending();

    void del(int key);

protected:
    Node* _constrTree(std::vector<std::pair<int, std::string>>& vec, int start, int end);

    Node* _toBalance(std::vector<std::pair<int, std::string>>& vec, int start, int end);

    Node* _add(Node* node, int key, std::string value);

    Node* _find(Node* node, int key);

    Node* _del(Node* node, int key);

    void _printStraight(Node*, std::vector<std::pair<int, std::string>>& vec);
    void _printBackward(Node*, std::vector<std::pair<int, std::string>>& vec);

    int _height(Node* node);
    void _inorder(Node* node, std::vector<std::pair<int, std::string>>& vec);
    Node* _findMin(Node* node);

protected:
    Node* _root;
};