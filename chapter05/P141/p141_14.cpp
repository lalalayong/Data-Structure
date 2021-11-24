/* 
    设计一个算法：求非空二叉树的宽度。
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
void disp(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        disp(T->lchild);
        disp(T->rchild);
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
void display(quene q)
{
    for (int i = 0; i < Maxsize; i++)
    {
        cout << q.data[q.f] << " ";
        q.f = (q.f + 1) % Maxsize;
    }
    cout << endl;
}

int BTWidth(BiTree T)
{
    BiTNode *p;
    quene q;
    InitQuene(q);
    enQuene(q, T);
    int last = q.r;      //last标识队列中每层的分界线
    int L = 0, maxL = 1; //L记录每层宽度，maxL记录最大宽度
    while (!isEmpty(q))  //层次遍历
    {
        deQuene(q, p);
        if (p->lchild)
        {
            L++; //宽度+1
            enQuene(q, p->lchild);
        }
        if (p->rchild)
        {
            L++;
            enQuene(q, p->rchild);
        }
        if (q.f == last) //到达每层最后一个结点
        {
            last = q.r;   //last指向下一层最后一个结点
            if (L > maxL) //更新最大宽度
            {
                maxL = L;
            }
            L = 0; //重置L，准备下一层计数
        }
    }
    return maxL;
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "二叉树：";
    disp(T);
    cout << endl;
    int ans = BTWidth(T);
    cout << "该二叉树的宽度为：" << ans << endl;
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
