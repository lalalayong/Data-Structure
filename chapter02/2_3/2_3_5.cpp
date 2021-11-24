/* 
    就地逆置带头结点的单链表（头插法）
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

//头插法逆置单链表
void reverse(LinkList &L){
    LNode *p,*r; //p为工作指针，r为p的后继，防止断链
    p=L->next; //p指向第一个元素结点
    L->next=NULL; //将头结点next置为NULL
    while(p){
        r=p->next; //记录p的后继
        p->next=L->next; //头插法
        L->next=p;
        p=r; //p后移
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
    reverse(L);
    cout << "逆置后的单链表：";
    display(L);
    return 0;
}