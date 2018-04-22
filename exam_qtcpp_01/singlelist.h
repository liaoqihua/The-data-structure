#ifndef SINGLELIST_H
#define SINGLELIST_H
#include "linearlist.h"
template<typename T> class singlelist;

template<typename T>
class node
{
private:
    T data;
    node<T> *next;
    friend class singlelist<T>;
};

template<typename T>
class singlelist:public linearlist<T>
{
public:
    singlelist();
    ~singlelist();
    bool isempty() const;
    int length() const;
    bool find(int i, T &x) const;
    int search(T x) const;
    bool insert(int i, T x);
    bool delet(int i);
    bool update(int i, T x);
    void output(ostream &out) const;
private:
    node<T> *head;
};

template<typename T>
singlelist<T>::singlelist()
{
    //创建头节点
    node<T> *p = new node<T>;
    p->data = static_cast<T>(0);
    p->next = NULL;
    this->head = p;
    this->n = 0;
}

template<typename T>
singlelist<T>::~singlelist()
{
    //从头节点开始释放内存
    node<T> *p = this->head;
    while(p)
    {
        p = p->next;
        delete this->head;
        this->head = p;
    }
}

template<typename T>
bool singlelist<T>::insert(int i, T x)
{
    if(i<-1||i>this->n)//插入值从第0个位置开始插入
    {
        cout << "out of bounds" << endl;
        return false;
    }
    node<T> *n = new node<T>();
    n->data = x;
    node<T> *p = this->head;
    for(int j=0;j<i;j++)
    {
        p = p->next;
    }
    if(i>-1)
    {
        n->next = p->next;
        p->next = n;
    }
    else//输入-1表示从最后插入值
    {
        while(p->next)
        {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
    }
    this->n++;
    return true;
}

template<typename T>
bool singlelist<T>::delet(int i)
{
    if(i<-1||i>this->n)
    {
        cout << "out of bounds" << endl;
        return false;
    }
    node<T> *p = this->head;
    if(i>-1)
    {
        for(int j=0;j<i;j++)
        {
            p = p->next;
        }
        node<T> *q = p->next;
        p->next = p->next->next;
        delete q;
    }
    else//输入-1表示从最后一个元素删除
    {
        node<T> *q = this->head;
        while(p->next)
        {
            q = p;
            p = p->next;
        }
        if(p->next==q->next)//是空链表时候会出现p和q都为NULL
        {
            cout << "link is empty" << endl;
            return false;
        }
        else
        {
            q->next = p->next;
            delete p;
        }
    }
    this->n--;
    return true;
}

template<typename T>
bool singlelist<T>::update(int i, T x)
{
    if(i<-1||i>this->n)
    {
        cout << "out of bounds" << endl;
        return false;
    }
    node<T> *p = this->head;
    if(i>-1)
    {
        for(int j=0;j<i;j++)
        {
            p = p->next;
        }
        p->next->data = x;
    }
    else//输入-1表示从最后一个位置修改元素值
    {
        while(p->next)
        {
            p = p->next;
        }
        p->data = x;
    }
    return true;
}

template<typename T>
bool singlelist<T>::isempty() const
{
    return this->n==0;
}

template<typename T>
int singlelist<T>::length() const
{
    return this->n;
}

template<typename T>
bool singlelist<T>::find(int i, T &x) const
{
    if(i<-1||i>this->n)
    {
        cout << "out of bounds" << endl;
        return false;
    }
    node<T> *p = this->head;
    if(i>-1)
    {
        for(int j=0;j<i;j++)
        {
            p = p->next;
        }
        x = p->next->data;
    }
    else//寻找最后一个元素，并保存在x中
    {
        while(p->next)
        {
            p = p->next;
        }
        x = p->data;
    }
    return true;
}

template<typename T>
int singlelist<T>::search(T x) const
{
    node<T> *p = this->head->next;
    for(int j=0;p;j++)
    {
        if(p->data==x)
            return j;
        p = p->next;
    }
    return 0;
}

template<typename T>
void singlelist<T>::output(ostream &out) const
{
    node<T> *p = this->head->next;

    while(p)
    {
        out << p->data << " ";
        p = p->next;
    }
    out << endl;
}


#endif // SINGLELIST_H
