/* 
    ����ջʵ������ƥ�䡣
 */
#include <iostream>
using namespace std;
#define Maxsize 50
#define elemtype char 

//----ջ-----------------------------------------------------------------------------------------------------------------------
typedef struct
{
    elemtype data[Maxsize];
    int top;
} stack1;

void InitStack(stack1 &s)
{
    s.top=-1;
}

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
    s.data[++s.top] = x; //ջ��ָ����+1������ջ
    return true;
}

bool pop(stack1 &s, elemtype &x)
{
    if (isEmpty(s))
    {
        cout << "ջ�գ���ջʧ�ܣ�" << endl;
        return false;
    }
    x = s.data[s.top--];//��ȥջ��Ԫ�أ�����ջ��ָ��-1
    return true;
}



bool BracketsCheck(char *str)
{
    stack1 s;
    s.top = -1;
    int i = 0;
    char e;
    while (str[i] != '\0')
    {
        switch (str[i])
        {
        case '(':
            push(s, '(');
            break;
        case '{':
            push(s, '{');
            break;
        case '[':
            push(s, '[');
            break;
        case ')':
            pop(s, e);
            if (e != '(')
                return false;
            break;
        case '}':
            pop(s, e);
            if (e != '{')
                return false;
            break;
        case ']':
            pop(s, e);
            if (e != '[')
                return false;
            break;
        default:
            break;
        }
        i++;
    }
    if (!isEmpty(s))
        return false;
    else
        return true;
}

int main()
{
    char *str = (char *)"{asd(asd){afs}[afa]asf}";
    cout << str << endl;
    if (BracketsCheck(str))
        cout << "����ƥ�䣡" << endl;
    else
        cout << "���Ų�ƥ�䣡" << endl;
    return 0;
}