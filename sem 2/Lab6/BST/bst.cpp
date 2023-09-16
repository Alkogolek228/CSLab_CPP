#include "BST.h"

BST::BST() : _root(nullptr) {}

BST::BST(std::vector<std::pair<int, std::string>> vec)
{
    _root = _constrTree(vec, 0, vec.size());
}

BST::~BST() {}

void BST::toBalance()
{
    std::vector<std::pair<int, std::string>> vec;
    _inorder(_root, vec);

    _root = _toBalance(vec, 0, vec.size());
}

void BST::add(int key, std::string data)
{
    _root = _add(_root, key, data);
}

std::string BST::find(int key)
{
    Node* node = _find(_root, key);

    if (node == nullptr) {return "";}
    else {return node->data;}
}

std::vector<std::pair<int, std::string>> BST::printStraight()
{
    std::vector<std::pair<int, std::string>> vec;
    _printStraight(_root, vec);
    return vec;
}

std::vector<std::pair<int, std::string>> BST::printBackward()
{
    std::vector<std::pair<int, std::string>> vec;
    _printBackward(_root, vec);
    return vec;
}

std::vector<std::pair<int, std::string>> BST::printAscending()
{
    std::vector<std::pair<int, std::string>> vec;
    _inorder(_root, vec);
    return vec;
}

void BST::del(int key)
{
    _root = _del(_root, key);
}

Node* BST::_constrTree(std::vector<std::pair<int, std::string>>& vec, int start, int end)
{
    if (start >= end)
    {
        return nullptr;
    }

    size_t mid = (start + end) / 2;

    Node* root = new Node();
    root->key = vec[mid].first;
    root->data = vec[mid].second;
    root->left = _constrTree(vec, start, mid);
    root->right = _constrTree(vec, mid + 1, end);

    return root;
}

Node* BST::_toBalance(std::vector<std::pair<int, std::string>>& vec, int start, int end)
{
    if (start >= end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;

    Node* root = new Node();
    root->key = vec[mid].first;
    root->data = vec[mid].second;
    root->left = _toBalance(vec, start, mid);
    root->right = _toBalance(vec, mid + 1, end);

    return root;
}

Node* BST::_add(Node* node, int key, std::string value)
{
    if (node == nullptr)
    {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->data = value;

        return newNode;
    }

    if (key < node->key)
    {
        node->left = _add(node->left, key, value);
    }
    else
    {
        if (key > node->key)
        {
            node->right = _add(node->right, key, value);
        }
        else
        {
            node->data = value;
        }
    }

    return node;
}

Node* BST::_find(Node* node, int key)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->key)
    {
        return _find(node->left, key);
    }
    else
    {
        if (key > node->key)
        {
            return _find(node->right, key);
        }
        else
        {
            return node;
        }
    }
}

Node* BST::_del(Node* node, int key)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->key)
    {
        node->left = _del(node->left, key);
    }
    else
    {
        if (key > node->key)
        {
            node->right = _del(node->right, key);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                if (node->left == nullptr)
                {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else
                {
                    if (node->right == nullptr)
                    {
                        Node* temp = node->left;
                        delete node;
                        return temp;
                    }
                    else
                    {
                        Node* minRight = _findMin(node->right);

                        node->key = minRight->key;
                        node->data = minRight->data;
                        node->right = _del(node->right, minRight->key);
                    }
                }
            }
        }
    }

    return node;
}

void BST::_printStraight(Node* node, std::vector<std::pair<int, std::string>>& vec)
{
    if (node == nullptr)
    {
        return;
    }

    vec.push_back({ node->key, node->data });

    _printStraight(node->left, vec);
    _printStraight(node->right, vec);
}

void BST::_printBackward(Node* node, std::vector<std::pair<int, std::string>>& vec)
{
    if (node == nullptr)
    {
        return;
    }

    _printBackward(node->right, vec);

    vec.push_back({ node->key, node->data });

    _printBackward(node->left, vec);
}

int BST::_height(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return (1 + std::max(_height(node->left), _height(node->right)));
}

void BST::_inorder(Node* node, std::vector<std::pair<int, std::string>>& vec)
{
    if (node == nullptr)
    {
        return;
    }

    _inorder(node->left, vec);
    vec.push_back({ node->key, node->data });

    _inorder(node->right, vec);
}

Node* BST::_findMin(Node* node)
{
    while (node != nullptr && node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}
