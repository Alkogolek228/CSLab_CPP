#ifndef DEQUE_H
#define DEQUE_H
#include <deque>
#include <memory>
#include <QApplication>
#include <QDebug>
#include "iterator.h"
#include "node.h"
#include "ptr.h"


template<class T>
class Deque :public Iterator<T>
{
public:
    Deque(){}
    ~Deque(){}

    Iterator<T> begin()  {
        Node<T>* firstNode = _front;
        return Iterator<T>(firstNode, 0);
    }

    Iterator<T> end(){
        Node<T>* lastNode = _back;
        return Iterator<T>(lastNode, lastNode->count);
    }

    T &back() {return _back->data[_back->count - 1];} //в последнем массиве пооследняя ячейка
    T &front(){return _front->data[0];}

    void push_back(const T &addItem);
    void push_front(const T &addItem);
    void pop_back();
    void pop_front();
    void resize(size_t new_size);

    bool empty() {return !_size;}
    int size() {return _size;}

    void clear() {
        _capacity=0;
        _size=0;
        _front=nullptr;
        _back=nullptr;
    }

    T& operator[](size_t index)
    {
        // Если индекс находится вне диапазона элементов, выбрасываем исключение
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* node = _front;
        size_t count = 0;
        while (node != nullptr && count + node->count <= index) {
            count += node->count;
            node = node->prev;
        }

        // Возвращаем элемент из найденного узла по соответствующему индексу в его массиве
        return node->data[index - count];
    }
private:
    Node<T> *_front;  //два указателя на первый и последний элементы
    Node<T> *_back;
    size_t _capacity = 0;  //обозначает текущее количество узлов в деке
    size_t _size = 0;   //количество элементов в деке
};


template<class T>
void Deque<T>::push_back(const T &addItem){
   if(_capacity == 0){   //Если дек пустой
       _front = new Node<T>;  //то создается новый узел
       _back = _front;
       _back->data[0] = addItem;  //элемент помещается в его массив
       _back->count++;
       _capacity++;
   }
   else{  //В противном случае, если текущий узел еще не заполнен
       if(_back->count < 4){
           _back->data[_back->count] = addItem;  //то элемент добавляется в его массив
           _back->count++;
       }
       else{  //Если текущий узел уже заполнен
            _back->prev = new Node<T>;  //то создается новый узел
            _back->prev->next = _back;
            _back = _back->prev;
            _back->data[_back->count] = addItem;  //элемент помещается в его массив
            _back->count++;
            _capacity++;
       }
   }

   _size++;
}

template<class T>
void Deque<T>::push_front(const T & addItem){
    if(_capacity == 0){
        _back=_front=new Node<T>;
        _front->data[0]=addItem;
        _front->count++;
        _front->prev = _back;
        _capacity++;
    }
    else{
        if(_front->count < 4){
            for(auto i = 0; i < _front->count; i++){
                auto tmp = _front->data[i + 1];
                _front->data[i + 1] = _front->data[i];
            }
            _front->data[0] = addItem;
            _front->count++;

        }
        else{
             _front->next = new Node<T>;
             _front->next->prev = _front;
             _front = _front->next;
             _front->data[0] = addItem;
             _front->count++;
             _capacity++;
        }
    }

    _size++;
}

template<class T>
void Deque<T>::pop_back() {
    if (_back->count > 1) {
        _back->data[--_back->count] = T();
    }
    else {
        Node<T> *tmp = _back;
        _back = _back->prev;
        if (_back) {
            delete tmp;
            _back->next = nullptr;
        }
        else {
            delete[] tmp->data;
            delete tmp;
            _back = _front = nullptr;
            _capacity = _size = 0;
        }
    }
    _size--;
}

template<class T>
void Deque<T>::pop_front(){
    if(_front->count <= 1){
        Node<T> * tmp = _front;
        _front = _front->prev;
        delete tmp;
        _capacity--;
    }
    else{
        _front->data[0] = rand();
        for(auto i = 1; i < _front->count; i++){
            _front->data[i - 1] = _front->data[i];
        }
    }
}

template<class T>
void Deque<T>::resize(size_t new_size) {
    if (new_size <= _size) {
        return;
    }

    size_t num_new_nodes = (new_size - _size + 3) / 4;

    for (size_t i = 0; i < num_new_nodes; i++) {
        if (_capacity == 0) {
            _front = _back = new Node<T>;
        }
        else {
            _back->next = new Node<T>;
            _back->next->prev = _back;
            _back = _back->next;
        }
        _capacity++;
    }

    _size = new_size;
}

#endif // DEQUE_H
