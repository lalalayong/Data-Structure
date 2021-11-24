/* 
    ɾ����ͷ���ĵ���������Сֵ��㡣
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

void del_Min(LinkList &L)
{
    int min = L->next->data; //min��¼��Сֵ��Ĭ��ָ���һ�����
    LNode *p = L->next, *q = L; //qָ���ɾ������ǰ����pΪ����ָ��
    while (p->next) //ÿ���ж�p����һ��㣬ʡȥ��preָ��
    {
        if (p->next->data < min) 
        {
            min = p->next->data; //���С����Сֵ�����£�����¼��ǰ��
            q = p;  
        }
        p = p->next;
    }
    LNode *f = q->next;
    q->next = q->next->next; //ɾ����Сֵ���
    free(f);
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "ԭ����";
    display(L);
    del_Min(L);
    cout << "ɾ����Сֵ����";
    display(L);
    return 0;
}