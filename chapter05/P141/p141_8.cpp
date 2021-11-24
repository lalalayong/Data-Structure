/* 
    ����һ�Ŷ�������˫��֧�ڵ�ĸ�����
 */
#include <iostream>
using namespace std;
#define Maxsize 50

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

//����һ�Ŷ�������˫��֧�ڵ�ĸ���(�ݹ�)
int doubleSonNodes(BiTree T)
{
    if (!T)
        return 0;                    //��������0
    else if (T->lchild && T->rchild) //˫��֧�ڵ㣬�ݹ��������������˫��֧�ڵ��������+1
        return doubleSonNodes(T->lchild) + doubleSonNodes(T->rchild) + 1;
    else //��˫��֧��㣬�ݹ��������������˫��֧�ڵ����
        return doubleSonNodes(T->lchild) + doubleSonNodes(T->rchild);
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    int num = doubleSonNodes(T);
    cout << "˫��֧�ڵ�ĸ���Ϊ��" << num << endl;
    return 0;
}

//��������
/* 
ABD##E##C#G##
                A
              /   \
            B       C
          /  \        \
         D    E        G
 */

/* 
ABD##E##CF##G##
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */