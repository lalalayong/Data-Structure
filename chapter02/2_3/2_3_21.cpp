/* 
    2009ͳ��
    ��ͷ���ĵ������ͷָ��Ϊlist�����ṹΪdata��link���ڲ��ı������ǰ���£������һ�������ܸ�Ч���㷨�����������е�����k��λ���ϵĽ�㣨kΪ����������
�����ҳɹ�����ý���data���ֵ��������1�����򷵻�0��
    �㷨˼�룺����ָ��p��q����ʼʱ��ָ���һ����㣬��ָ��p����k����Ȼ�����ָ��һ���ߣ�ֱ����ָ���ߵ����һ�����ʱ����ָ����ָ�Ľ�㼴Ϊ������k����㡣
    ʱ�临�Ӷȣ�O(n)
 */
/* 
    ɾ����ͷ���ĵ�����L������ֵΪx�Ľ�㡣���ͷ���ռ䣬����ֵΪx�Ľ�㲻Ψһ��
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *link;
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
        r->link = s;
        r = s;
    }
    r->link = NULL;
}
//��ʾ������
void display(LinkList L)
{
    LNode *s = L->link;
    while (s)
    {
        cout << s->data << " ";
        s = s->link;
    }
    cout << endl;
}

int Search_k(LinkList L, int k)
{
    LNode *p = L->link, *q = L->link; //p��qָ���һ�����
    int k1 = k;
    while (--k) //p����k��
    {
        if (!p->link) //�����Ȳ���k������ʧ�ܣ�����0
            return 0;
        else
            p = p->link;
    }
    while (p->link) //p��qͬ����
    {
        p = p->link;
        q = q->link;
    }
    //p�ߵ����һ�����ʱ��qָ������k�����
    cout << "������" << k1 << "��Ԫ��Ϊ " << q->data << endl; //���������
    return 1;
}

int Search_k_1(LinkList L, int k)
{
    LNode *p = L->link, *q = L->link; //p��qָ���һ�����
    int k1 = k;
    int count = 0;
    while (p) //��������
    {
        if (count < k) //��������count<k��ֻ�ƶ�p
            count++;
        else
            q = q->link;
        p = p->link; //֮��p��qͬʱ�ƶ�
    }
    if (count < k) //����ʧ�ܣ�����0
        return 0;
    else //���ҳɹ������������1
    {
        cout << "������" << k1 << "��Ԫ��Ϊ " << q->data << endl;
        return 1;
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    int k;
    cout << "������Ҫ���ҵ����ڼ���Ԫ�أ�";
    cin >> k;
    if (Search_k_1(L, k))
    {
        cout << "���ҳɹ�����" << endl;
    }
    else
    {
        cout << "����ʧ�ܣ���" << endl;
    }
    return 0;
}