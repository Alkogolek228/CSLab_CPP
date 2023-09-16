#ifndef FINDLEAF_H
#define FINDLEAF_H

#include "bst.h"

class FindLeaf : public BST
{
public:
    FindLeaf();
    FindLeaf(std::vector<std::pair<int, std::string>> vec);
    ~FindLeaf();
    int countLeaves();

private:
    int _countLeaves(Node* node);
};
#endif // FINDLEAF_H
