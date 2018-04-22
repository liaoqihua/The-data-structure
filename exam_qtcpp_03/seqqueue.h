#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include "queue.h"

template<typename T>
class SeqQueue: public queue<T>
{
public:
    SeqQueue();
    SeqQueue(int msize);
    ~SeqQueue();
    bool isempty() const;
    bool isfull() const;
    bool head(T &x) const;
    T head() const;
    bool enter(T x);
    bool delet(T &x);
    T delet();
    void clear();
private:
    T *data;
    int maxsize;
    int front, rear;
};

template<typename T>
SeqQueue<T>::SeqQueue()
{
    this->data = new T[10];
    this->maxsize = 10;
    this->front = 0;
    this->rear = 0;
}

template<typename T>
SeqQueue<T>::SeqQueue(int msize)
{
    this->data = new T[msize];
    this->maxsize = msize;
    this->front = 0;
    this->rear = 0;
}

template<typename T>
SeqQueue<T>::~SeqQueue()
{
    delete[] this->data;
}

template<typename T>
bool SeqQueue<T>::isempty() const
{
    return this->front == this->rear;
}

template<typename T>
bool SeqQueue<T>::isfull() const
{
    return (this->rear+1)%this->maxsize == this->front;
}

template<typename T>
bool SeqQueue<T>::enter(T x)
{
    if(this->isfull())
    {
        cout << "queue is full" << endl;
        return false;
    }
    else
    {
        this->data[this->rear] = x;
        this->rear = (this->rear + 1) % this->maxsize;
        return true;
    }
}

template<typename T>
bool SeqQueue<T>::head(T &x) const
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return false;
    }
    else
    {
        x = this->data[this->front];
        return true;
    }
}

template<typename T>
T SeqQueue<T>::head() const
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return false;
    }
    else
    {
        return this->data[this->front];
    }
}

template<typename T>
bool SeqQueue<T>::delet(T &x)
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return false;
    }
    else
    {
        x = this->data[this->front];
        this->front = (this->front + 1) % this->maxsize;
        return true;
    }
}

template<typename T>
T SeqQueue<T>::delet()
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return false;
    }
    else
    {
        T x = this->data[this->front];
        this->front = (this->front + 1) % this->maxsize;
        return x;
    }
}

template<typename T>
void SeqQueue<T>::clear()
{
    this->rear = this->front;
}


#endif // SEQQUEUE_H
