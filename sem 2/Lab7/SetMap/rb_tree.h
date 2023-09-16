#ifndef RB_TREE_H
#define RB_TREE_H

#include <functional>
#include <string>
#include <queue>
#include "rb_node.h"
#include "rb_iterator.h"

template <typename T>
class rb_tree
{
public:
    //members
    rb_node<T>* root;
    unsigned long size;
    //Constructors
    rb_tree(void) : root(NULL), size(0) { }

    template<typename Iterator_>
    rb_tree(Iterator_ begin, Iterator_ end) { insert(begin, end); }

    //Utility functions
    rb_iterator<rb_node<T>> max(void) { return (empty()) ? end() : rb_iterator<rb_node<T>>(root->max()); }
    rb_iterator<rb_node<T>> min(void) { return (empty()) ? end() : rb_iterator<rb_node<T>>(root->min()); }
    rb_iterator<rb_node<T>> begin(void) { return min(); }
    rb_iterator<rb_node<T>> end(void) { return rb_iterator<rb_node<T>>(); }
    bool empty(void) const { return (root == NULL); }

    /*Insertion*/
    rb_iterator<rb_node<T>> insert(T value)
    {
        return rb_iterator<rb_node<T>>(insert(new rb_node<T>(value)));
    }

    rb_iterator<rb_node<T>> insert(rb_iterator<rb_node<T>>& current, T& value)
    {
        return insert(value);
    }

    template< typename Iterator_ >
    void insert(Iterator_ begin, Iterator_ end)
    {
        for (Iterator_ it = begin; it != end; ++it)
        {
            T v = *it;
            insert(v);
        }
    }

    /*	RED BLACK INSERTION	*/
    rb_node<T>* insert(rb_node<T>* node)
    {
        binary_insert(node);
        rb_node<T>* temp = node;
        rb_adjust(temp);
        return node;
    }

    //Display tree
    std::string print()
    {
        if (empty())
            return "No tree initialized";
        else
            return print(root);
    }

    void inorder_print(rb_node<T>* ptr)
    {
        if (ptr == NULL)
            return;
        ptr->print();
        inorder_print(ptr->left);
        inorder_print(ptr->right);
    }

    int height()
    {
        return height(root);
    }


protected:
    std::string print(rb_node<T>* node)
    {
        std::string result;
        result += "\n";
        if (node == NULL)
            return result;
        int h = height();
        std::queue<rb_node<T>*> currentLevel, nextLevel;
        currentLevel.push(node);
        while (!currentLevel.empty())
        {
            rb_node<T>* currNode = currentLevel.front();
            currentLevel.pop();
            if (currNode != NULL) {
                for (int i = (1 << h - 1) * 2; i > 0; i--)
                    result += " ";
                result += std::to_string(currNode->value) + ":" + std::to_string(currNode->color);
                nextLevel.push(currNode->left);
                nextLevel.push(currNode->right);
            }
            if (currentLevel.empty())
            {
                result += "\n";
                h--;
                std::swap(currentLevel, nextLevel);
            }
        }
        return result;
    }


    int height(rb_node<T>* node)
    {
        if (node == NULL)
            return 0;
        int heightLeft = height(node->left);
        int heightRight = height(node->right);

        if (heightLeft > heightRight)
            return heightLeft + 1;
        else
            return heightRight + 1;
    }

    //Binary Tree Insertion
    rb_node<T>* binary_insert(rb_node<T>* node)
    {
        ++size;
        //Root insertion case
        if (empty())
            root = node;
        else
        {
            rb_node<T>* current = root;
            do
            {
                if (current->value < node->value)
                {
                    if (current->right == NULL)
                    {
                        node->parent = current; current->right = node; break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
                else if (current->value >= node->value)
                {
                    if (current->left == NULL)
                    {
                        node->parent = current; current->left = node; break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
            } while (true);
        }
        return node;
    }

    //Special functions
    void rb_adjust(rb_node<T>* node)
    {
        //Case 1: Root node
        if (node == NULL)
            return;
        if (node->parent == NULL)
        {
            node->color = BLACK; return;
        }

        rb_node<T>* p = node->parent;
        //Case 2: Parent is BLACK
        if (p != NULL && p->color == BLACK)
            return;

        //Case 3: Parent and Uncle are RED
        rb_node<T>* u = p->sibling();
        if (p->color == RED && (u != NULL && u->color == RED))
        {
            p->color = BLACK;
            u->color = BLACK;
            p->parent->color = RED;
            rb_adjust(p->parent);
            return;
        }

        //Case 4: Parent is Red and Uncle is Black(Or NULL)
        //If parent is left son
        if (p->is_a_left_son())
        {
            if (node->is_a_right_son())
            {
                node = p; left_rotate(p);
            }

            p->color = BLACK;

            if (p->parent != NULL)
            {
                p->parent->color = RED;
                right_rotate(p->parent);
            }
            return;
        }
        //If parent is right son
        else if (p->is_a_right_son())
        {
            if (node->is_a_left_son())
            {
                node = p; right_rotate(p);
            }
            p->color = BLACK;
            if (p->parent != NULL)
            {
                p->parent->color = RED;
                left_rotate(p->parent);
            }
            return;
        }
    }

    // left rotate
    void left_rotate(rb_node<T>* node)
    {
        if (node->right != NULL)
        {
            rb_node<T>* right_son = node->right;
            if ((node->right = node->right->left) != NULL)
                node->right->parent = node;
            if (node->parent == NULL)
                root = right_son;
            else if (node->is_a_left_son())
                node->parent->left = right_son;
            else
                node->parent->right = right_son;

            // update right_son's parent:
            right_son->parent = node->parent;
            // the left son of the old right son is this node:
            node->parent = right_son;
            right_son->left = node;
        }
    }

    //	right rotate
    void right_rotate(rb_node<T>* node)
    {
        // check if node has a left son
        if (node->left != NULL) {
            rb_node<T>* left_son = node->left;
            if ((node->left = node->left->right) != NULL)
                node->left->parent = node;
            if (node->parent == NULL)
                root = left_son;
            else if (node->is_a_left_son())
                node->parent->left = left_son;
            else
                node->parent->right = left_son;
            left_son->parent = node->parent;
            node->parent = left_son;
            left_son->right = node;
        }
    }
};

#endif // RB_TREE_H
