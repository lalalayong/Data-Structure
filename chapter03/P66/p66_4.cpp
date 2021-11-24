/* 
    �жϴ�ͷ���ĵ������Ƿ����ĶԳơ�
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *LinkList;

//β�巨����������(������)
void buildList(LinkList L, char A[], int n)
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

bool dc(LinkList L, int n)
{
    int i;
    LNode *p = L->next;
    char a[n / 2];              //a[]�ַ�ջ
    for (i = 0; i < n / 2; i++) //����ǰһ��Ԫ�ؽ�ջ
    {
        a[i] = p->data;
        p = p->next;
    }
    i--;            //��iָ��ջ����������Ϊż����iͣ�ں�һ���һ��Ԫ�أ���Ϊ������iͣ���м�Ԫ�أ�
    if (n % 2 == 1) //��������Ϊ��������pָ�������һ���һ��Ԫ��
        p = p->next;
    while (p && p->data == a[i]) //�����Ƿ����ĶԳ�
    {
        i--; //i��Ϊջ��ָ��
        p = p->next;
    }
    if (i == -1)     //ջΪ��ջ
        return true; //�������ĶԳ�
    else
        return false;
}

int main()
{
    int n = 7;
    char A[7] = {'l', 'o', 'a', 'd', 'a', 'o', 'l'};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    if (dc(L, n))
    {
        cout << "���������ĶԳƣ���" << endl;
    }
    else
    {
        cout << "����������ĶԳƣ���" << endl;
    }

    return 0;
}