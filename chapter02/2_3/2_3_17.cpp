/* 
    设计一个算法判断带头结点的循环双链表是否对称。
 */
#include <iostream>
using namespace std;

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//创建带头结点的循环双链表（从数组）
void buildList(DLinkList &L, int a[], int n)
{
    L = (DLinkList)malloc(sizeof(DNode));
    DNode *r = L; //r始终指向双链表最后一个结点
    L->next = L;
    L->prior = L;
    for (int i = 0; i < n; i++)
    {
        DNode *s = (DLinkList)malloc(sizeof(DNode));
        s->data = a[i];

        s->next = r->next; //循环双链表尾插法
        r->next->prior = s;
        s->prior = r;
        r->next = s;
        
        r = s; //r指向新的尾部结点
        L->prior = s; //L的前驱指向尾部结点
    }
}

//输出循环双链表
void display(DLinkList L)
{
    DNode *p = L->next;
    while (p != L)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool isSymmetry(DLinkList L)
{
    DNode *p = L->next;
    DNode *q = L->prior;
    while (p != q && q->next != p) //奇数时，p!=q停止循环，偶数时，q->next!=p时结束循环（此时p，q刚好互换位置，p跑到q的后继）
    {
        if (p->data == q->data) //数据相同，则同步走
        {
            p = p->next;
            q = q->prior;
        }
        else
        {
            return false;
        }
    }//while循环正常结束，表明是对称的
    return true;
}

int main()
{
    int n = 5;
    int a[5] = {1, 1, 3, 2, 1};
    DLinkList L;
    buildList(L,a,n);
    cout<<"循环双链表:";
    display(L);
    if (isSymmetry(L))
    {
        cout << "该循环双链表是对称的！！" << endl;
    }
    else
    {
        cout << "该循环双链表不是对称的！！" << endl;
    }
    return 0;
}