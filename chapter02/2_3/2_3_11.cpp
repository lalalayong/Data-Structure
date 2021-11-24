/* 
    �����Ա�C={a1,b1,a2,b2,...,an,bn}���ô�ͷ���ĵ������ţ����һ���͵��㷨��������Ϊ�������Ա�A={a1,a2,...,an},B={b1,b2,...,bn}
    �㷨˼�룺���������β�巨�ӵ���A��ż�������ͷ�巨�ӵ���B������ʵ����ĿҪ��
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

LinkList disCreat_A_B(LinkList &A)
{
    LNode *p = A->next,*q; //pΪ����ָ�룬q��ֹ����
    LNode *ra=A; //raָ��A���β��
    LinkList B=(LinkList)malloc(sizeof(LNode));
    B->next=NULL;
    while(p){
        ra->next=p; //��ǰ���ӵ���A
        ra=p;
        p=p->next; //��һ���ӵ���B��ͷ�巨��
        if(p){
            q=p->next; //ͷ�巨ʱ��q����p����һ��㣬��ֹ����
            p->next=B->next;
            B->next=p;
            p=q;
        }
    }
    ra->next=NULL;
    return B;
}

int main()
{
    int n = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    LNode *A = (LNode *)malloc(sizeof(LNode));
    buildList(A, a, n);
    cout << "ԭ����A��";
    display(A);
    LNode *B=disCreat_A_B(A);
    cout << "�ֽ���A��";
    display(A);
    cout << "�ֽ���B��";
    display(B);
    return 0;
}