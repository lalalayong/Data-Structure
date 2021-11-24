/* 
    设一个带头结点的单链表A分解成两个带头结点的单链表A和B，使得A表中含有原表中序号为奇数的元素，B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
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
    LNode *p = A->next; //p为工作指针，指向第一个结点
    A->next=NULL; //将A表置空
    LinkList B=(LinkList)malloc(sizeof(LNode));
    LNode *ra=A,*rb=B; //ra和rb分别指向A表和B表的尾部
    while(p){
        ra->next=p; //奇数结点接到表A
        ra=p;
        rb->next=p->next; //偶数结点接到表B
        rb=p->next;
        p=p->next->next; //p走两步，再次走到奇数结点进行下一轮循环
    }
    ra->next=NULL;
    rb->next=NULL;
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