/* 
    设一个带头结点的单链表中所欲元素结点的值无序，编写一个函数，删除所有介于给定值（作为函数参数给出）之间的元素。
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

void rangeDelete(LinkList &L, int s, int t)
{
    LNode *p = L, *q;
    while (p->next)
    {
        if (p->next->data >= s && p->next->data <= t)
        {
            q = p->next;
            p->next = p->next->next; 
            free(q);
        }
        else //只有不满足条件时p才指向下一结点
        {
            p = p->next;
        }
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "原链表：";
    display(L);
    int s, t;
    cout << "请输入要删除元素的范围：";
    cin >> s >> t;
    rangeDelete(L, s, t);
    cout << "删除后的单链表：";
    display(L);
    return 0;
}