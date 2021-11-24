/* 
    ��һ����ͷ���ĵ�����A�ֽ��������ͷ���ĵ�����A��B��ʹ��A���к���ԭ�������Ϊ������Ԫ�أ�B���к���ԭ�������Ϊż����Ԫ�أ��ұ��������˳�򲻱䡣
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
    LNode *p = A->next; //pΪ����ָ�룬ָ���һ�����
    A->next=NULL; //��A���ÿ�
    LinkList B=(LinkList)malloc(sizeof(LNode));
    LNode *ra=A,*rb=B; //ra��rb�ֱ�ָ��A���B���β��
    while(p){
        ra->next=p; //�������ӵ���A
        ra=p;
        rb->next=p->next; //ż�����ӵ���B
        rb=p->next;
        p=p->next->next; //p���������ٴ��ߵ�������������һ��ѭ��
    }
    ra->next=NULL;
    rb->next=NULL;
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