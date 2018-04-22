#include "seqstack.h"
#include "linkstack.h"

void dcb_stack()
{
    int num;
    cout << "请输入要计算的数:";
    cin >> num;

    LinkStack<int> ls;
    while(num)
    {
        ls.push(num%2);
        num = num / 2;
    }
    cout << "十进制转化为二进制的结果是:";
    while(!ls.isempty())
    {
        cout << ls.pop();
    }
    cout << endl;
}

int get_pri(char ch)
{
    switch (ch) {
    case '+':return 1;
    case '-':return 1;
    case '/':return 2;
    case '*':return 2;
    case '#':return 0;
    }
    return -1;
}

bool isInString(char *str, char ch)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(ch==str[i])
            return true;
    }
    return false;
}

void compute_exp()
{
    char ch, theta;
    int x, y, result;
    char str[6]="+-*/#";
    LinkStack<int> ls1;
    LinkStack<char> ls2;
    ls2.push('#');
    cout << "请输入表达式:";
    if(cin.peek()!='\n')
        cin >> ch;
    else
        ch = '#';
    do{
        if(ch<='9'&&ch>='0')
        {
            ls1.push(ch-'0');
        }

        if(isInString(str, ch))
        {
            if(get_pri(ch)>get_pri(ls2.getTop()))
            {
                ls2.push(ch);
            }
            else
            {
                theta = ls2.pop();
                y = ls1.pop();
                x = ls1.pop();
                result = [x, theta, y](){
                    switch(theta)
                    {
                    case '+':return (x+y);
                    case '-':return (x-y);
                    case '*':return (x*y);
                    case '/':return (x/y);
                    }
                    return -1;
                }();
                ls1.push(result);
                continue;
            }
        }
        if(cin.peek()!='\n')
            cin >> ch;
        else
            ch = '#';
    }while((ch!='#')||(ls2.getTop()!='#'));

    cout << "结果为:" << ls1.pop() << endl;
}

int main()
{
    SeqStack<int> ss(5);
    for(int i=1;i<=11;i++)
    {
        ss.push(10*i);
    }//初始化长度为5，存入11个，过载6
    for(int i=0;i<5;i++)
    {
        cout << ss.pop() << " ";
    }//50 40 30 20 10
    cout << endl;
    for(int i=1;i<=11;i++)
    {
        ss.push(10*i);
    }//初始化长度为5，存入11个，过载6
    for(int i=0;i<5;i++)
    {
        int x;
        ss.pop(x);
        cout << x << " ";
    }
    cout << endl;

    SeqStack<int> ss1;//采用默认模式初始化stack，长度为10
    for(int i=1;i<=11;i++)
    {
        ss1.push(10*i);
    }//100 90 80 70 60 50 40 30 20 10
    cout << ss1.getTop() << " ";
    int x;
    ss1.getTop(x);
    cout << x << endl;

    LinkStack<int> ls;
    for(int i=1;i<=6;i++)
    {
        ls.push(5*i);
    }
    cout << "top element is " << ls.getTop() << endl;
    for(int i=0;i<6;i++)
    {
        cout << ls.pop() << " ";
    }

    cout << endl;
    ls.getTop();

    //dcb_stack();
    compute_exp();

    return 0;
}
