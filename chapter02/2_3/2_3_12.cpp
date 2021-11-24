/* 
    在一个递增有序的单链表中有数值相同的元素，设计一个算法去掉数值相同的元素。如{7,10,10,21,30,42,42,42,51,70}变成{7,10,21,30,42,51,70}
    算法思想：用p扫描单链表，若p结点值等于其后继结点的值则删除其后继结点，否则p后移，继续扫描。
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//尾插法建立单链表(从数组)
void buildList(LinkList L, int A[], int n)
{
    //带头节点
    LNode *s, *r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = A[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

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

void Del_Same(LinkList &L)
{
    LNode *p = L->next, *q;
    if (!p)
        return;
    while (p->next)
    {
        if (p->data == p->next->data)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}

int main()
{
    int n = 10;
    int A[10] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "原链表：";
    display(L);
    Del_Same(L);
    cout << "去掉重复元素后的单链表：";
    display(L);
    return 0;
}