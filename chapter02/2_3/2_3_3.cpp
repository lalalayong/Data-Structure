/* 
    ���������ͷ���ĵ������ֵ��
    �㷨˼�룺1.ͷ�巨�����������ٱ������
            2.�����������ÿ���ڵ㣬ֵ��ջ������ջ
            3.�ݹ飺�ȵݹ飬���������������
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

void R_Print(LinkList L){
    if(L->next!=NULL)
        R_Print(L->next); //�ݹ�
    if(L!=NULL)
        cout<<L->data<<" "; //�������
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout<<"ԭ����";
    display(L);
    cout<<"���������";
    R_Print(L->next);
    return 0;
}