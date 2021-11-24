/* 
    设计一个递归算法，删除不带头结点的单链表L中所有值为x的元素。
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

int n = 4;
int A[4] = {1, 2, 3, 4};
void buildList(LinkList L)
{ //不带头节点
    LNode *s, *r = L;
    r->data = A[0];
    if (n == 1)
        r->next = NULL;
    else
    {
        for (int i = 1; i < n; i++)
        {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = A[i];
            r->next = s;
            r = s;
        }
    }
    r->next = NULL;
}

void display(LinkList L)
{
    LNode *s = L;
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

void deletex(LinkList &L, int x)
{
    LNode *p;
    if (L == NULL) //递归出口
        return;
    if (L->data == x) 
    {
        p = L;  //若L所指的结点的值为x
        L = L->next; //删除L,并让L指向下一结点
        free(p);
        deletex(L, x); //递归调用
    }
    else //若L所指的结点的值不为x
    {
        deletex(L->next, x); //递归调用
    }
}
int main()
{
    // LNode *L=new LNode(); //用new申请的内存要使用delete来释放内存
    LNode *L=(LNode *)malloc(sizeof(LNode)); //malloc对应free
    buildList(L);
    display(L);
    int x;
    cout << "请输入要删除的元素：";
    cin >> x;
    deletex(L, x);
    display(L);
    return 0;
}