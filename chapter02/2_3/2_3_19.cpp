/* 
    ��һ����ͷ����ѭ������������ֵ��Ϊ�����������һ���㷨�������ҳ��������н��ֵ��С�Ľڵ㲢�����Ȼ�󽫸ý�����ɾ����ֱ��������Ϊ�գ����ɾ��ͷ��㡣
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

void Del_All(LinkList &L)
{
    while (L->next != L)
    {
        LNode *p = L->next, *minp = L->next, *q; //minp��¼��Сֵ����ǰ����Ĭ��ָ���һ��Ԫ�أ�pΪ����ָ��
        while (p->next != L)
        {
            if (p->next->data < minp->data)
            {
                minp = p;
            }
            p = p->next;
        }
        if (minp == L->next) //��һ���ж�֮��minpδ������������һ��Ԫ��Ϊ��Сֵ��
        {
            cout << minp->data << " ";
            L->next = minp->next;
            free(minp);
        }
        else
        {
            q = minp->next;
            cout << q->data << " ";
            minp->next = minp->next->next;
            free(q);
        }
    }
    free(L);
}
void Del_All_2(LinkList &L)
{
    while (L->next != L)
    {
        int min = INT_MAX;       //min��¼��Сֵ
        LNode *p = L, *minp, *q; //minp��¼��Сֵ����ǰ����Ĭ��ָ���һ��Ԫ�أ�pΪ����ָ��
        while (p->next != L)
        {
            if (p->next->data < min)
            {
                min = p->next->data;
                minp = p;
            }
            p = p->next;
        }
        q = minp->next;
        cout << q->data << " ";
        minp->next = minp->next->next;
        free(q);
    }
    free(L);
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, a, n1);
    cout << "ѭ��������L��";
    display(L);
    Del_All(L);
    return 0;
}