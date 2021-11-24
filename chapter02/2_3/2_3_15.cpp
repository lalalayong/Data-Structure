/* 
    ��A,B��������ͷ���ĵ���������Ԫ�ص���������AB�Ľ��������������A�С�
    �㷨˼�룺��A,B�����򣬿ɴӵ�һ��Ԫ�������αȽ�AB�����Ԫ�أ���Ԫ��ֵ��ͬ������һ�����ӵ�����������Ľ��ȫ���ͷţ���һ������ȫ��������ɺ�
�ͷ���һ�������е�ȫ��ʣ���㡣
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

LinkList Union_A_B(LinkList &A, LinkList &B)
{
    LNode *pa = A->next, *pb = B->next;
    LNode *pc = A; //��A���������
    LNode *u;
    while (pa && pb) //��һ��������β�����Ƴ�ѭ��
    {
        if (pa->data == pb->data) //�ҵ��������
        {
            pc->next = pa; //ѡ��һ�����������β��
            pc = pa;
            pa=pa->next; //pa����
            u = pb; //�ͷ���һ�����
            pb = pb->next;
            free(u);
        }
        else if (pa->data < pb->data) //Ԫ��С��ָ�����,���ͷŽ��
        {
            u = pa;
            pa = pa->next;
            free(u);
        }
        else
        {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    //��ʣ������ͷ�
    while (pa)
    {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb)
    {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL; //ע�⣺β�巨Ҫ�����һ������next�ÿ�
    free(B); //�ͷű�Bͷ���
    return A; //���ؽ����
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
    LNode *C = Union_A_B(A, B);
    cout << "����A,B�Ľ�����";
    display(C);
    return 0;
}