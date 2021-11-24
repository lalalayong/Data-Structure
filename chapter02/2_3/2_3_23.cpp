/* 
    2015统考
    用单链表保存m个整数，链表中数据data的绝对值<n，设计一个时间复杂度尽可能高的算法，对于链表中data绝对值相同的结点，仅保留第一次出现的结点，其他的均删除。
例如{21，-15，-15，-7,15},删除后变为{21,-15,-7}。
    算法思想：空间换时间，由于data绝对值小于n，则利用一个大小为n+1（0的绝对值为0）的辅助数组A，A中默认所有元素初值为0，
            从头遍历链表，当A[|p->next->data|]为1时，则删除该结，否则将A[|data|]置为1，
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

void Del_Com_Abs(LinkList &L, int n)
{
    LNode *p = L, *q;
    int *A = (int *)malloc((n + 1) * sizeof(int)); //申请n+1个位置的辅助空间
    for (int i = 0; i < n + 1; i++)                //数组元素初值为0
        A[i] = 0;
    while (p->next)
    {

        if (A[abs(p->next->data)] == 0) //判断是否已存在data绝对值相同的结点
        {
            A[abs(p->next->data)] = 1; //首次出现，保留
            p = p->next;
        }
        else //重复出现，删除
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
        }
    }
    free(A); //释放辅助空间
}
int main()
{
    int num = 22;
    int n1 = 5;
    int A[5] = {21, -15, -15, -7, 15};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n1);
    display(L);
    Del_Com_Abs(L, num);
    cout << "删除绝对值重复的元素后：" << endl;
    display(L);
    return 0;
}