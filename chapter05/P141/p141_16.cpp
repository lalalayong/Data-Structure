/* 
    ���һ���㷨����������Ҷ������������һ����������ͷָ��Ϊhead������ʱ��Ҷ������ָ��������ŵ�����ָ�롣
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
void disp_Linked_Tree(BiTree T)
{
    while (T)
    {
        cout << T->data << " ";
        T = T->rchild;
    }
}

BiTNode *head, *r = NULL; //ȫ�ֱ���
void Inorder(BiTree T)
{

    if (T)
    {
        Inorder(T->lchild); //�������������
        Inorder(T->rchild);
        if (T->lchild == NULL && T->rchild == NULL) //Ҷ���
        {
            if (head == NULL) //�����һ��Ҷ���
            {
                head = T;
                r = T;
            }
            else //�������
            {
                r->rchild = T;
                r = T;
            }
        }
        r->rchild = NULL; //��������β
    }
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "��������";
    disp(T);
    cout << endl;
    Inorder(T);
    disp_Linked_Tree(head);
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