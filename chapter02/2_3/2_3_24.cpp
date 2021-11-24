/* 
    ���һ���㷨���ж�һ�������Ƿ��л�������У��ҳ�������ڵ㲢���أ����򷵻�NULL.
    �㷨˼�룺1.���ÿ���ָ��ͬʱ���ƣ��ҵ������㣨���л�����
            2.����������ָ�루һ���ӵ�һ����㡢һ���������㣩ͬ���ߣ�һ����һ����
            3.��������ָ���ٴ�����ʱ��Ϊ������ڵ�
 */

/* 
    ɾ����ͷ���ĵ�����L������ֵΪx�Ľ�㡣���ͷ���ռ䣬����ֵΪx�Ľ�㲻Ψһ��
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
    r->next = L->next->next->next->next; //�ֶ����û�����4��ʼ4,5,6Ϊ��
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

LNode *findLoopStart(LinkList L)
{
    LNode *slow = L->next, *fast = L->next; //���ÿ���ָ��
    while (slow && fast->next)
    {
        slow = slow->next;       //ÿ����һ��
        fast = fast->next->next; //ÿ��������
        if (slow == fast)        //����
            break;
    }
    if (slow == NULL || fast->next == NULL)
        return NULL;               //û�л�������NULL
    LNode *p = L->next, *q = slow; //�ֱ�ָ��ʼ���������
    while (p != q)                 //ͬ���ߣ�ֱ���ٴ���������Ϊ������ڵ�
    {
        p = p->next;
        q = q->next;
    }
    return p; //������ڵ�
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    LNode *p = findLoopStart(L);
    if (p)
    {
        cout << "������ڵ�Ϊ" << p->data << endl;
    }
    else
    {
        cout << "�������޻���" << endl;
    }
    return 0;
}