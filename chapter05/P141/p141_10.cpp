/* 
    求二叉树先序遍历序列中第k个结点的值。
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

static int i = 0;
static int a;
char findPre_K(BiTree T, int k)
{
    if (T)
    {
        if (++i == k)
        {
            a = T->data;
        }
        else
        {
            findPre_K(T->lchild, k);
            findPre_K(T->rchild, k);
        }
    }
    return a;
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "二叉树:";
    disp(T);
    cout << endl;
    int k;
    cout << "请输入要查找先序序列第几个值:";
    cin >> k;
    char ans = findPre_K(T, k);
    cout << "先序序列第" << k << "个值为：" << ans << endl;
    return 0;
}
/* 
ABD##E##CF##G##
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */