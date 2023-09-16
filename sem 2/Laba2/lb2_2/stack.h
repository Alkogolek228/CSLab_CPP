#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
private:
    static const int MAX_SIZE = 100;
    T stack[MAX_SIZE];
    int Top = -1;
public:
    void push(T item);
    T pop();
    T top();
    bool empty();
    int size();
};

#endif // STACK_H
