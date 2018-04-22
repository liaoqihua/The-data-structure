#include "seqstring.h"

int main()
{
    SeqString ss("hello");
    SeqString ss1(" world");
    cout << ss << ss1 << endl;//hello world
    cout << (ss+ss1) << endl;//hello world
    cout << (ss+=ss1) << endl;//ss hello world ss1  world
    cout << ss << ss1 << endl;//hello world  world
    cout << ss(1, 4) << endl;//ell
    cout << ss << endl;
    cout << ss.index("hello") << endl;//"" -1 h 0 l 2 o 4 orld 7 orl 7
    ss = ss1;
    cout << ss << ss1 << endl;// world  world
    ss += ss1;
    cout << ss << endl;// world world
    ss.delet(0, 4);//ld world
    ss.delet(1, 3);//lorld
    cout << ss << endl;
    ss.insert(2, "wor");//loworrld
    cout << ss << endl;
    ss.delet(4, 4);//lowo
    ss.delet(3, 10);//low
    cout << ss << endl;
    ss.delet(0, 1);//ow
    cout << ss << endl;
    ss.insert(0, "le");
    ss.insert(4, "owowowowhello");
    cout << ss << endl;
    ss.replace("ow", "t");
    cout << ss << endl;


    return 0;
}
