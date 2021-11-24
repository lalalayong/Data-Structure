/* 
    利用两个栈模拟一个队列（出队、入队、判队空）。
    思想：当需要向队列中插入一个元素时，用s1存放已输入的元素，即s1执行入栈操作。
        当需要出队时，对s2执行出栈操作，由于从栈中出的顺序是原顺序的逆序，所以模拟出队时，先将s1中所有元素出栈并进入s2栈，再对s2执行出栈操作，
    即可实现出队操作，在执行此操作前必须先判断s2是否为空，否则会导致顺序混乱，当栈s1和s2都为空时，队列为空。
 */
#include <iostream>
using namespace std;
#define Maxsize 10
typedef struct
{
    int data[Maxsize];
    int top;
} stack1;

bool isEmpty(stack1 s)
{
    if (s.top == -1)
        return true; //栈空
    else
        return false;
}

bool isFull(stack1 s)
{
    if (s.top == Maxsize - 1)
        return true;
    else
        return false;
}

bool push(stack1 &s, int x)
{
    if (s.top == Maxsize - 1)
    {
        cout << "栈满，入栈失败！" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool pop(stack1 &s, int &x)
{
    if (s.top == -1)
    {
        cout << "栈空，出栈失败！" << endl;
        return false;
    }
    x = s.data[s.top--];
    return true;
}

void disp(stack1 s)
{
    int top1 = s.top;
    while (top1 != -1)
    {
        cout << s.data[top1] << " ";
        top1--;
    }
    cout << endl;
}

int enQuene(stack1 &s1, stack1 &s2, int e)
{
    if (!isFull(s1)) //s1不满
    {
        push(s1, e); //直接进队
        return 1;
    }
    if (isFull(s1) && !isEmpty(s2)) //s1满，s2不为空
    {
        cout << "队列满" << endl; 
        return 0;
    }
    if (isFull(s1) && isEmpty(s2)) //s1满，s2为空
    {
        int x;
        while (!isEmpty(s1)) //s1入s2
        {
            pop(s1, x);
            push(s1, x);
        }
    }
    push(s1, e); //入s1（入队）
    return 1;
}

void deQuene(stack1 &s1, stack1 &s2, int &x)
{
    if (!isEmpty(s2)) //s2不为空
    {
        pop(s2, x);
    }
    else if (isEmpty(s1)) //s2为空，s1为空
    {
        cout << "队列为空" << endl;
    }
    else //s2为空，s1不为空
    {
        while (!isEmpty(s1))
        {
            pop(s1, x);
            push(s2, x);
        }
        pop(s2, x);
    }
}
int QueneEmpty(stack1 s1, stack1 s2)
{
    if (isEmpty(s1) && isEmpty(s2))
        return 1;
    else
        return 0;
}

int main()
{
    stack1 s1;
    s1.top = -1;
    stack1 s2;
    s2.top = -1;
    cout<<"模拟入队："<<endl;
    for(int i=0;i<Maxsize;i++){
        enQuene(s1,s2,i);
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"模拟出队："<<endl;
    for(int i=0;i<Maxsize;i++){
        int x;
        deQuene(s1,s2,x);
        cout<<x<<" ";
    }
    cout <<endl;

    return 0;
}