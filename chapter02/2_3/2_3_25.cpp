/* 
    ���ͷ���ĵ�����{a1,a2,a3,...,an-2.an-1,an},���һ���ռ临�Ӷ�ΪO(1)��ʱ���Ͼ����ܸ�Ч���㷨���������е���������Ϊ{a1,an,a2,an-1,a3,an-2,...}.
    �㷨˼�룺��ǰ��ȡһ�����Ӻ��ȡһ���������ǵ�����Ҫ��Ӻ�ߵ���ȡ��㣬���Ƚ������һ�����ã������ÿ���ָ���ҵ��м�ڵ㣩
            Ȼ��һ��ָ��ָ���һ����㣬һ��ָ��ָ�����ú�ĺ�벿�ֵ�һ����㣬
            Ȼ������ȡ�½�㣬����ָ��λ�ã�
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

void change_list(LinkList &L)
{
    LNode *slow, *fast;
    LNode *p, *q, *r, *s;
    slow = fast = L;
    while (fast->next) //�ҵ��м���
    {
        slow = slow->next; //��ָ����һ��
        fast = fast->next;
        if (fast->next) //��ָ�������������next���ڣ�
            fast = fast->next;
    }
    p = slow;       //pΪ�м���
    q = slow->next; //qΪ����������׽��
    p->next = NULL; //��p->next��Ϊ��
    while (q)       //�������������ã�ͷ�巨��
    {
        r = q->next; //��¼q�ĺ�̣���ֹ����
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next; //sָ��ǰ��ε�һ����㣬�������
    q = p->next; //qָ����ε�һ�����
    p->next = NULL;
    while (q) //��������εĽ����뵽ָ��λ��
    {
        r = q->next;       //rָ����ε���һ�������
        q->next = s->next; //��qָ��Ľ����뵽s֮��
        s->next = q;
        s = q->next; //sָ��ǰ��ε���һ�������
        q = r;
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    change_list(L);
    cout << "���ź�ĵ�����" << endl;
    display(L);
    return 0;
}