/* 
    给定两个单链表，编写算法找到两个链表的公共结点（从某一结点开始他们的next都指向一个结点）
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//尾插法建立有公共结点的单链表(从数组)
void buildList(LinkList L1, LinkList L2, int A[], int B[], int n1, int n2)
{
    //带头节点  
    LNode *s1, *r1 = L1;
    LNode *s2, *r2 = L2;
    int dist = n1 - n2;
    for (int i = 0; i < dist + 1; i++)
    {
        s1 = (LNode *)malloc(sizeof(LNode));
        s1->data = A[i];
        r1->next = s1;
        r1 = s1;
    }
    for (int i = 0; i < 1; i++)
    {
        s2 = (LNode *)malloc(sizeof(LNode));
        s2->data = B[i];
        r2->next = s2;
        r2 = s2;
    }
    for (int i = dist + 1; i < n1; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = A[i];
        r1->next = r2->next = s;
        r1 = r2 = s;
    }
    r1->next = r2->next = NULL;
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

int Length(LinkList L)
{
    int k = 0;
    LNode *s = L->next;
    while (s)
    {
        k++;
        s = s->next;
    }
    return k;
}

LNode *Search_1st_Common(LinkList L1, LinkList L2)
{
    int len1 = Length(L1); //计算两个表的表长
    int len2 = Length(L2);
    int dist; //表长之差
    LinkList longlist, shortlist; //分别指向表长较长和较短的链表
    if (len1 > len2) //L1表长较长
    {
        longlist = L1->next;
        shortlist = L2->next;
        dist = len1 - len2; //表长之差
    }
    else  //L2表长较长
    {
        longlist = L2->next;
        shortlist = L1->next;
        dist = len2 - len1;
    }
    while (dist--)  //表长的链表先遍历到第dist个，然后两表同步走
        longlist = longlist->next;
    while (longlist)  //同步寻找公共结点
    {
        if (longlist == shortlist) //找到则返回结点指针
            return longlist;
        else
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    return NULL; //遍历结束，没有公共结点
}

int main()
{
    int n1 = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int B[4] = {7, 4, 5, 6};
    LNode *L1 = (LNode *)malloc(sizeof(LNode));
    LNode *L2 = (LNode *)malloc(sizeof(LNode));
    buildList(L1, L2, A, B, n1, n2);
    cout << "原链表L1：";
    display(L1);
    cout << "原链表L2：";
    display(L2);
    LNode *C = Search_1st_Common(L1, L2);
    cout << "公共结点为：" << C->data << endl;
    ;
    return 0;
}