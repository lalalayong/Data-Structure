/* 
    逆序输出带头结点的单链表的值。
    算法思想：1.头插法建立单链表，再遍历输出
            2.遍历单链表的每个节点，值入栈，最后出栈
            3.递归：先递归，再输出，便是逆序
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

void R_Print(LinkList L){
    if(L->next!=NULL)
        R_Print(L->next); //递归
    if(L!=NULL)
        cout<<L->data<<" "; //倒序输出
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout<<"原链表：";
    display(L);
    cout<<"逆序输出：";
    R_Print(L->next);
    return 0;
}