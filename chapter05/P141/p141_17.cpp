/* 
    ����㷨�ж����Ŷ������Ƿ����ƣ�
    �������������ƣ�ָ�������Ŷ��������ǿ�����ֻ��һ�����ڵ㣬����T1����������T2�����������ƣ�����T1����������T2��������Ҳ���ơ�
 */
#include <iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
//��ʾ������
void display(LinkList L)
{
    LNode *s = L->next;
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

//�ݹ齨��������������
void creatBiTree(BiTree &t)
{
    char ch;
    ch = getchar();
    if (ch == '\n')
    {
        ch = getchar();
    }
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

bool similar(BiTree T1, BiTree T2)
{
    if (T1 == NULL && T2 == NULL) //�����Կգ���������
        return true;
    else if (T1 == NULL || T2 == NULL) //����һ�����ǿգ����ز�����
        return false;
    else //�ݹ��ж�
        return similar(T1->lchild, T2->lchild) && similar(T1->rchild, T2->rchild);
}

int main()
{
    BiTree T1 = NULL, T2 = NULL;
    cout << "�������һ�Ŷ�����������:";
    creatBiTree(T1);
    cout << "������T1��";
    disp(T1);
    cout << endl;
    cout << "������ڶ��Ŷ�����������:";
    creatBiTree(T2);
    cout << "������T2��";
    disp(T2);
    cout << endl;
    if (similar(T1, T2))
        cout << "���ƣ�" << endl;
    else
        cout << "�����ƣ�" << endl;

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