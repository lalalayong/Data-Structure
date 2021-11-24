/* 
    ���һ���㷨����ǿն������Ŀ�ȡ�
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
void disp(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        disp(T->lchild);
        disp(T->rchild);
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
void display(quene q)
{
    for (int i = 0; i < Maxsize; i++)
    {
        cout << q.data[q.f] << " ";
        q.f = (q.f + 1) % Maxsize;
    }
    cout << endl;
}

int BTWidth(BiTree T)
{
    BiTNode *p;
    quene q;
    InitQuene(q);
    enQuene(q, T);
    int last = q.r;      //last��ʶ������ÿ��ķֽ���
    int L = 0, maxL = 1; //L��¼ÿ���ȣ�maxL��¼�����
    while (!isEmpty(q))  //��α���
    {
        deQuene(q, p);
        if (p->lchild)
        {
            L++; //���+1
            enQuene(q, p->lchild);
        }
        if (p->rchild)
        {
            L++;
            enQuene(q, p->rchild);
        }
        if (q.f == last) //����ÿ�����һ�����
        {
            last = q.r;   //lastָ����һ�����һ�����
            if (L > maxL) //���������
            {
                maxL = L;
            }
            L = 0; //����L��׼����һ�����
        }
    }
    return maxL;
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "��������";
    disp(T);
    cout << endl;
    int ans = BTWidth(T);
    cout << "�ö������Ŀ��Ϊ��" << ans << endl;
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
