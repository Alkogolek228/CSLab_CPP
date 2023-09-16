#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include <ptr.h>

template<typename T>
class Queue
{
    struct Data{

        T inf;
        Data *next= nullptr;
        Data(const T& inf = T(), Data* next = nullptr) : inf(inf), next(next) {}
    };

    Data *head =nullptr;
    Data* tail =nullptr;

public:
    Queue(){};
    void push(const T&);
    bool pop();
    virtual ~Queue();
    bool empty() const { return !head; }
    int size() const {
            int count = 0;
            Ptr<Data> cur = head;
            while (cur) {
                ++count;
                cur = cur->next;
            }
            return count;
        }
    T& front() const {
        if (!head) {
            throw std::out_of_range("Queue is empty");
        }
        return head->inf;
    }

    T& back() const {
        if (!tail) {
            throw std::out_of_range("Queue is empty");
        }
        return tail->inf;
    }
};

template<typename T>
void Queue<T>::push(const T& val)
{
    //SmartPtr<QElem> elem (new QElem(val));
    Data *elem =new Data();
    elem->inf=val;

    if(head==nullptr)
    {
        head=tail=elem;
    }
    else tail=tail->next=elem;

}

template<typename T>
bool Queue<T>::pop()
{
    if(!head) return false;
    Data * elem = head;
    head=head->next;
    delete elem;
    return true;

}

template<typename T>
Queue<T>::~Queue(){
    while(head)
    {
        Data * elem=head;
        head=head->next;
        delete elem;
    }
}

#endif // QUEUE_H
