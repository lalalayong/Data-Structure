/* 
    在基于单链表表示的待排序关键字序列上进行简单选择排序
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
int n = 8;

void buildList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    LNode *r = L, *s;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = A[i];
        r->next = s;
        r = r->next;
    }
    r->next=NULL;
}
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

void SelectSort(LinkList &L)
{
    LNode *h = L->next, *r, *s, *p, *q;
    L->next = NULL;
    while (h) //持续扫描原链表
    {
        p = s = h;
        q = r = NULL;
        //s和r记录最大结点和其前驱，p为工作指针，q为其前驱
        while (p) //扫描原链表寻找最大结点s
        {
            if (p->data > s->data)
            { //找到更大的，记录它和它的前驱
                s = p;
                r = q;
            }
            q = p; //继续寻找
            p = p->next;
        }
        if (s == h)
            h = h->next;  //最大结点在原链表前端，将其摘下
        else
            r->next = s->next; //最大结点在原链表表内，将其摘下

        s->next = L->next; //将最大结点s插入结果链前端
        L->next = s;
    }
}

int main()
{
    LinkList L;
    buildList(L);
    cout << "排序前的单链表：";
    display(L);
    SelectSort(L);
    cout <<"排序后的单链表：";
    display(L);
    return 0;
}