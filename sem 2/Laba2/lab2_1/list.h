#ifndef LIST_H
#define LIST_H

#include"student.h"

struct Node
{
public:
    Student data;
    Node *prev, *next;
    Node(Student data)
    {
        this->data = data;
        this->prev = this->next = nullptr;
    }
};

class List
{
public:
    Node *head, *tail;
    List();
   ~List();
    void push_front(Student);
    void push_back(Student);
    void pop_front();
    void pop_back();
    Node* getAt(int);
    Node* operator [](int);
    void insert(int, Student);
    void erase(int);
};

#endif // LIST_H
