/* 
    设A,B是两个带头结点的单链表，其中元素递增有序，设计一个算法从A,B中的公共元素产生单链表C，要求不破坏A,B的结点。
    算法思想：表A,B都有序，可从第一个元素起依次比较AB两表的元素，若元素值不相同则较小的指针向后移，若元素值相同，则创建一个值相同的结点插入（尾插法）
到新的链表C中。然后两个指针同时后移，直到一个链表到达尾部。
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

LinkList getCommon(LinkList A, LinkList B)
{
    LNode *pa = A->next, *pb = B->next;
    LNode *C = (LNode *)malloc(sizeof(LNode)); //建立表C
    LNode *r = C; //r始终指向表C的尾结点
    while (pa && pb) //有一个链表到达尾部则推出循环
    {
        if (pa->data == pb->data) //找到公共结点，建立新结点链到表C尾部
        {
            LNode *s = (LNode *)malloc(sizeof(LNode));
            s->data = pa->data; 
            r->next = s; //尾插法
            r = s;
            pa = pa->next; //表A和表B继续向后扫描
            pb = pb->next;
        }
        else if (pa->data < pb->data) //元素小的指针后移
        {
            pa = pa->next;
        }
        else
        {
            pb = pb->next;
        }
    }
    r->next=NULL; //注意：尾插法要将最后一个结点的next置空
    return C;
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
    LNode *C = getCommon(A, B);
    cout << "AB公共元素单链表C：";
    display(C);
    return 0;
}