/* 
    判断给定二叉树是否为完全二叉树。
 */
#include <iostream>
using namespace std;
#define Maxsize 50
#define elemtype BiTree

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

typedef struct
{
    elemtype data[Maxsize];
    int f, r, tag;
} quene;

void InitQuene(quene &p)
{
    p.f = p.r = p.tag = 0;
}

bool isEmpty(quene q)
{
    if (q.f == q.r && q.tag == 0)
        return true; //队空
    else
        return false;
}
bool isFull(quene q)
{
    if (q.f == q.r && q.tag == 1)
        return true; //队满
    else
        return false;
}

bool enQuene(quene &q, elemtype x)
{
    if (isFull(q))
    {
        cout << "队满，进队失败！" << endl;
        return false;
    }
    q.data[q.r] = x;
    q.r = (q.r + 1) % Maxsize;
    q.tag = 1;
    return true;
}
bool deQuene(quene &q, elemtype &x)
{
    if (isEmpty(q))
    {
        cout << "队空，出队失败！" << endl;
        return false;
    }
    x = q.data[q.f];
    q.f = (q.f + 1) % Maxsize;
    q.tag = 0;
    return true;
}

bool isComplete(BiTree T)
{
    quene Q;
    BiTNode *p;
    InitQuene(Q);
    if (!T)
        return true; //空树为满二叉树
    enQuene(Q, T);
    while (!isEmpty(Q))
    {
        deQuene(Q, p);
        if (p) //结点非空将其左右子树入队
        {
            enQuene(Q, p->lchild);
            enQuene(Q, p->rchild);
        }
        else //遇到空节点，检查队列中是否有非空节点
        {
            if (!isEmpty(Q))
            {
                deQuene(Q, p);
                if (p) //结点非空，则不是满二叉树
                    return false;
            }
        }
    }
    return true; //全部遍历完成，是满二叉树
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    if (isComplete(T))
        cout << "是一颗完全二叉树！" << endl;
    else
        cout << "不是一颗完全二叉树！" << endl;

    return 0;
}
//ABD##E##C#G##
/* 
                A
              /   \
            B       C
          /  \        \
         D    E        G
 */

//ABD##E##CF##G##
/* 
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */