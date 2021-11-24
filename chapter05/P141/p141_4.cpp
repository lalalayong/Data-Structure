/* 
    反向层次遍历（从下至上，从右至左）
    思想：改造层次遍历算法，出队之后不访问，而改为入栈，最后依次出栈，即为反向层次遍历。
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

//----栈-----------------------------------------------------------------------------------------------------------------------
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
    x = s.data[s.top--]; //先去栈顶元素，再令栈顶指针-1
    return true;
}

//----队列----------------------------------------------------------------------------------------------------------------------
typedef struct
{
    elemtype data[Maxsize];
    int f, r, tag;
} quene;

void InitQuene(quene &q)
{
    q.f = q.r = q.tag = 0;
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

void InvertLevel(BiTree T)
{
    stack1 s;
    quene q;
    BiTNode *p;
    if (T)
    {
        InitQuene(q);
        InitStack(s);
        enQuene(q, T);
        while (!isEmpty(q)) //层次遍历
        {
            deQuene(q, p);
            push(s, p);//出队后入栈（层次遍历是出队后访问）
            if (p->lchild)
                enQuene(q, p->lchild); //有左孩子，入队
            if (p->rchild)
                enQuene(q, p->rchild);//有右孩子，入队
        }
        while (!isEmpty(s)) //栈中存放的是层次遍历序列
        {
            pop(s, p); //依次出栈，得到的便是反向层次遍历
            cout << p->data << " ";
        }
    }
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "反向层次遍历：";
    InvertLevel(T);
    return 0;
}
//ABD##E##CF##G##
/* 
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */