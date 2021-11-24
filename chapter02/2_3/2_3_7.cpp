/* 
    ��һ����ͷ���ĵ�����������Ԫ�ؽ���ֵ���򣬱�дһ��������ɾ�����н��ڸ���ֵ����Ϊ��������������֮���Ԫ�ء�
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

void rangeDelete(LinkList &L, int s, int t)
{
    LNode *p = L, *q;
    while (p->next)
    {
        if (p->next->data >= s && p->next->data <= t)
        {
            q = p->next;
            p->next = p->next->next; 
            free(q);
        }
        else //ֻ�в���������ʱp��ָ����һ���
        {
            p = p->next;
        }
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "ԭ����";
    display(L);
    int s, t;
    cout << "������Ҫɾ��Ԫ�صķ�Χ��";
    cin >> s >> t;
    rangeDelete(L, s, t);
    cout << "ɾ����ĵ�����";
    display(L);
    return 0;
}