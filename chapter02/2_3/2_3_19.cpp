/* 
    设一个带头结点的循环单链表，其结点值均为正整数，设计一个算法，反复找出单链表中结点值最小的节点并输出，然后将该结点从中删除，直到单链表为空，最后删除头结点。
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//尾插法建立循环单链表(从数组)
void buildList(LinkList L, int A[], int n)
{
    //带头节点
    LNode *s, *r = L;
    L->next = L;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = A[i];

        r->next = s;
        r = s;
    }
    r->next = L;
}

//显示循环单链表
void display(LinkList L)
{
    LNode *s = L->next;
    while (s != L)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

void Del_All(LinkList &L)
{
    while (L->next != L)
    {
        LNode *p = L->next, *minp = L->next, *q; //minp记录最小值结点的前驱，默认指向第一个元素，p为工作指针
        while (p->next != L)
        {
            if (p->next->data < minp->data)
            {
                minp = p;
            }
            p = p->next;
        }
        if (minp == L->next) //若一轮判断之后minp未变的情况（即第一个元素为最小值）
        {
            cout << minp->data << " ";
            L->next = minp->next;
            free(minp);
        }
        else
        {
            q = minp->next;
            cout << q->data << " ";
            minp->next = minp->next->next;
            free(q);
        }
    }
    free(L);
}
void Del_All_2(LinkList &L)
{
    while (L->next != L)
    {
        int min = INT_MAX;       //min记录最小值
        LNode *p = L, *minp, *q; //minp记录最小值结点的前驱，默认指向第一个元素，p为工作指针
        while (p->next != L)
        {
            if (p->next->data < min)
            {
                min = p->next->data;
                minp = p;
            }
            p = p->next;
        }
        q = minp->next;
        cout << q->data << " ";
        minp->next = minp->next->next;
        free(q);
    }
    free(L);
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, a, n1);
    cout << "循环单链表L：";
    display(L);
    Del_All(L);
    return 0;
}