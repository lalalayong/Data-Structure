/* 
    设A,B是两个带头结点的单链表，其中元素递增有序，求AB的交集并存放于链表A中。
    算法思想：表A,B都有序，可从第一个元素起依次比较AB两表的元素，若元素值相同，则保留一个链接到结果表，其他的结点全部释放，当一个链表全部遍历完成后，
释放另一个链表中的全部剩余结点。
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

LinkList Union_A_B(LinkList &A, LinkList &B)
{
    LNode *pa = A->next, *pb = B->next;
    LNode *pc = A; //用A当做结果表
    LNode *u;
    while (pa && pb) //有一个链表到达尾部则推出循环
    {
        if (pa->data == pb->data) //找到公共结点
        {
            pc->next = pa; //选择一个链到结果表尾部
            pc = pa;
            pa=pa->next; //pa后移
            u = pb; //释放另一个结点
            pb = pb->next;
            free(u);
        }
        else if (pa->data < pb->data) //元素小的指针后移,并释放结点
        {
            u = pa;
            pa = pa->next;
            free(u);
        }
        else
        {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    //将剩余表结点释放
    while (pa)
    {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb)
    {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL; //注意：尾插法要将最后一个结点的next置空
    free(B); //释放表B头结点
    return A; //返回结果表
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
    LNode *C = Union_A_B(A, B);
    cout << "链表A,B的交集：";
    display(C);
    return 0;
}