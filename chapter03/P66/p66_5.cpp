/* 
    ����ջ��
 */
#include <bits/stdc++.h>
using namespace std;
#define Maxsize 50

typedef struct
{
    int data[Maxsize];
    int top[2];
} stack1;

stack1 s;

int push(int i, int x)
{ //��ջ��i��ʾջ�ţ���ս�ɹ��򷵻�1�����򷵻�-1��xΪ��ջԪ��
    if (i < 0 || i > 1)
    {
        cout << "ջ���������" << endl;
        return -1;
    }
    if (s.top[1] - s.top[0] == 1)
    {
        cout << "ջ��" << endl;
        return -1;
    }
    switch (i)
    {
    case 0:
        s.data[++s.top[0]] = x;
        return 1;
        break;
    case 1:
        s.data[--s.top[1]] = x;
        return 1;
    }
}

int pop(int i)
{ //��ջ��i��ʾջ�ţ���ս�ɹ��򷵻س�ջԪ�أ����򷵻�-1
    if (i < 0 || i > 1)
    {
        cout << "ջ���������" << endl;
        return -1;
    }
    switch (i)
    {
    case 0:
        if (s.top[0] == -1)
        {
            cout << "ջ��" << endl;
            return -1;
        }
        else
        {
            cout << "��ջ" << endl;

            return s.data[s.top[0]--];
        }
        break;
    case 1:
        if (s.top[1] == Maxsize)
        {
            cout << "ջ��" << endl;
            return -1;
        }
        else
        {
            return s.data[s.top[1]++];
        }
    }
}

int main()
{
    s.top[0] = -1, s.top[1] = Maxsize;
    if (push(0, 1) == 1)
        cout << "0��ջ��ջ�ɹ���" << endl;
    int i= 5;
    while (i)
    {
        int x = pop(0);
        if (x != -1)
        {
            cout << "0��ջ��ջ�ɹ���" << endl;
            cout << "0��ջ��ջԪ��Ϊ" << x << endl;
        }
        i--;
    }

    return 0;
}