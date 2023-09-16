#ifndef NODE_H
#define NODE_H

template<class T>
class Node{
public:
    Node(){}
    ~Node(){
        delete prev;
        delete next;
        delete []data;
    }
    int count = 0;
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    T *data = new T[4];
};
#endif // NODE_H
