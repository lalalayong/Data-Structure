/* 
    设计一个算法，判断一个链表是否有环，如果有，找出环的入口点并返回，否则返回NULL.
    算法思想：1.设置快慢指针同时后移，找到相遇点（若有环），
            2.再设置两个指针（一个从第一个结点、一个从相遇点）同步走，一次走一步，
            3.当这两个指针再次相遇时即为环的入口点
 */

/* 
    删除带头结点的单链表L中所有值为x的结点。并释放其空间，假设值为x的结点不唯一。
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
    r->next = L->next->next->next->next; //手动设置环，从4开始4,5,6为环
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

LNode *findLoopStart(LinkList L)
{
    LNode *slow = L->next, *fast = L->next; //设置快慢指针
    while (slow && fast->next)
    {
        slow = slow->next;       //每次走一步
        fast = fast->next->next; //每次走两步
        if (slow == fast)        //相遇
            break;
    }
    if (slow == NULL || fast->next == NULL)
        return NULL;               //没有环，返回NULL
    LNode *p = L->next, *q = slow; //分别指向开始点和相遇点
    while (p != q)                 //同步走，直到再次相遇，即为环的入口点
    {
        p = p->next;
        q = q->next;
    }
    return p; //返回入口点
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    LNode *p = findLoopStart(L);
    if (p)
    {
        cout << "环的入口点为" << p->data << endl;
    }
    else
    {
        cout << "此链表无环！" << endl;
    }
    return 0;
}