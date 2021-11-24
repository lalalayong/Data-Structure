/* 
    给定一个带头结点的单链表，设head为头指针，试编写算法：按递增次序输出单链表中的各结点的数据，并释放结点所占的存储空间。
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

void min_Delete(LinkList &head)
{
    while (head->next)
    {
        LNode *p = head, *q=head; //p是工作指针，q记录最小值结点的前驱，每次从单链表的头开始
        int min = p->next->data;
        while (p->next) //每次判断p的下一结点
        {
            if (p->next->data <min)
            {
                q = p; //小于当前最小值，记录该结点并更新min
                min=p->next->data; 
            }
            p=p->next; //p后移
        }
        cout<<q->next->data<<" "; //输出最小值结点元素
        p=q->next; //暂存最小值结点
        q->next=q->next->next; //将最小值结点从单链表中删除
        free(p); //释放空间
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 9, 5, 4, 1};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "原链表：";
    display(L);
    cout << "按递增次序输出单链表元素：";
    min_Delete(L);
    return 0;
}