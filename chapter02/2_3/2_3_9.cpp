/* 
    ����һ����ͷ���ĵ�������headΪͷָ�룬�Ա�д�㷨����������������������еĸ��������ݣ����ͷŽ����ռ�Ĵ洢�ռ䡣
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

void min_Delete(LinkList &head)
{
    while (head->next)
    {
        LNode *p = head, *q=head; //p�ǹ���ָ�룬q��¼��Сֵ����ǰ����ÿ�δӵ������ͷ��ʼ
        int min = p->next->data;
        while (p->next) //ÿ���ж�p����һ���
        {
            if (p->next->data <min)
            {
                q = p; //С�ڵ�ǰ��Сֵ����¼�ý�㲢����min
                min=p->next->data; 
            }
            p=p->next; //p����
        }
        cout<<q->next->data<<" "; //�����Сֵ���Ԫ��
        p=q->next; //�ݴ���Сֵ���
        q->next=q->next->next; //����Сֵ���ӵ�������ɾ��
        free(p); //�ͷſռ�
    }
}

int main()
{
    int n = 6;
    int A[6] = {1, 2, 9, 5, 4, 1};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    cout << "ԭ����";
    display(L);
    cout << "�������������������Ԫ�أ�";
    min_Delete(L);
    return 0;
}