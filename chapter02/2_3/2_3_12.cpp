/* 
    ��һ����������ĵ�����������ֵ��ͬ��Ԫ�أ����һ���㷨ȥ����ֵ��ͬ��Ԫ�ء���{7,10,10,21,30,42,42,42,51,70}���{7,10,21,30,42,51,70}
    �㷨˼�룺��pɨ�赥������p���ֵ�������̽���ֵ��ɾ�����̽�㣬����p���ƣ�����ɨ�衣
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//β�巨����������(������)
void buildList(LinkList L, int A[], int n)
{
    //��ͷ�ڵ�
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

//��ʾ������
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

void Del_Same(LinkList &L)
{
    LNode *p = L->next, *q;
    if (!p)
        return;
    while (p->next)
    {
        if (p->data == p->next->data)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}

int main()
{
    int n = 10;
    int A[10] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "ԭ����";
    display(L);
    Del_Same(L);
    cout << "ȥ���ظ�Ԫ�غ�ĵ�����";
    display(L);
    return 0;
}