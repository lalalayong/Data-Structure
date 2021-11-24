/* 
    ���������������򡢺���ǵݹ������
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

//����ǵݹ�
void postOrder(BiTree T)
{
    stack1 s;
    s.top = -1; //��ʼ��һ��ջs
    BiTNode *p = T;
    while (p || !isEmpty(s))
    {
        if (p) //�ߵ������
        {
            push(s, p);
            p = p->lchild;
        }
        else //����
        {
            p = s.data[s.top];                    //��ջ�����
            if (p->rchild && p->rchild->tag == 0) //�������������ڣ���δ�����ʹ�
                p = p->rchild;                    //ת����
            else                                  //���򵯳���㲢����
            {
                pop(s, p);              //����ջ�����
                cout << p->data << " "; //����
                p->tag = 1;             //���ʱ��
                p = NULL;               //�������������pָ�루ÿ��ͨ��ջ������ж���һ��Ҫ���ʣ�
            }
        }
    }
}

//����ǵݹ�
void inOrder(BiTree T)
{
    stack1 s;
    s.top = -1; //��ʼ��һ��ջs
    BiTNode *p = T;
    while (p || !isEmpty(s)) //ջ���ջ�p����ʱѭ��
    {
        if (p)
        {
            push(s, p);    //��ǰ�ڵ���ջ
            p = p->lchild; //�ߵ������
        }
        else //��ջ����ת���ջ����������
        {
            pop(s, p);              //ջ������ջ
            cout << p->data << " "; //����
            p = p->rchild;          //���������ߣ�pָ��ǰ�����Һ���
        }
    } //�����Ը�����������ѭ������
}       

//����ǵݹ�
void preOrder(BiTree T)
{
    stack1 s;
    s.top = -1; //��ʼ��һ��ջs
    BiTNode *p = T;
    while (p || !isEmpty(s))
    {
        if (p) //�ߵ������
        {
            cout << p->data << " "; //�ȷ��ʵ�ǰ�ڵ�
            push(s, p);             //�ٽ���ǰ�ڵ���ջ
            p = p->lchild;          //���Ӳ��գ�һֱ������
        }
        else //��ջ����ת���ջ����������
        {
            pop(s, p);     //ջ������ջ
            p = p->rchild; //���������ߣ�pָ��ǰ�����Һ���
        }
    } //�����Ը�����������ѭ������
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "���������";
    preOrder(T);
    cout << endl;
    cout << "���������";
    inOrder(T);
    cout << endl;
    cout << "���������";
    postOrder(T);
    cout << endl;
    return 0;
}