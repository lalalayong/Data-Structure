/* 
    ��һ����ͷ���ĵ��������һ���㷨ʹ��Ԫ�ص�������
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

void Sort(LinkList &L){
    LNode *pre;     //pre������¼p�Ĵ�����λ�õ�ǰ��
    LNode *p=L->next,*r=p->next;   //pΪ����ָ�룬rָ��p��̣���ֹ����
    L->next=NULL; //��L��next��Ϊ��
    p->next=L->next; //�����һ����㣬�����������ͷ�巨��
    L->next=p;
    p=r;
    while(p){
        r=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)  //�ҵ��������λ�ã���¼��ǰ��
            pre=pre->next;
        p->next=pre->next; //ͷ�巨����
        pre->next=p;
        p=r; //����ɨ��ԭ��������ʣ�µĽ��
    }
}

int main()
{
    int n = 6;
    int A[6] = {8, 2, 3, 4, 5, 1};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "ԭ����";
    display(L);
    Sort(L);
    cout << "���������ĵ�����";
    display(L);
    return 0;
}