/* 
    编写一个算法：对于二叉树中每一个值为x的结点，删除以它为根的子树，并释放相应空间。
 */
#include <iostream>
using namespace std;

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

void deleteXTree(BiTree &T) //递归删除以T为根的子树
{
    if (T)
    {
        deleteXTree(T->lchild); //删除T的左子树
        deleteXTree(T->rchild); //删除T的右子树
        free(T);                //释放T的空间
    }
}
//在二叉树上递归寻找所有以x为元素值的结点，并删除以其为根的子树
void searchDeleteX(BiTree T, char x)
{
    if (T)
    {
        if (T->data == x) //若根节点为x，则删除整个树
        {
            deleteXTree(T);
            exit(0); //退出
        }
        if (T->lchild && T->lchild->data == x) //若T的左孩子存在，且结点值为x
        {
            deleteXTree(T->lchild); //删除以T的左孩子为根的子树
            T->lchild = NULL;       //T的左孩子置空
        }
        else //否则，递归地在T的左子树中寻找
        {
            searchDeleteX(T->lchild, x);
        }
        if (T->rchild && T->rchild->data == x) //若T的右孩子存在，且结点值为x
        {
            deleteXTree(T->rchild); //删除以T的右孩子为根的子树
            T->rchild = NULL;       //T的右孩子置空
        }
        else //否则，递归地在T的右子树中寻找
        {
            searchDeleteX(T->rchild, x);
        }
    }
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "删除前的二叉树：";
    disp(T);
    cout << endl;
    char x;
    cout << "请输入要删除结点的值:";
    cin >> x;
    searchDeleteX(T, x);
    cout << "删除后的二叉树：";
    disp(T);
    cout << endl;

    return 0;
}
/* 
ABD##E##BF##G##
                A
              /   \
            B       B
          /  \     /  \
         D    E   F    G
 */