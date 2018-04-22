#include "seqlist.h"
#include "singlelist.h"

int main()
{
    seqlist<int> list(10);
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);
    list.output(cout);

    singlelist<int> slist;
    slist.insert(0, 1);
    slist.insert(1, 3);
    slist.insert(2, 4);
    slist.insert(-1, 2);
    slist.output(cout);//1342
    slist.delet(0);
    slist.output(cout);//342
    slist.insert(-1, 5);
    slist.output(cout);//3425
    slist.delet(-1);
    slist.output(cout);//342
    slist.insert(-1, 6);
    slist.output(cout);//3426
    slist.delet(2);
    slist.output(cout);//346
    slist.update(1, 2);
    slist.update(-1, 5);
    slist.output(cout);//325
    cout << "isempty:" << slist.isempty() << endl;
    cout << "length:" << slist.length() << endl;
    int x;
    slist.find(1, x);
    cout << "find 1 x:" << x << endl;
    cout << "search 2:" << slist.search(2) << endl;

    return 0;
}
