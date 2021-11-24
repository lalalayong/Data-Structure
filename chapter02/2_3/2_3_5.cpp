/* 
    �͵����ô�ͷ���ĵ�����ͷ�巨��
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

//ͷ�巨���õ�����
void reverse(LinkList &L){
    LNode *p,*r; //pΪ����ָ�룬rΪp�ĺ�̣���ֹ����
    p=L->next; //pָ���һ��Ԫ�ؽ��
    L->next=NULL; //��ͷ���next��ΪNULL
    while(p){
        r=p->next; //��¼p�ĺ��
        p->next=L->next; //ͷ�巨
        L->next=p;
        p=r; //p����
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
    reverse(L);
    cout << "���ú�ĵ�����";
    display(L);
    return 0;
}