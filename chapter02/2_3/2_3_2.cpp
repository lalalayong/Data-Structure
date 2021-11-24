/* 
    删除带头结点的单链表L中所有值为x的结点。并释放其空间，假设值为x的结点不唯一。
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

void deletex(LinkList &L, int x)
{
    LNode *q, *p = L;
    while (p->next) //由于删除结点需要该结点的前一个结点，所以判断的时候直接判断下一个结点的元素是否为x，省去了pre指针
    {
        if (p->next->data == x) //如果p的下一结点的值为x，则删除下一结点
        {
            q = p->next;             //暂存下一结点
            p->next = p->next->next; //删除下一结点
            free(q);                 //释放内存
        }
        else //否则，进行下一个结点的判断
        {
            p = p->next;
        }
    }
}
int main()
{
    int n = 6;
    int A[6] = {1, 2, 4, 3, 4, 5};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    int x;
    cout << "请输入要删除的元素：";
    cin >> x;
    deletex(L, x);
    display(L);
    return 0;
}