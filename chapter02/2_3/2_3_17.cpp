/* 
    ���һ���㷨�жϴ�ͷ����ѭ��˫�����Ƿ�Գơ�
 */
#include <iostream>
using namespace std;

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//������ͷ����ѭ��˫���������飩
void buildList(DLinkList &L, int a[], int n)
{
    L = (DLinkList)malloc(sizeof(DNode));
    DNode *r = L; //rʼ��ָ��˫�������һ�����
    L->next = L;
    L->prior = L;
    for (int i = 0; i < n; i++)
    {
        DNode *s = (DLinkList)malloc(sizeof(DNode));
        s->data = a[i];

        s->next = r->next; //ѭ��˫����β�巨
        r->next->prior = s;
        s->prior = r;
        r->next = s;
        
        r = s; //rָ���µ�β�����
        L->prior = s; //L��ǰ��ָ��β�����
    }
}

//���ѭ��˫����
void display(DLinkList L)
{
    DNode *p = L->next;
    while (p != L)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool isSymmetry(DLinkList L)
{
    DNode *p = L->next;
    DNode *q = L->prior;
    while (p != q && q->next != p) //����ʱ��p!=qֹͣѭ����ż��ʱ��q->next!=pʱ����ѭ������ʱp��q�պû���λ�ã�p�ܵ�q�ĺ�̣�
    {
        if (p->data == q->data) //������ͬ����ͬ����
        {
            p = p->next;
            q = q->prior;
        }
        else
        {
            return false;
        }
    }//whileѭ�����������������ǶԳƵ�
    return true;
}

int main()
{
    int n = 5;
    int a[5] = {1, 1, 3, 2, 1};
    DLinkList L;
    buildList(L,a,n);
    cout<<"ѭ��˫����:";
    display(L);
    if (isSymmetry(L))
    {
        cout << "��ѭ��˫�����ǶԳƵģ���" << endl;
    }
    else
    {
        cout << "��ѭ��˫�����ǶԳƵģ���" << endl;
    }
    return 0;
}