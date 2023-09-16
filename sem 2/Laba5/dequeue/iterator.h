#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"

template<class T>
class Iterator {
private:
    Node<T>* _node;  // указатель на узел
    int _index;   //индекс текущего элемента
public:
    Iterator(){};
    Iterator(Node<T>* node) : _node(node){};
        Iterator(Node<T>* node, int index) : _node(node), _index(index) {};
        ~Iterator(){};
        //DequeIterator& begin();
        //DequeIterator& end();
        Iterator<T> begin()  ;
        Iterator<T> end() ;
        T& operator*() const {
            return _node->data[_index];
        }

        T* operator->() const {
            return &_node->data[_index];
        }
        Iterator<T> begin() const {  //пока нода может указывать на предыдущую перемещаем и оставляем первой
                Node<T>* firstNode = _node;
                while (firstNode->prev) {
                    firstNode = firstNode->prev;
                }
                return Iterator<T>(firstNode, 0);
            }

            Iterator<T> end() const {
                Node<T>* lastNode = _node;
                while (lastNode->next) {
                    lastNode = lastNode->next;
                }
                return Iterator<T>(lastNode, lastNode->count);
            }

        Iterator& operator++() {
            if (_index + 1 < _node->count) {
                _index++;
            } else {
                _node = _node->next;
                _index = 0;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            if (_index > 0) {
                _index--;
            } else {
                _node = _node->prev;
                _index = _node->count - 1;
            }
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }


bool operator==(const Iterator& other) const {
return (_node == other._node) && (_index == other._index);
}

bool operator!=(const Iterator& other) const {
return !(*this == other);
}


};
#endif // ITERATOR_H
