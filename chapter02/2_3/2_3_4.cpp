/* 
    删除带头结点的单链表中最小值结点。
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

void del_Min(LinkList &L)
{
    int min = L->next->data; //min记录最小值，默认指向第一个结点
    LNode *p = L->next, *q = L; //q指向待删除结点的前驱，p为工作指针
    while (p->next) //每次判断p的下一结点，省去了pre指针
    {
        if (p->next->data < min) 
        {
            min = p->next->data; //如果小于最小值，更新，并记录其前驱
            q = p;  
        }
        p = p->next;
    }
    LNode *f = q->next;
    q->next = q->next->next; //删除最小值结点
    free(f);
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "原链表：";
    display(L);
    del_Min(L);
    cout << "删除最小值结点后：";
    display(L);
    return 0;
}