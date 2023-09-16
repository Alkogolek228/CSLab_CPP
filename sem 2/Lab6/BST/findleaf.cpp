#include "findleaf.h"

FindLeaf::FindLeaf(): BST(){}

FindLeaf::FindLeaf(std::vector<std::pair<int, std::string>> vec) : BST(vec){}

FindLeaf::~FindLeaf(){}

int FindLeaf::countLeaves()
{
    return _countLeaves(_root);
}

int FindLeaf::_countLeaves(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        return 1;
    }

    int leftLeaves = _countLeaves(node->left);
    int rightLeaves = _countLeaves(node->right);

    return leftLeaves + rightLeaves;
}
