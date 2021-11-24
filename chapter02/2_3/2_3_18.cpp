/* 
    ������ѭ��������ͷָ��ֱ�Ϊh1��h2����дһ������������h2���ӵ�h1֮��ʹ�������Ա���ѭ��������ʽ��
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//β�巨����ѭ��������(������)
void buildList(LinkList L, int A[], int n)
{
    //��ͷ�ڵ�
    LNode *s, *r = L;
    L->next = L;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = A[i];

        r->next = s;
        r = s;
    }
    r->next = L;
}

//��ʾѭ��������
void display(LinkList L)
{
    LNode *s = L->next;
    while (s != L)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

LinkList Link_L1_L2(LinkList &h1, LinkList &h2)
{
    LNode *p1 = h1, *p2 = h2;
    while (p1->next != h1) //�ֱ��ҵ�L1��L2��β���
        p1 = p1->next;
    while (p2->next != h2)
        p2 = p2->next;
    p1->next = h2->next; //��L1��β������ӵ�L2��ͷ��㣬
    p2->next = h1; //��L2��β������ӵ�L1��ͷ��㣬�γ��µ�ѭ��������
    return h1;
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int b[4] = {7, 8, 9, 10};
    LNode *L1 = (LNode *)malloc(sizeof(LNode));
    LNode *L2 = (LNode *)malloc(sizeof(LNode));
    buildList(L1, a, n1);
    buildList(L2, b, n2);
    cout << "ԭѭ��������L1��";
    display(L1);
    cout << "ԭѭ��������L2��";
    display(L1);
    LinkList L = Link_L1_L2(L1, L2);
    cout << "���Ӻ��ѭ��������";
    display(L);
    return 0;
}