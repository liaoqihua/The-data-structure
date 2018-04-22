#ifndef SEQLIST_H
#define SEQLIST_H
#include "linearlist.h"

template<class T>
class seqlist :
    public linearlist<T>
{
public:
    seqlist();
    seqlist(int msize);
    ~seqlist();
    bool isempty() const;
    int length() const;
    bool find(int i, T &x) const;
    int search(T x) const;
    bool insert(int i, T x);
    bool delet(int i);
    bool update(int i, T x);
    void output(ostream &out) const;
protected:
    int maxlength;
    T *elements;
};

template<class T>
seqlist<T>::seqlist()
{

}

template<class T>
seqlist<T>::seqlist(int msize)
{
    this->n = 0;
    this->maxlength = msize;
    this->elements = new T[msize];
}


template<class T>
seqlist<T>::~seqlist()
{
    delete[] this->elements;
}

template<class T>
bool seqlist<T>::isempty() const
{
    return this->n == 0;
}

template<class T>
int seqlist<T>::length() const
{
    return this->n;
}

template<class T>
bool seqlist<T>::find(int i, T &x) const
{
    if (i<0 || i>this->n - 1)
    {
        cout << "out of bounds" << endl;
        return false;
    }
    x = elements[i];
    return true;
}

template<class T>
int seqlist<T>::search(T x) const
{
    for (int i = 0; i < this->n; i++)
    {
        if (x == elements[i])
            return i;
    }
    return 0;
}

template<class T>
bool seqlist<T>::insert(int i, T x)
{
    if (i<0 || i>this->n)
    {
        cout << "out of bounds" << endl;
        return false;
    }
    if (this->n == maxlength)
    {
        cout << "overflow" << endl;
        return false;
    }
    for (int j = this->n - 1; j >= i; j--)
    {
        elements[j + 1] = elements[j];
    }
    elements[i] = x;
    this->n++;
    return true;
}

template<class T>
bool seqlist<T>::delet(int i)
{
    if (i<0 || i>this->n - 1)
    {
        cout << "out of bounds" << endl;
        return false;
    }
    for (int j = i; j < this->n; j++)
    {
        elements[j] = elements[j + 1];
    }
    this->n--;
    return true;
}

template<class T>
bool seqlist<T>::update(int i, T x)
{
    if (i<0 || i>this->n - 1)
    {
        cout << "out of bounds" << endl;
        return false;
    }
    elements[i] = x;
    return true;
}

template<class T>
void seqlist<T>::output(ostream &out) const
{
    for (int j = 0; j < this->n; j++)
    {
        out << elements[j] << " ";
    }
    out << endl;
}
#endif // SEQLIST_H
