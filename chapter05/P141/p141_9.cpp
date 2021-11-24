/* 
    交换二叉树中所有结点的左右子树。
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
    if (T) //T为空时递归结束，返回
    {
        swap(T->lchild);           //递归交换T的左子树
        swap(T->rchild);           //递归交换T的右子树
        BiTNode *temp = T->lchild; //交换T的左右孩子
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "交换前的二叉树:";
    disp(T);
    cout << endl;
    swap(T);
    cout << "交换后的二叉树:";
    disp(T);
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