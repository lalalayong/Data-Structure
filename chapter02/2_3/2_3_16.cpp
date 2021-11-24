/* 
    两个整数序列分别存放在两个单链表中，设计一个算法，判断序列B是否为序列A的连续子序列.
    算法思想：从两个链表的第一个结点开始比较，若数据相同，则后移指针，若之后数据不相同，则A从上次开始比较的结点的后继开始，B仍从第一个结点开始，
直到B到达表尾，表示成功，若A到了表尾而B未到表尾，表示失败，操作中应记录A链表每次开始的结点，以便下次匹配时好从其后继开始。

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

bool pattern(LinkList A, LinkList B)
{
    LNode *pa = A->next, *pb = B->next;
    LNode *pre=A->next; //pre记录每次比较中A链表的开始结点
    while(pa&&pb){
        if(pa->data==pb->data){ //数据匹配则一直后移，直到表尾
            pa=pa->next;
            pb=pb->next;
        }else{ //若中途发生不匹配则pa重置为A表上次开始结点的后继，pb重置为B表第一个结点
            pre=pre->next;
            pa=pre;
            pb=B->next;
        }
    }
    if(pb==NULL)
        return true;
    else
        return false;
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int b[4] = {2, 3, 4, 5};
    LNode *A = (LNode *)malloc(sizeof(LNode));
    LNode *B = (LNode *)malloc(sizeof(LNode));
    buildList(A, a, n1);
    buildList(B, b, n2);
    cout << "原链表A：";
    display(A);
    cout << "原链表B：";
    display(B);
    if(pattern(A,B)){
        cout<<"序列B是序列A的连续子序列!"<<endl;
    }
    else
        cout<<"序列B不是序列A的连续子序列!"<<endl;

    return 0;
}