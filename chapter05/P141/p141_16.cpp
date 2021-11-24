/* 
    设计一个算法将二叉树的叶结点从左到右连成一个单链表，表头指针为head，链接时用叶结点的右指针域来存放单链表指针。
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
void disp_Linked_Tree(BiTree T)
{
    while (T)
    {
        cout << T->data << " ";
        T = T->rchild;
    }
}

BiTNode *head, *r = NULL; //全局变量
void Inorder(BiTree T)
{

    if (T)
    {
        Inorder(T->lchild); //后序遍历左子树
        Inorder(T->rchild);
        if (T->lchild == NULL && T->rchild == NULL) //叶结点
        {
            if (head == NULL) //处理第一个叶结点
            {
                head = T;
                r = T;
            }
            else //其他结点
            {
                r->rchild = T;
                r = T;
            }
        }
        r->rchild = NULL; //设置链表尾
    }
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "二叉树：";
    disp(T);
    cout << endl;
    Inorder(T);
    disp_Linked_Tree(head);
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