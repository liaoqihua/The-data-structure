#include "seqqueue.h"
#include "linkqueue.h"

using namespace std;

int main()
{
    SeqQueue<int> sq(10);
    sq.enter(10);
    cout << sq.head() << endl;//10
    for(int i=0;i<11;i++)
    {
        sq.enter(5 * i);
    }//总共插入12个数，将会出现3个报错//10 0 5 10 15 20 25 30 35
    cout << sq.head() << endl;
    for(int i=0;i<5;i++)
    {
        cout << sq.delet() << " ";
    }//20 25 30 35
    cout << endl;
    for(int i=0;i<6;i++)
    {
        sq.enter(10 * i);
    }//0 10 20 30 40 | 20 25 30 35
    for(int i=0;i<9;i++)
    {
        cout << sq.delet() << " ";
    }
    cout << endl;

    LinkQueue<int> lq;
    for(int i=0;i<5;i++)
    {
        lq.enter(10 * i);
    }
    for(int i=0;i<6;i++)
    {
        cout << lq.delet() << " ";
    }
    cout << endl;
    for(int i=0;i<5;i++)
    {
        lq.enter(10 * i);
    }
    lq.clear();
    cout << lq.head() << endl;

    return 0;
}
