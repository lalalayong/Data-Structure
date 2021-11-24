/* 
    设计算法判断两颗二叉树是否相似：
    两个二叉树相似，指的是两颗二叉树都是空树或都只有一个根节点，或者T1的左子树和T2的左子树相似，并且T1的右子树和T2的右子树也相似。
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
//显示单链表
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

//递归建立二叉树（先序）
void creatBiTree(BiTree &t)
{
    char ch;
    ch = getchar();
    if (ch == '\n')
    {
        ch = getchar();
    }
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

bool similar(BiTree T1, BiTree T2)
{
    if (T1 == NULL && T2 == NULL) //两树皆空，返回相似
        return true;
    else if (T1 == NULL || T2 == NULL) //其中一棵树非空，返回不相似
        return false;
    else //递归判断
        return similar(T1->lchild, T2->lchild) && similar(T1->rchild, T2->rchild);
}

int main()
{
    BiTree T1 = NULL, T2 = NULL;
    cout << "请输入第一颗二叉树（先序）:";
    creatBiTree(T1);
    cout << "二叉树T1：";
    disp(T1);
    cout << endl;
    cout << "请输入第二颗二叉树（先序）:";
    creatBiTree(T2);
    cout << "二叉树T2：";
    disp(T2);
    cout << endl;
    if (similar(T1, T2))
        cout << "相似！" << endl;
    else
        cout << "不相似！" << endl;

    return 0;
}
//测试用例
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