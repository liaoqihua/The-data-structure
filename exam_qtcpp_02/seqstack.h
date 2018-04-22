#ifndef SEQSTACK_H
#define SEQSTACK_H
#include "stack.h"

template<typename T>
class SeqStack: public stack<T>
{
public:
    SeqStack();
    SeqStack(int msize);
    ~SeqStack();
    bool isempty() const;
    bool getTop(T &x) const;
    T getTop() const;
    bool push(T x);
    bool pop(T &x);
    T pop();
    void clear();
    bool isfull() const;
private:
    int top;
    int maxtop;
    T *data;
};

template<typename T>
SeqStack<T>::SeqStack()
{
    this->top = 0;
    this->maxtop = 10;
    this->data = new T[10];
}

template<typename T>
SeqStack<T>::SeqStack(int msize)
{
    this->top = 0;
    this->maxtop = msize;
    this->data = new T[msize];
}

template<typename T>
SeqStack<T>::~SeqStack()
{
    delete[] this->data;
}

template<typename T>
bool SeqStack<T>::isempty() const
{
    return this->top == 0;
}

template<typename T>
bool SeqStack<T>::isfull() const
{
    return this->top == this->maxtop;
}

template<typename T>
bool SeqStack<T>::getTop(T &x) const
{
    if(this->isempty())
        return false;
    else
    {
        x = this->data[this->top-1];
        return true;
    }
}

template<typename T>
T SeqStack<T>::getTop() const
{
    if(this->isempty())
        return NULL;
    else
    {
        return this->data[this->top-1];
    }
}

template<typename T>
bool SeqStack<T>::push(T x)
{
    if(this->isfull())
    {
        cout << "overflow" << endl;
        return false;
    }
    else
    {
        this->data[this->top] = x;
        this->top++;
        return true;
    }
}

template<typename T>
bool SeqStack<T>::pop(T &x)
{
    if(this->isempty())
    {
        cout << "stack is empty" << endl;
        return false;
    }
    else
    {
        x = this->data[this->top-1];
        this->top--;
        return true;
    }
}

template<typename T>
T SeqStack<T>::pop()
{
    if(this->isempty())
    {
        cout << "stack is empty" << endl;
        return NULL;
    }
    else
    {
        T x = this->data[this->top-1];
        this->top--;
        return x;
    }
}

template<typename T>
void SeqStack<T>::clear()
{
    this->top = 0;
}

#endif // SEQSTACK_H
