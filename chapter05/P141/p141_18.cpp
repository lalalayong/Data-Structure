/* 
    д���������������������ָ������ں����ǰ�������㷨��
 */
#include <iostream>
using namespace std;
#define elemtype int

typedef struct ThreadNode
{
    elemtype data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //tag=0��ʾ���Һ��ӣ�tag=1��ʾǰ������
} ThreadNode, *ThreadTree;

//�ݹ齨��������������
void creatThreadTree(ThreadTree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (ThreadNode *)malloc(sizeof(ThreadNode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        creatThreadTree(t->lchild);
        creatThreadTree(t->rchild);
    }
}

void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p)
    {
        InThread(p->lchild, pre);
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(pre->rchild, pre);
    }
}

//ͨ���������������������������
void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T)

    {
        InThread(T, pre);
        pre->rchild = NUll;
        pre->rtag = 1;
    }
}