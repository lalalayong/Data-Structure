/* 
    设ROOT为二叉树根节点指针，p，q为指向任意两个结点的指针，试编写算法Ancestor(ROOT,p,q,r)，找到p和q的最近公共祖先结点r。
    算法思想:采用后序非递归遍历算法，当访问到某结点时，战中所有元素为该结点的祖先。当访问到p或q时，将栈复制到另一辅助栈，并且继续遍历，等遍历到p或q中另一个结点时，
将当前栈中的结点与辅助栈中结点去匹配，第一个匹配的元素就是p、q的最近公共祖先结点。
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
void disp(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        disp(T->lchild);
        disp(T->rchild);
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

BiTNode *Ancestor(BiTree ROOT, BiTNode *p, BiTNode *q)
{
    int flag;
    BiTNode *t = ROOT;
    stack1 s, s1;
    InitStack(s);
    InitStack(s1);
    while (t || !isEmpty(s)) //改造的后序非递归算法
    {
        if (t) //若结点存在，则一直向左走
        {
            if (t == p || t == q) //若结点为p或q
            {
                //flag用来记录是否已经遇到过p或q（p、q位置不确定，有可能先遇到p或者先遇到q）
                if (flag == 0) //第一次遇到p或q，则将s栈内元素复制到辅助栈s1
                {
                    s1.top = s.top;
                    for (int i = s.top; i >= 0; i--)
                        s1.data[i] = s.data[i];
                    flag = 1; //置flag为1
                }
                else //若遇到p或q中的另外一个，直接将栈s内元素与辅助栈s1内元素进行比较，
                {
                    for (int i = s.top; i >= 0; i--)
                        for (int j = s1.top; j >= 0; j--)
                            if (s1.data[j] == s.data[i])
                                return s.data[i]; //第一个相同的结点即为pq最近公共祖先结点
                }
            }

            push(s, t);    //入栈
            t = t->lchild; //向左走
        }
        else
        {
            t = s.data[s.top];
            if (t->rchild && t->rchild->tag == 0)
                t = t->rchild;
            else
            {
                pop(s, t);
                t->tag = 1;
                t = NULL;
            }
        }
    }
    return NULL;
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "二叉树：";
    disp(T);
    cout << endl;
    BiTNode *p = T->rchild, *q = T->lchild->rchild, *r; //设置p,q
    r = Ancestor(T, p, q);
    cout << p->data << "和" << q->data << "的最近公共祖先结点为：" << r->data << endl;
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
