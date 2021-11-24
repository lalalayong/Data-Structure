/* 
    写出中序线索二叉树里查找指定结点在后序的前驱结点的算法。
 */
#include <iostream>
using namespace std;
#define elemtype int

typedef struct ThreadNode
{
    elemtype data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //tag=0表示左右孩子，tag=1表示前驱或后继
} ThreadNode, *ThreadTree;

//递归建立二叉树（先序）
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

//通过中序遍历建立中序线索二叉树
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