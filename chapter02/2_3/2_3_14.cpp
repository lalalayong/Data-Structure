/* 
    ��A,B��������ͷ���ĵ���������Ԫ�ص����������һ���㷨��A,B�еĹ���Ԫ�ز���������C��Ҫ���ƻ�A,B�Ľ�㡣
    �㷨˼�룺��A,B�����򣬿ɴӵ�һ��Ԫ�������αȽ�AB�����Ԫ�أ���Ԫ��ֵ����ͬ���С��ָ������ƣ���Ԫ��ֵ��ͬ���򴴽�һ��ֵ��ͬ�Ľ����루β�巨��
���µ�����C�С�Ȼ������ָ��ͬʱ���ƣ�ֱ��һ��������β����
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

LinkList getCommon(LinkList A, LinkList B)
{
    LNode *pa = A->next, *pb = B->next;
    LNode *C = (LNode *)malloc(sizeof(LNode)); //������C
    LNode *r = C; //rʼ��ָ���C��β���
    while (pa && pb) //��һ��������β�����Ƴ�ѭ��
    {
        if (pa->data == pb->data) //�ҵ�������㣬�����½��������Cβ��
        {
            LNode *s = (LNode *)malloc(sizeof(LNode));
            s->data = pa->data; 
            r->next = s; //β�巨
            r = s;
            pa = pa->next; //��A�ͱ�B�������ɨ��
            pb = pb->next;
        }
        else if (pa->data < pb->data) //Ԫ��С��ָ�����
        {
            pa = pa->next;
        }
        else
        {
            pb = pb->next;
        }
    }
    r->next=NULL; //ע�⣺β�巨Ҫ�����һ������next�ÿ�
    return C;
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
    LNode *C = getCommon(A, B);
    cout << "AB����Ԫ�ص�����C��";
    display(C);
    return 0;
}