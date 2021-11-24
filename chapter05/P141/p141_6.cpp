/* 
    根据先序和中序序列构造一颗二叉树。
 */
#include <iostream>
using namespace std;
#define Maxsize 50

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int pos = 0;
BiTree build(char A[], char B[], int s, int e)
{
    if (s <= e)
    {
        BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
        root->data = A[pos]; //建立根节点
        int i;
        for (i = s; B[i] != root->data; i++) //找到根节点在中序序列中的位置
            ;
        pos++;                                //全局变量，指向下一颗子树的根节点，
        root->lchild = build(A, B, s, i - 1); //递归建立左子树
        root->rchild = build(A, B, i + 1, e); //递归建立右子树
        return root;                          //返回根节点
    }
    return NULL; //到叶结点时开始返回
}

void disp(BiTree T)
{
    if (T)
    {
        disp(T->lchild);
        disp(T->rchild);
        cout << T->data << " ";
    }
}
int main()
{
    int n = 6;
    char A[6] = {'A', 'B', 'D', 'E', 'C', 'F'}; //先序序列
    char B[6] = {'D', 'B', 'E', 'A', 'F', 'C'}; //中序序列
    BiTree T = build(A, B, 0, n - 1);
    cout << "后序序列为：";
    disp(T);
    return 0;
}