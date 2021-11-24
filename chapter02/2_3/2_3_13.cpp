/* 
    假设有两个单链表均按元素递增次序排列，设计一个算法，就地将两个单链表合成一个按元素递减次序排列的单链表。
    算法思想：两个递增链表各自从第一个结点开始比较，将较小的结点插入结果表中，由于题目要求结果链表以递减顺序排列，所以采用头插法，
比较结束后可能会有一个链表非空，此时直接将该链表的所有结点头插到结果表
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

void merge(LinkList &A, LinkList &B)
{//将AB两表合并到A表
    LNode *pa = A->next, *pb = B->next;
    LNode *r; //头插法时r用来记录下一结点，防止断链
    A->next = NULL; //头插法，将结果表置空
    while (pa && pb)
    {
        if (pa->data <= pb->data) //将值较小的结点插入结果表
        {
            r = pa->next; //r暂存pa的后继结点，防止断链
            pa->next = A->next; //头插法
            A->next = pa;
            pa = r;
        }
        else
        {
            r = pb->next;
            pb->next = A->next;
            A->next = pb;
            pb = r;
        }
    }
    //通常会有一个链表非空，直接将剩余元素插入结果表
    while (pa)
    {
        r = pa->next;
        pa->next = A->next;
        A->next = pa;
        pa = r;
    }
    while (pb)
    {
        r = pb->next;
        pb->next = A->next;
        A->next = pb;
        pb = r;
    }
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int b[4] = {1, 4, 7, 8};
    LNode *A = (LNode *)malloc(sizeof(LNode));
    LNode *B = (LNode *)malloc(sizeof(LNode));
    buildList(A, a, n1);
    buildList(B, b, n2);
    cout << "原链表A：";
    display(A);
    cout << "原链表B：";
    display(B);
    merge(A,B);
    cout << "合并后的单链表：";
    display(A);
    return 0;
}