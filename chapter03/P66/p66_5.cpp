/* 
    共享栈。
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
{ //入栈，i表示栈号，入战成功则返回1，否则返回-1，x为入栈元素
    if (i < 0 || i > 1)
    {
        cout << "栈号输入错误！" << endl;
        return -1;
    }
    if (s.top[1] - s.top[0] == 1)
    {
        cout << "栈满" << endl;
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
{ //出栈，i表示栈号，出战成功则返回出栈元素，否则返回-1
    if (i < 0 || i > 1)
    {
        cout << "栈号输入错误！" << endl;
        return -1;
    }
    switch (i)
    {
    case 0:
        if (s.top[0] == -1)
        {
            cout << "栈空" << endl;
            return -1;
        }
        else
        {
            cout << "出栈" << endl;

            return s.data[s.top[0]--];
        }
        break;
    case 1:
        if (s.top[1] == Maxsize)
        {
            cout << "栈空" << endl;
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
        cout << "0号栈入栈成功！" << endl;
    int i= 5;
    while (i)
    {
        int x = pop(0);
        if (x != -1)
        {
            cout << "0号栈出栈成功！" << endl;
            cout << "0号栈出栈元素为" << x << endl;
        }
        i--;
    }

    return 0;
}