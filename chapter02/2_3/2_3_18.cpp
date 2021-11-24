/* 
    有两个循环单链表，头指针分别为h1和h2，编写一个函数将链表h2链接到h1之后，使新链表仍保持循环链表形式。
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

LinkList Link_L1_L2(LinkList &h1, LinkList &h2)
{
    LNode *p1 = h1, *p2 = h2;
    while (p1->next != h1) //分别找到L1和L2的尾结点
        p1 = p1->next;
    while (p2->next != h2)
        p2 = p2->next;
    p1->next = h2->next; //将L1的尾结点链接到L2的头结点，
    p2->next = h1; //将L2的尾结点链接到L1的头结点，形成新的循环单链表
    return h1;
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int b[4] = {7, 8, 9, 10};
    LNode *L1 = (LNode *)malloc(sizeof(LNode));
    LNode *L2 = (LNode *)malloc(sizeof(LNode));
    buildList(L1, a, n1);
    buildList(L2, b, n2);
    cout << "原循环单链表L1：";
    display(L1);
    cout << "原循环单链表L2：";
    display(L1);
    LinkList L = Link_L1_L2(L1, L2);
    cout << "链接后的循环单链表：";
    display(L);
    return 0;
}