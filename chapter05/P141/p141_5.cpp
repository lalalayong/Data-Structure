/* 
    设计一个非递归算法求二叉树的高度。
 */
#include <iostream>
using namespace std;
#define Maxsize 50

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

//非递归求二叉树高度
int BTdepth(BiTree T)
{
    if (!T) 
        return 0; //树空，高度为0
    int front = -1, rear = -1;
    int last = 0; //last指向当前层的最右结点（每层的分界点）
    int level = 0;
    BiTree Q[Maxsize]; //设置队列Q
    Q[++rear] = T;     //根节点入队
    BiTree p;
    while (front < rear) //队列不为空，则循环
    {
        p = Q[++front]; //队头元素出队
        if (p->lchild)  //左孩子入队
            Q[++rear] = p->lchild;
        if (p->rchild) //右孩子入队
            Q[++rear] = p->rchild;
        if (front == last) //若到达了该层最后一个结点
        {
            level++;     //层数+1
            last = rear; //last指向下一层的最右节点
        }
    }
    return level;
}

//递归求二叉树高度
int BTdepth_1(BiTree T){
    if(!T)
        return 0;
    int ldepth=BTdepth_1(T->lchild);
    int rdepth=BTdepth_1(T->rchild);
    return ldepth>rdepth?ldepth+1:rdepth+1;
}

int main()
{
    BiTree T;
    cout << "请输入一颗二叉树（先序）:";
    creatBiTree(T);
    int depth = BTdepth_1(T);
    cout << "该二叉树的高度为：" << depth << endl;
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