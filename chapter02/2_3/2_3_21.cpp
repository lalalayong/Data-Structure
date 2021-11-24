/* 
    2009统考
    带头结点的单链表表头指针为list，结点结构为data，link，在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点（k为正整数），
若查找成功输出该结点的data域的值，并返回1，否则返回0。
    算法思想：快慢指针p、q，初始时均指向第一个结点，快指针p先走k步，然后快慢指针一起走，直到快指针走到最后一个结点时，慢指针所指的结点即为倒数第k个结点。
    时间复杂度：O(n)
 */
/* 
    删除带头结点的单链表L中所有值为x的结点。并释放其空间，假设值为x的结点不唯一。
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *link;
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
        r->link = s;
        r = s;
    }
    r->link = NULL;
}
//显示单链表
void display(LinkList L)
{
    LNode *s = L->link;
    while (s)
    {
        cout << s->data << " ";
        s = s->link;
    }
    cout << endl;
}

int Search_k(LinkList L, int k)
{
    LNode *p = L->link, *q = L->link; //p、q指向第一个结点
    int k1 = k;
    while (--k) //p先走k步
    {
        if (!p->link) //链表长度不足k，查找失败，返回0
            return 0;
        else
            p = p->link;
    }
    while (p->link) //p、q同步走
    {
        p = p->link;
        q = q->link;
    }
    //p走到最后一个结点时，q指向倒数第k个结点
    cout << "倒数第" << k1 << "个元素为 " << q->data << endl; //输出并返回
    return 1;
}

int Search_k_1(LinkList L, int k)
{
    LNode *p = L->link, *q = L->link; //p、q指向第一个结点
    int k1 = k;
    int count = 0;
    while (p) //遍历链表
    {
        if (count < k) //计数，若count<k则只移动p
            count++;
        else
            q = q->link;
        p = p->link; //之后p、q同时移动
    }
    if (count < k) //查找失败，返回0
        return 0;
    else //查找成功，输出并返回1
    {
        cout << "倒数第" << k1 << "个元素为 " << q->data << endl;
        return 1;
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    int k;
    cout << "请输入要查找倒数第几个元素：";
    cin >> k;
    if (Search_k_1(L, k))
    {
        cout << "查找成功！！" << endl;
    }
    else
    {
        cout << "查找失败！！" << endl;
    }
    return 0;
}