/* 
    �жϸ����������Ƿ�Ϊ��ȫ��������
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

typedef struct
{
    elemtype data[Maxsize];
    int f, r, tag;
} quene;

void InitQuene(quene &p)
{
    p.f = p.r = p.tag = 0;
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

bool isComplete(BiTree T)
{
    quene Q;
    BiTNode *p;
    InitQuene(Q);
    if (!T)
        return true; //����Ϊ��������
    enQuene(Q, T);
    while (!isEmpty(Q))
    {
        deQuene(Q, p);
        if (p) //���ǿս��������������
        {
            enQuene(Q, p->lchild);
            enQuene(Q, p->rchild);
        }
        else //�����սڵ㣬���������Ƿ��зǿսڵ�
        {
            if (!isEmpty(Q))
            {
                deQuene(Q, p);
                if (p) //���ǿգ�������������
                    return false;
            }
        }
    }
    return true; //ȫ��������ɣ�����������
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    if (isComplete(T))
        cout << "��һ����ȫ��������" << endl;
    else
        cout << "����һ����ȫ��������" << endl;

    return 0;
}
//ABD##E##C#G##
/* 
                A
              /   \
            B       C
          /  \        \
         D    E        G
 */

//ABD##E##CF##G##
/* 
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */