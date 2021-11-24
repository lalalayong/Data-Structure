/* 
    车厢调度，有n节硬座车厢和软座车厢（分别用H和S表示），利用调度栈道（入栈或出栈操作），将所有的软座车厢调整到所有的硬座车厢的前面。
 */
#include <iostream>
using namespace std;
#define Maxsize 50
#define elemtype char

typedef struct
{
    elemtype data[Maxsize];
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
bool push(stack1 &s, elemtype x)
{
    if (isFull(s))
    {
        cout << "栈满，入栈失败！" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool pop(stack1 &s, elemtype &x)
{
    if (isEmpty(s))
    {
        cout << "栈空，出栈失败！" << endl;
        return false;
    }
    x = s.data[s.top--];
    return true;
}

void Train_Arrrange(char train[])
{
    int i = 0, k = 0;
    stack1 s;
    s.top = -1;
    while (train[i])
    {
        if (train[i] == 'H') //硬座，入栈
        {
            push(s, train[i]);
        }
        else //软座，向前调整
        {
            train[k++] = train[i];
        }
        i++;
    }
    while (!isEmpty(s)) //最后将硬座出栈，放在软座后边
    {
        char c;
        pop(s, c);
        train[k++] = c;
    }
}

int main()
{
    char train[] = "HSHSHHSHHSSHSH";
    cout << train << endl;
    Train_Arrrange(train);
    cout << train << endl;
    return 0;
}