#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename T>
class stack
{
    virtual bool isempty() const = 0;
    virtual bool getTop(T &x) const = 0;
    virtual bool push(T x) = 0;
    virtual bool pop(T &x) = 0;
    virtual void clear() = 0;
};


#endif // STACK_H
