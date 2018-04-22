#include "btree.h"

int main()
{
    Btree<int> bt;
    bt.preorder(bt.Root());//1 2 3 4
    cout << endl;
    bt.inorder(bt.Root());//2 3 1 4
    cout << endl;
    bt.postorder(bt.Root());//3 2 4 1
    cout << endl;
    bt.preorderUseStack(bt.Root());//1 2 3 4
    cout << endl;
    bt.inorderUseStack(bt.Root());//2 3 1 4
    cout << endl;
    bt.postorderUseStack(bt.Root());//3 2 4 1
    cout << endl;
    cout << bt.getDepth(bt.Root()) << endl;
    cout << bt.countLeaf(bt.Root()) << endl;
    return 0;
}
