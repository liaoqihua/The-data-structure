#ifndef LINEARLIST_H
#define LINEARLIST_H
#include <iostream>
using namespace std;

template<class T>
class linearlist
{
public:
    virtual bool isempty() const=0;
    virtual int length() const=0;
    virtual bool find(int i, T &x) const=0;
    virtual int search(T x) const=0;
    virtual bool insert(int i, T x)=0;
    virtual bool delet(int i)=0;
    virtual bool update(int i, T x)=0;
    virtual void output(ostream &out) const=0;
protected:
    int n;
};

#endif // LINEARLIST_H
