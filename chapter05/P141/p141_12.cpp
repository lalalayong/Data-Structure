/* 
    在二叉树中查找值为x的结点，编写算法：打印值为x的结点的所有祖先。假设值为x的结点不多于1个。
    算法思想：采用后序非递归遍历算法，栈中保存的结点便是当前节点的所有祖先结点。当遍历到值为x的结点时，依次输出栈中结点的值，即为所有祖先的值。
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

void Search(BiTree T, char x)
{
    BiTNode *p = T;
    stack1 s;
    InitStack(s);
    while (p || !isEmpty(s)) //改造的后序非递归算法
    {
        if (p) //当结点不为空时
        {
            if (p->data == x) //如果结点值为x，依次输出栈内其祖先结点的值
            {
                cout << "所查结点的所有祖先结点的值为：" << endl;
                for (int i = s.top; i >= 0; i--)
                    cout << s.data[i]->data << " ";
                cout << endl;
                exit(0);
            }
            push(s, p);    //入栈
            p = p->lchild; //一直向左走
        }
        else //当结点为空的情况
        {
            p = s.data[s.top]; //判断栈顶结点的右孩子，若右孩子存在，转向右
            if (p->rchild && p->rchild->tag == 0)
                p = p->rchild;
            else //否则，出栈并访问
            {
                pop(s, p);
                p->tag = 1;
                p = NULL; //p置为空
            }
        }
    }
    cout << "不存在值为" << x << "的结点！" << endl;
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    cout << "二叉树：";
    disp(T);
    cout << endl;
    char x;
    cout << "请输入要查找的结点的值:";
    cin >> x;
    Search(T, x);
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
