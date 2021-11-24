/* 
    判断带头结点的单链表是否中心对称。
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *LinkList;

//尾插法建立单链表(从数组)
void buildList(LinkList L, char A[], int n)
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

bool dc(LinkList L, int n)
{
    int i;
    LNode *p = L->next;
    char a[n / 2];              //a[]字符栈
    for (i = 0; i < n / 2; i++) //链表前一半元素进栈
    {
        a[i] = p->data;
        p = p->next;
    }
    i--;            //让i指向栈顶（链表长若为偶数，i停在后一半第一个元素，若为奇数，i停在中间元素）
    if (n % 2 == 1) //链表长度若为奇数，让p指向链表后一半第一个元素
        p = p->next;
    while (p && p->data == a[i]) //检验是否中心对称
    {
        i--; //i作为栈顶指针
        p = p->next;
    }
    if (i == -1)     //栈为空栈
        return true; //链表中心对称
    else
        return false;
}

int main()
{
    int n = 7;
    char A[7] = {'l', 'o', 'a', 'd', 'a', 'o', 'l'};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    if (dc(L, n))
    {
        cout << "该链表中心对称！！" << endl;
    }
    else
    {
        cout << "该链表非中心对称！！" << endl;
    }

    return 0;
}