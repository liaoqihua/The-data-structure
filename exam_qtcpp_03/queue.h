#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template<typename T>
class queue
{
public:
    virtual bool isempty() const = 0;
    virtual bool head(T &x) const = 0;
    virtual bool enter(T x) = 0;
    virtual bool delet(T &x) = 0;
    virtual void clear() = 0;
};

#endif // QUEUE_H
