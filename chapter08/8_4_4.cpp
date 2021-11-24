/* 
    �ڻ��ڵ������ʾ�Ĵ�����ؼ��������Ͻ��м�ѡ������
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
int n = 8;

void buildList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    LNode *r = L, *s;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = A[i];
        r->next = s;
        r = r->next;
    }
    r->next=NULL;
}
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

void SelectSort(LinkList &L)
{
    LNode *h = L->next, *r, *s, *p, *q;
    L->next = NULL;
    while (h) //����ɨ��ԭ����
    {
        p = s = h;
        q = r = NULL;
        //s��r��¼��������ǰ����pΪ����ָ�룬qΪ��ǰ��
        while (p) //ɨ��ԭ����Ѱ�������s
        {
            if (p->data > s->data)
            { //�ҵ�����ģ���¼��������ǰ��
                s = p;
                r = q;
            }
            q = p; //����Ѱ��
            p = p->next;
        }
        if (s == h)
            h = h->next;  //�������ԭ����ǰ�ˣ�����ժ��
        else
            r->next = s->next; //�������ԭ������ڣ�����ժ��

        s->next = L->next; //�������s��������ǰ��
        L->next = s;
    }
}

int main()
{
    LinkList L;
    buildList(L);
    cout << "����ǰ�ĵ�����";
    display(L);
    SelectSort(L);
    cout <<"�����ĵ�����";
    display(L);
    return 0;
}