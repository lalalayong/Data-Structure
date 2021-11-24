/* 
    二叉树的先序、中序、后序非递归遍历。
 */
#include <iostream>
using namespace std;

#define Maxsize 50
#define elemtype BiTree

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
    int tag;
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
        t->tag = 0;
        t->lchild = NULL;
        t->rchild = NULL;
        creatBiTree(t->lchild);
        creatBiTree(t->rchild);
    }
}
//----栈------------------
typedef struct
{
    elemtype data[Maxsize];
    int top;
} stack1;

void InitStack(stack1 &s)
{
    s.top = -1;
}

bool isEmpty(stack1 s)
{
    if (s.top == -1)
        return true; //栈空
    else
        return false;
}

bool isFull(stack1 s)
{
    if (s.top == Maxsize - 1)
        return true;
    else
        return false;
}
bool push(stack1 &s, elemtype x)
{
    if (isFull(s))
    {
        cout << "栈满，入栈失败！" << endl;
        return false;
    }
    s.data[++s.top] = x; //栈顶指针先+1，再入栈
    return true;
}

bool pop(stack1 &s, elemtype &x)
{
    if (isEmpty(s))
    {
        cout << "栈空，出栈失败！" << endl;
        return false;
    }
    x = s.data[s.top--]; //先取栈顶元素，再令栈顶指针-1
    return true;
}

//后序非递归
void postOrder(BiTree T)
{
    stack1 s;
    s.top = -1; //初始化一个栈s
    BiTNode *p = T;
    while (p || !isEmpty(s))
    {
        if (p) //走到最左边
        {
            push(s, p);
            p = p->lchild;
        }
        else //向右
        {
            p = s.data[s.top];                    //读栈顶结点
            if (p->rchild && p->rchild->tag == 0) //若其右子树存在，且未被访问过
                p = p->rchild;                    //转向右
            else                                  //否则弹出结点并访问
            {
                pop(s, p);              //弹出栈顶结点
                cout << p->data << " "; //访问
                p->tag = 1;             //访问标记
                p = NULL;               //结点访问完后，重置p指针（每次通过栈顶结点判断下一个要访问）
            }
        }
    }
}

//中序非递归
void inOrder(BiTree T)
{
    stack1 s;
    s.top = -1; //初始化一个栈s
    BiTNode *p = T;
    while (p || !isEmpty(s)) //栈不空或p不空时循环
    {
        if (p)
        {
            push(s, p);    //当前节点入栈
            p = p->lchild; //走到最左边
        }
        else //出栈，并转向出栈结点的右子树
        {
            pop(s, p);              //栈顶结点出栈
            cout << p->data << " "; //访问
            p = p->rchild;          //向右子树走，p指向当前结点的右孩子
        }
    } //继续对该右子树进行循环遍历
}       

//先序非递归
void preOrder(BiTree T)
{
    stack1 s;
    s.top = -1; //初始化一个栈s
    BiTNode *p = T;
    while (p || !isEmpty(s))
    {
        if (p) //走到最左边
        {
            cout << p->data << " "; //先访问当前节点
            push(s, p);             //再将当前节点入栈
            p = p->lchild;          //左孩子不空，一直向左走
        }
        else //出栈，并转向出栈结点的右子树
        {
            pop(s, p);     //栈顶结点出栈
            p = p->rchild; //向右子树走，p指向当前结点的右孩子
        }
    } //继续对该右子树进行循环遍历
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "先序遍历：";
    preOrder(T);
    cout << endl;
    cout << "中序遍历：";
    inOrder(T);
    cout << endl;
    cout << "后序遍历：";
    postOrder(T);
    cout << endl;
    return 0;
}