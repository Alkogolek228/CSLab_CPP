#include "list.h"
List::List()
{
    this->head = this->tail = nullptr;
}

List::~List()
{
    while (head != NULL)
    pop_front();
}

void List::push_front(Student data)
{
    Node* ptr = new Node(data);
    ptr->next = head;
    if (head != nullptr)
    {
        head->prev = ptr;
    }
    if (tail == nullptr)
    {
        tail = ptr;
        head = ptr;
    }
}

void List::push_back(Student data)
{
    Node* ptr = new Node(data);
    ptr->prev = tail;
    if (tail != nullptr)
    {
        tail->next = ptr;
    }
    if (head == nullptr)
    {
        head = ptr;
    }

    tail = ptr;
}

void List::pop_front()
{
    if (head == nullptr) return;

    Node* ptr = head->next;

    if (ptr != nullptr)
    {
        ptr->prev = nullptr;
    }
    else
    {
        tail = nullptr;
        delete head;
        head = ptr;
    }
}

void List::pop_back()
{
    if (tail == nullptr) return;

    Node* ptr = tail->prev;

    if (ptr != nullptr)
    {
        ptr->next = nullptr;
    }
    else
    {
        head = nullptr;
        delete tail;
        tail = ptr;
    }
}

Node* List::getAt(int index)
{
    Node* ptr = head;
    int n = 0;
    while (n != index)
    {
        if (ptr == nullptr)
        return ptr;
        ptr = ptr->next;
        n++;
    }
    return ptr;
}

Node* List::operator [](int index)
{
    return getAt(index);
}

void List::insert(int index,Student data)
{
    Node* right = getAt(index);

    if (right == nullptr)
        return push_back(data);

    Node* left = right->prev;

    if (left == nullptr)
        return push_front(data);

    Node* ptr = new Node(data);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;
}

void List::erase(int index)
{
    Node* ptr = getAt(index);
    if (ptr == nullptr)
        return;
    if (ptr->prev == nullptr)
    {
        pop_front();
        return;
    }
    if (ptr->next == nullptr)
    {
        pop_back();
        return;
    }

    Node* left = ptr->prev;
    Node* right = ptr->next;
    left->next = right;
    right->prev = left;
    delete ptr;
}
