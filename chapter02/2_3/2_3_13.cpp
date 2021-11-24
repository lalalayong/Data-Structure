/* 
    �������������������Ԫ�ص����������У����һ���㷨���͵ؽ�����������ϳ�һ����Ԫ�صݼ��������еĵ�����
    �㷨˼�룺��������������Դӵ�һ����㿪ʼ�Ƚϣ�����С�Ľ����������У�������ĿҪ���������Եݼ�˳�����У����Բ���ͷ�巨��
�ȽϽ�������ܻ���һ������ǿգ���ʱֱ�ӽ�����������н��ͷ�嵽�����
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

void merge(LinkList &A, LinkList &B)
{//��AB����ϲ���A��
    LNode *pa = A->next, *pb = B->next;
    LNode *r; //ͷ�巨ʱr������¼��һ��㣬��ֹ����
    A->next = NULL; //ͷ�巨����������ÿ�
    while (pa && pb)
    {
        if (pa->data <= pb->data) //��ֵ��С�Ľ���������
        {
            r = pa->next; //r�ݴ�pa�ĺ�̽�㣬��ֹ����
            pa->next = A->next; //ͷ�巨
            A->next = pa;
            pa = r;
        }
        else
        {
            r = pb->next;
            pb->next = A->next;
            A->next = pb;
            pb = r;
        }
    }
    //ͨ������һ������ǿգ�ֱ�ӽ�ʣ��Ԫ�ز�������
    while (pa)
    {
        r = pa->next;
        pa->next = A->next;
        A->next = pa;
        pa = r;
    }
    while (pb)
    {
        r = pb->next;
        pb->next = A->next;
        A->next = pb;
        pb = r;
    }
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int b[4] = {1, 4, 7, 8};
    LNode *A = (LNode *)malloc(sizeof(LNode));
    LNode *B = (LNode *)malloc(sizeof(LNode));
    buildList(A, a, n1);
    buildList(B, b, n2);
    cout << "ԭ����A��";
    display(A);
    cout << "ԭ����B��";
    display(B);
    merge(A,B);
    cout << "�ϲ���ĵ�����";
    display(A);
    return 0;
}