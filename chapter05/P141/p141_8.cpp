/* 
    计算一颗二叉树中双分支节点的个数。
 */
#include <iostream>
using namespace std;
#define Maxsize 50

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//递归建立二叉树（先序）
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

//计算一颗二叉树中双分支节点的个数(递归)
int doubleSonNodes(BiTree T)
{
    if (!T)
        return 0;                    //空树返回0
    else if (T->lchild && T->rchild) //双分支节点，递归计算左右子树的双分支节点个数，再+1
        return doubleSonNodes(T->lchild) + doubleSonNodes(T->rchild) + 1;
    else //非双分支结点，递归计算左右子树的双分支节点个数
        return doubleSonNodes(T->lchild) + doubleSonNodes(T->rchild);
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    int num = doubleSonNodes(T);
    cout << "双分支节点的个数为：" << num << endl;
    return 0;
}

//测试用例
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