/* 
    ������ȣ���n��Ӳ��������������ᣨ�ֱ���H��S��ʾ�������õ���ջ������ջ���ջ�������������е�����������������е�Ӳ�������ǰ�档
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
bool push(stack1 &s, elemtype x)
{
    if (isFull(s))
    {
        cout << "ջ������ջʧ�ܣ�" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool pop(stack1 &s, elemtype &x)
{
    if (isEmpty(s))
    {
        cout << "ջ�գ���ջʧ�ܣ�" << endl;
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
        if (train[i] == 'H') //Ӳ������ջ
        {
            push(s, train[i]);
        }
        else //��������ǰ����
        {
            train[k++] = train[i];
        }
        i++;
    }
    while (!isEmpty(s)) //���Ӳ����ջ�������������
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