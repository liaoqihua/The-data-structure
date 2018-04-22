#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "queue.h"

template<typename T> class LinkQueue;

template<typename T>
class QueueNode
{
    T data;
    QueueNode *next;
    friend class LinkQueue<T>;
};

template<typename T>
class LinkQueue: public queue<T>
{
public:
    LinkQueue();
    ~LinkQueue();
    bool isempty() const;
    bool head(T &x) const;
    T head() const;
    bool enter(T x);
    bool delet(T &x);
    T delet();
    void clear();
private:
    QueueNode<T> *front, *rear;
};

template<typename T>
LinkQueue<T>::LinkQueue()
{
    QueueNode<T> *qn = new QueueNode<T>;
    qn->data = 0;
    qn->next = NULL;
    this->front = qn;
    this->rear = qn;
}

template<typename T>
LinkQueue<T>::~LinkQueue()
{
    QueueNode<T> *p;
    while(this->front)
    {
        p = this->front;
        this->front = this->front->next;
        delete p;
    }
}

template<typename T>
bool LinkQueue<T>::isempty() const
{
    return this->front == this->rear;
}

template<typename T>
bool LinkQueue<T>::enter(T x)
{
    QueueNode<T> *qn = new QueueNode<T>;
    qn->data = x;
    qn->next = NULL;
    this->rear->next = qn;
    this->rear = qn;
    return true;
}

template<typename T>
bool LinkQueue<T>::delet(T &x)
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return false;
    }
    else
    {
        QueueNode<T> *qn;
        x = this->front->next->data;
        qn = this->front->next;
        this->front->next = this->front->next->next;
        if(qn == this->rear)
            this->rear = this->front;
        delete qn;
        return true;
    }
}

template<typename T>
T LinkQueue<T>::delet()
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return NULL;
    }
    else
    {
        QueueNode<T> *qn;
        T x;
        x = this->front->next->data;
        qn = this->front->next;
        this->front->next = this->front->next->next;
        if(qn == this->rear)
            this->rear = this->front;
        delete qn;
        return x;
    }
}

template<typename T>
bool LinkQueue<T>::head(T &x) const
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return false;
    }
    else
    {
        x = this->front->next->data;
        return true;
    }
}

template<typename T>
T LinkQueue<T>::head() const
{
    if(this->isempty())
    {
        cout << "queue is empty" << endl;
        return NULL;
    }
    else
    {
        return this->front->next->data;
    }
}

template<typename T>
void LinkQueue<T>::clear()
{
    QueueNode<T> *qn;
    while(this->front->next)
    {
        qn = this->front->next;
        this->front->next = this->front->next->next;
        delete qn;
    }
    this->rear = this->front;
}

#endif // LINKQUEUE_H
