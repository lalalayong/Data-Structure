/* 
    有一个带头结点的单链表，设计一个算法使其元素递增有序。
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

void Sort(LinkList &L){
    LNode *pre;     //pre用来记录p的待插入位置的前驱
    LNode *p=L->next,*r=p->next;   //p为工作指针，r指向p后继，防止断链
    L->next=NULL; //将L的next置为空
    p->next=L->next; //处理第一个结点，将其插入结果表（头插法）
    L->next=p;
    p=r;
    while(p){
        r=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)  //找到待插入的位置，记录其前驱
            pre=pre->next;
        p->next=pre->next; //头插法插入
        pre->next=p;
        p=r; //继续扫描原单链表中剩下的结点
    }
}

int main()
{
    int n = 6;
    int A[6] = {8, 2, 3, 4, 5, 1};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "原链表：";
    display(L);
    Sort(L);
    cout << "递增排序后的单链表：";
    display(L);
    return 0;
}