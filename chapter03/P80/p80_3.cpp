/* 
    ��������ջģ��һ�����У����ӡ���ӡ��жӿգ���
    ˼�룺����Ҫ������в���һ��Ԫ��ʱ����s1����������Ԫ�أ���s1ִ����ջ������
        ����Ҫ����ʱ����s2ִ�г�ջ���������ڴ�ջ�г���˳����ԭ˳�����������ģ�����ʱ���Ƚ�s1������Ԫ�س�ջ������s2ջ���ٶ�s2ִ�г�ջ������
    ����ʵ�ֳ��Ӳ�������ִ�д˲���ǰ�������ж�s2�Ƿ�Ϊ�գ�����ᵼ��˳����ң���ջs1��s2��Ϊ��ʱ������Ϊ�ա�
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
        return true; //ջ��
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
        cout << "ջ������ջʧ�ܣ�" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool pop(stack1 &s, int &x)
{
    if (s.top == -1)
    {
        cout << "ջ�գ���ջʧ�ܣ�" << endl;
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
    if (!isFull(s1)) //s1����
    {
        push(s1, e); //ֱ�ӽ���
        return 1;
    }
    if (isFull(s1) && !isEmpty(s2)) //s1����s2��Ϊ��
    {
        cout << "������" << endl; 
        return 0;
    }
    if (isFull(s1) && isEmpty(s2)) //s1����s2Ϊ��
    {
        int x;
        while (!isEmpty(s1)) //s1��s2
        {
            pop(s1, x);
            push(s1, x);
        }
    }
    push(s1, e); //��s1����ӣ�
    return 1;
}

void deQuene(stack1 &s1, stack1 &s2, int &x)
{
    if (!isEmpty(s2)) //s2��Ϊ��
    {
        pop(s2, x);
    }
    else if (isEmpty(s1)) //s2Ϊ�գ�s1Ϊ��
    {
        cout << "����Ϊ��" << endl;
    }
    else //s2Ϊ�գ�s1��Ϊ��
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
    cout<<"ģ����ӣ�"<<endl;
    for(int i=0;i<Maxsize;i++){
        enQuene(s1,s2,i);
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"ģ����ӣ�"<<endl;
    for(int i=0;i<Maxsize;i++){
        int x;
        deQuene(s1,s2,x);
        cout<<x<<" ";
    }
    cout <<endl;

    return 0;
}