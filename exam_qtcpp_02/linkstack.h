#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "stack.h"

template<typename T> class LinkStack;

template<typename T>
class stacknode
{
    T data;
    stacknode *next;
    friend class LinkStack<T>;
};

template<typename T>
class LinkStack: public stack<T>
{
public:
    LinkStack();
    ~LinkStack();
    bool isempty() const;
    bool getTop(T &x) const;
    T getTop() const;
    bool push(T x);
    bool pop(T &x);
    T pop();
    void clear();
private:
    stacknode<T> *top;
};

template<typename T>
LinkStack<T>::LinkStack()
{
    this->top = NULL;
}

template<typename T>
LinkStack<T>::~LinkStack()
{
    while (this->top)
    {
        stacknode<T> *p = this->top;
        this->top = this->top->next;
        delete p;
    }
}

template<typename T>
bool LinkStack<T>::isempty() const
{
    return this->top == NULL;
}

template<typename T>
bool LinkStack<T>::getTop(T &x) const
{
    if(this->isempty())
    {
        cout << "stack is empty" << endl;
        return false;
    }
    else
    {
        x = this->top->data;
        return true;
    }
}

template<typename T>
T LinkStack<T>::getTop() const
{
    if(this->isempty())
    {
        cout << "stack is empty" << endl;
        return NULL;
    }
    else
    {
        return this->top->data;
    }
}

template<typename T>
bool LinkStack<T>::push(T x)
{
    stacknode<T> *sn = new stacknode<T>;
    sn->data = x;
    sn->next = this->top;
    this->top = sn;
    return true;
}

template<typename T>
bool LinkStack<T>::pop(T &x)
{
    if(this->isempty())
    {
        cout << "stack is empty" << endl;
        return false;
    }
    else
    {
        x = this->top->data;
        stacknode<T> *sn = this->top;
        this->top = this->top->next;
        delete sn;
        return true;
    }
}

template<typename T>
T LinkStack<T>::pop()
{
    if(this->isempty())
    {
        cout << "stack is empty" << endl;
        return NULL;
    }
    else
    {
        T x = this->top->data;
        stacknode<T> *sn = this->top;
        this->top = this->top->next;
        delete sn;
        return x;
    }
}

template<typename T>
void LinkStack<T>::clear()
{
    stacknode<T> *sn;
    while(this->top)
    {
        sn = this->top;
        this->top = this->top->next;
        delete sn;
    }
}

#endif // LINKSTACK_H
