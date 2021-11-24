/* 
    ����ջ��������Ԫ�����á�
 */
#include <iostream>
using namespace std;
#define Maxsize 10
typedef struct
{
    int data[Maxsize];
    int top;
} stack1;
typedef struct
{
    int data[Maxsize];
    int f, r, tag;
} squene;

bool isEmpty(squene q)
{
    if (q.f == q.r && q.tag == 0)
        return true; //�ӿ�
    else
        return false;
}

bool enQuene(squene &q, int x)
{
    if (q.f == q.r && q.tag == 1)
    {
        cout << "����������ʧ�ܣ�" << endl;
        return false;
    }
    q.data[q.r] = x;
    q.r = (q.r + 1) % Maxsize;
    q.tag = 1;
    return true;
}
bool deQuene(squene &q, int &x)
{
    if (q.f == q.r && q.tag == 0)
    {
        cout << "�ӿգ�����ʧ�ܣ�" << endl;
        return false;
    }
    x = q.data[q.f];
    q.f = (q.f + 1) % Maxsize;
    q.tag = 0;
    return true;
}

bool isEmpty(stack1 s)
{
    if (s.top == -1)
        return true; //ջ��
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
void display(squene q)
{
    for (int i = 0; i < Maxsize; i++)
    {
        cout << q.data[q.f] << " ";
        q.f = (q.f + 1) % Maxsize;
    }
    cout << endl;
}

void Inverser(stack1 &s, squene &q)
{
    int x;
    while (!isEmpty(q))
    {
        deQuene(q, x);
        push(s, x);
    }
    while (!isEmpty(s))
    {
        pop(s, x);
        enQuene(q, x);
    }
}

int main()
{
    squene q;
    q.f = q.r = 0;
    q.tag = 0;
    stack1 s;
    s.top = -1;
    for (int i = 0; i < Maxsize; i++)
    {
        enQuene(q, i);
    }
    display(q);
    Inverser(s, q);
    display(q);
    return 0;
}