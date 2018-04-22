#ifndef BTREE_H
#define BTREE_H
#include "linkstack.h"
#include <iostream>
using namespace std;

template<typename T> class Btree;

template<typename T>
class TreeNode
{
    T data;
    TreeNode *left, *right;
    TreeNode();
    TreeNode(T data);
    TreeNode(T data, TreeNode *left, TreeNode *right);
    friend class Btree<T>;
};

template<typename T>
TreeNode<T>::TreeNode()
{
}

template<typename T>
TreeNode<T>::TreeNode(T data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

template<typename T>
TreeNode<T>::TreeNode(T data, TreeNode *left, TreeNode *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

template<typename T>
class Btree
{
public:
    Btree();
    Btree(T x);
    Btree(T x, Btree<T> *l, Btree<T> *r);
    ~Btree();
    TreeNode<T>* createBtree();
    bool isempty() const;
    void clear(TreeNode<T> *tn);
    bool Root(T &x) const;
    TreeNode<T>* Root() const;
    void maketree(T x, Btree<T> *left, Btree<T> *right);
    void breaktree(T &x, Btree<T> *left, Btree<T> *right);
    void preorder(TreeNode<T> *bt);
    void preorderUseStack(TreeNode<T> *bt);
    void inorder(TreeNode<T> *bt);
    void inorderUseStack(TreeNode<T> *bt);
    void postorder(TreeNode<T> *bt);
    void postorderUseStack(TreeNode<T> *bt);
    int getDepth(TreeNode<T> *bt);
    int countLeaf(TreeNode<T> *bt);
    void visit(TreeNode<T> *bt) const;
private:
    TreeNode<T> *root;
};

template<typename T>
Btree<T>::Btree()
{
    cout << "开始先序创建二叉树:" << endl;
    this->root = this->createBtree();
}

template<typename T>
TreeNode<T>* Btree<T>::createBtree()
{
    T x;
    cin >> x;
    if(!x)
    {
        return NULL;
    }

    TreeNode<T> *tn = new TreeNode<T>(x);
    tn->left = this->createBtree();
    tn->right = this->createBtree();
    return tn;
}

template<typename T>
Btree<T>::Btree(T x)
{
    this->root = new TreeNode<T>(x);
}

template<typename T>
Btree<T>::Btree(T x, Btree<T> *l, Btree<T> *r)
{
    if(this->root||l==r)
        return ;
    this->root = new TreeNode<T>(x, l->root, r->root);
    l->root = NULL;
    r->root = NULL;
}

template<typename T>
Btree<T>::~Btree()
{
    this->clear(this->Root());
}

template<typename T>
bool Btree<T>::isempty() const
{
    return this->root == NULL;
}

template<typename T>
void Btree<T>::clear(TreeNode<T> *tn)
{
    if(tn)
    {
        this->clear(tn->left);
        this->clear(tn->right);
        delete tn;
    }
    return ;
}

template<typename T>
TreeNode<T>* Btree<T>::Root() const
{
    return this->root;
}

template<typename T>
bool Btree<T>::Root(T &x) const
{
    x = this->root->data;
}

template<typename T>
void Btree<T>::maketree(T x, Btree<T> *left, Btree<T> *right)
{
    if(this->root||left==right)
        return ;
    this->root = new TreeNode<T>(x, left->root, right->root);
    left->root = NULL;
    right->root = NULL;
    return ;
}

template<typename T>
void Btree<T>::breaktree(T &x, Btree<T> *left, Btree<T> *right)
{
    if(this->root||left==right||left->root||right->root)
        return ;
    x = this->root->data;
    left->root = this->root->left;
    right->root = this->root->right;
    delete this->root;
    this->root = NULL;
}

template<typename T>
void Btree<T>::visit(TreeNode<T> *bt) const
{
    cout << bt->data << " ";
}

template<typename T>
void Btree<T>::preorder(TreeNode<T> *bt)
{
    if(bt)
    {
        this->visit(bt);
        this->preorder(bt->left);
        this->preorder(bt->right);
    }
    return ;
}

template<typename T>
void Btree<T>::preorderUseStack(TreeNode<T> *bt)
{
    if(!bt)
        return ;
    LinkStack< TreeNode<T>* > s;
    do
    {
        while(bt)
        {
            this->visit(bt);
            s.push(bt);
            bt = bt->left;
        }
        if(!s.isempty())
        {
            bt = s.pop();
            bt = bt->right;
        }
    }while(s.getTop()||bt);
}

template<typename T>
void Btree<T>::inorder(TreeNode<T> *bt)
{
    if(bt)
    {
        this->inorder(bt->left);
        this->visit(bt);
        this->inorder(bt->right);
    }
    return ;
}

template<typename T>
void Btree<T>::inorderUseStack(TreeNode<T> *bt)
{
    if(!bt)
        return ;
    LinkStack< TreeNode<T>* > s;
    do
    {
        while(bt)
        {
            s.push(bt);
            bt = bt->left;
        }
        if(!s.isempty())
        {
            bt = s.pop();
            this->visit(bt);
            bt = bt->right;
        }
    }while(s.getTop()||bt);
}


template<typename T>
void Btree<T>::postorder(TreeNode<T> *bt)
{
    if(bt)
    {
        this->postorder(bt->left);
        this->postorder(bt->right);
        this->visit(bt);
    }
    return ;
}

template<typename T>
void Btree<T>::postorderUseStack(TreeNode<T> *bt)
{
    if(!bt)
        return ;
    LinkStack< TreeNode<T>* > lls;
    LinkStack< TreeNode<T>* > rls;
    TreeNode<T> *temp;
    do
    {
        while(bt)
        {
            lls.push(bt);
            bt = bt->left;
        }
        if(!lls.isempty())
        {
            bt = lls.pop();
            rls.push(bt);
            bt = bt->right;
            while(!bt&&!rls.isempty())
            {
                temp = rls.pop();
                this->visit(temp);
                if(rls.getTop()==NULL||rls.getTop()->right!=temp)
                {
                    break;
                }
            }
        }
    }while(lls.getTop()||rls.getTop()||bt);
}

template<typename T>
int Btree<T>::getDepth(TreeNode<T> *bt)
{
    int m, n;
    if(!bt)
        return 0;
    else
    {
        m = this->getDepth(bt->left);
        n = this->getDepth(bt->right);
        return (m>n?m:n)+1;
    }
}

template<typename T>
int Btree<T>::countLeaf(TreeNode<T> *bt)
{
    int i;
    if(bt==NULL)
        i = 0;
    else if((bt->left)==NULL&&(bt->right)==NULL)
        i = 1;
    else
    {
        i = this->countLeaf(bt->left) + this->countLeaf(bt->right);
    }
    return i;
}

#endif // BTREE_H
