/* 
    �ڶ������в���ֵΪx�Ľ�㣬��д�㷨����ӡֵΪx�Ľ����������ȡ�����ֵΪx�Ľ�㲻����1����
    �㷨˼�룺���ú���ǵݹ�����㷨��ջ�б���Ľ����ǵ�ǰ�ڵ���������Ƚ�㡣��������ֵΪx�Ľ��ʱ���������ջ�н���ֵ����Ϊ�������ȵ�ֵ��
 */
#include <iostream>
using namespace std;
#define Maxsize 50
#define elemtype BiTree

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
    int tag;
} BiTNode, *BiTree;

//�ݹ齨��������������
void creatBiTree(BiTree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (BiTNode *)malloc(sizeof(BiTNode));
        t->data = ch;
        t->tag = 0;
        t->lchild = NULL;
        t->rchild = NULL;
        creatBiTree(t->lchild);
        creatBiTree(t->rchild);
    }
}
void disp(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        disp(T->lchild);
        disp(T->rchild);
    }
}

//----ջ------------------
typedef struct
{
    elemtype data[Maxsize];
    int top;
} stack1;

void InitStack(stack1 &s)
{
    s.top = -1;
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
    x = s.data[s.top--]; //��ȡջ��Ԫ�أ�����ջ��ָ��-1
    return true;
}

void Search(BiTree T, char x)
{
    BiTNode *p = T;
    stack1 s;
    InitStack(s);
    while (p || !isEmpty(s)) //����ĺ���ǵݹ��㷨
    {
        if (p) //����㲻Ϊ��ʱ
        {
            if (p->data == x) //������ֵΪx���������ջ�������Ƚ���ֵ
            {
                cout << "��������������Ƚ���ֵΪ��" << endl;
                for (int i = s.top; i >= 0; i--)
                    cout << s.data[i]->data << " ";
                cout << endl;
                exit(0);
            }
            push(s, p);    //��ջ
            p = p->lchild; //һֱ������
        }
        else //�����Ϊ�յ����
        {
            p = s.data[s.top]; //�ж�ջ�������Һ��ӣ����Һ��Ӵ��ڣ�ת����
            if (p->rchild && p->rchild->tag == 0)
                p = p->rchild;
            else //���򣬳�ջ������
            {
                pop(s, p);
                p->tag = 1;
                p = NULL; //p��Ϊ��
            }
        }
    }
    cout << "������ֵΪ" << x << "�Ľ�㣡" << endl;
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "��������";
    disp(T);
    cout << endl;
    char x;
    cout << "������Ҫ���ҵĽ���ֵ:";
    cin >> x;
    Search(T, x);
    return 0;
}
//��������
/* 
ABD##E##CF##G##
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */
/* 
ABD##E##C#G##
                A
              /   \
            B       C
          /  \        \
         D    E        G
 */
