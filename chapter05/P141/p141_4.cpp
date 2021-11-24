/* 
    �����α������������ϣ���������
    ˼�룺�����α����㷨������֮�󲻷��ʣ�����Ϊ��ջ��������γ�ջ����Ϊ�����α�����
 */
#include <iostream>
using namespace std;
#define Maxsize 50
#define elemtype BiTree

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
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
        t->lchild = NULL;
        t->rchild = NULL;
        creatBiTree(t->lchild);
        creatBiTree(t->rchild);
    }
}

//----ջ-----------------------------------------------------------------------------------------------------------------------
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
    x = s.data[s.top--]; //��ȥջ��Ԫ�أ�����ջ��ָ��-1
    return true;
}

//----����----------------------------------------------------------------------------------------------------------------------
typedef struct
{
    elemtype data[Maxsize];
    int f, r, tag;
} quene;

void InitQuene(quene &q)
{
    q.f = q.r = q.tag = 0;
}

bool isEmpty(quene q)
{
    if (q.f == q.r && q.tag == 0)
        return true; //�ӿ�
    else
        return false;
}
bool isFull(quene q)
{
    if (q.f == q.r && q.tag == 1)
        return true; //����
    else
        return false;
}

bool enQuene(quene &q, elemtype x)
{
    if (isFull(q))
    {
        cout << "����������ʧ�ܣ�" << endl;
        return false;
    }
    q.data[q.r] = x;
    q.r = (q.r + 1) % Maxsize;
    q.tag = 1;
    return true;
}
bool deQuene(quene &q, elemtype &x)
{
    if (isEmpty(q))
    {
        cout << "�ӿգ�����ʧ�ܣ�" << endl;
        return false;
    }
    x = q.data[q.f];
    q.f = (q.f + 1) % Maxsize;
    q.tag = 0;
    return true;
}
void display(quene q)
{
    for (int i = 0; i < Maxsize; i++)
    {
        cout << q.data[q.f] << " ";
        q.f = (q.f + 1) % Maxsize;
    }
    cout << endl;
}

void InvertLevel(BiTree T)
{
    stack1 s;
    quene q;
    BiTNode *p;
    if (T)
    {
        InitQuene(q);
        InitStack(s);
        enQuene(q, T);
        while (!isEmpty(q)) //��α���
        {
            deQuene(q, p);
            push(s, p);//���Ӻ���ջ����α����ǳ��Ӻ���ʣ�
            if (p->lchild)
                enQuene(q, p->lchild); //�����ӣ����
            if (p->rchild)
                enQuene(q, p->rchild);//���Һ��ӣ����
        }
        while (!isEmpty(s)) //ջ�д�ŵ��ǲ�α�������
        {
            pop(s, p); //���γ�ջ���õ��ı��Ƿ����α���
            cout << p->data << " ";
        }
    }
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "�����α�����";
    InvertLevel(T);
    return 0;
}
//ABD##E##CF##G##
/* 
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */