/* 
    设带头结点的单链表{a1,a2,a3,...,an-2.an-1,an},设计一个空间复杂度为O(1)，时间上尽可能高效的算法，重新排列单链表各结点为{a1,an,a2,an-1,a3,an-2,...}.
    算法思想：从前边取一个，从后边取一个，由于是单链表，要想从后边倒着取结点，首先将链表后一半逆置，（利用快慢指针找到中间节点）
            然后一个指针指向第一个结点，一个指针指向逆置后的后半部分第一个结点，
            然后依次取下结点，插入指定位置，
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

void change_list(LinkList &L)
{
    LNode *slow, *fast;
    LNode *p, *q, *r, *s;
    slow = fast = L;
    while (fast->next) //找到中间结点
    {
        slow = slow->next; //慢指针走一步
        fast = fast->next;
        if (fast->next) //快指针走两步（如果next存在）
            fast = fast->next;
    }
    p = slow;       //p为中间结点
    q = slow->next; //q为后半段链表的首结点
    p->next = NULL; //将p->next置为空
    while (q)       //将后半段链表逆置（头插法）
    {
        r = q->next; //记录q的后继，防止断链
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next; //s指向前半段第一个结点，即插入点
    q = p->next; //q指向后半段第一个结点
    p->next = NULL;
    while (q) //将链表后半段的结点插入到指定位置
    {
        r = q->next;       //r指向后半段的下一个插入点
        q->next = s->next; //将q指向的结点插入到s之后
        s->next = q;
        s = q->next; //s指向前半段的下一个插入点
        q = r;
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    change_list(L);
    cout << "重排后的单链表：" << endl;
    display(L);
    return 0;
}