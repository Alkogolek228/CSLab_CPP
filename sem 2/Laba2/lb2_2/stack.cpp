#include "Stack.h"

template<typename T>
void Stack<T>::push(T item)
{
    if (Top == MAX_SIZE - 1)
    {
        return;
    }
    Top++;
    stack[Top] = item;
}

template<typename T>
T Stack<T>::pop()
{
    if (Top == -1)
    {
        return T();
    }
    T item = stack[Top];
    Top--;
    return item;
}

template<typename T>
T Stack<T>::top()
{
    if (Top == -1)
    {
        return T();
    }
    return stack[Top];
}

template<typename T>
bool Stack<T>::empty()
{
    return Top == -1;
}

template<typename T>
int Stack<T>::size()
{
    return Top + 1;
}
