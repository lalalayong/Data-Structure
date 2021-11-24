/* 
    ���������������н�������������
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
void disp(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        disp(T->lchild);
        disp(T->rchild);
    }
}

void swap(BiTree T)
{
    if (T) //TΪ��ʱ�ݹ����������
    {
        swap(T->lchild);           //�ݹ齻��T��������
        swap(T->rchild);           //�ݹ齻��T��������
        BiTNode *temp = T->lchild; //����T�����Һ���
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "����ǰ�Ķ�����:";
    disp(T);
    cout << endl;
    swap(T);
    cout << "������Ķ�����:";
    disp(T);
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