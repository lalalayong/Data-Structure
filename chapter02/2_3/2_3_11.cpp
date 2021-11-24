/* 
    设线性表C={a1,b1,a2,b2,...,an,bn}采用带头结点的单链表存放，设计一个就地算法，将其拆分为两个线性表，A={a1,a2,...,an},B={b1,b2,...,bn}
    算法思想：奇数结点用尾插法接到表A，偶数结点用头插法接到表B，即可实现题目要求。
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

LinkList disCreat_A_B(LinkList &A)
{
    LNode *p = A->next,*q; //p为工作指针，q防止断链
    LNode *ra=A; //ra指向A表的尾部
    LinkList B=(LinkList)malloc(sizeof(LNode));
    B->next=NULL;
    while(p){
        ra->next=p; //当前结点接到表A
        ra=p;
        p=p->next; //下一结点接到表B（头插法）
        if(p){
            q=p->next; //头插法时用q保存p的下一结点，防止断链
            p->next=B->next;
            B->next=p;
            p=q;
        }
    }
    ra->next=NULL;
    return B;
}

int main()
{
    int n = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    LNode *A = (LNode *)malloc(sizeof(LNode));
    buildList(A, a, n);
    cout << "原链表A：";
    display(A);
    LNode *B=disCreat_A_B(A);
    cout << "分解后的A表：";
    display(A);
    cout << "分解后的B表：";
    display(B);
    return 0;
}