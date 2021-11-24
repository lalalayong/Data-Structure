/* 
    2015ͳ��
    �õ�������m������������������data�ľ���ֵ<n�����һ��ʱ�临�ӶȾ����ܸߵ��㷨������������data����ֵ��ͬ�Ľ�㣬��������һ�γ��ֵĽ�㣬�����ľ�ɾ����
����{21��-15��-15��-7,15},ɾ�����Ϊ{21,-15,-7}��
    �㷨˼�룺�ռ任ʱ�䣬����data����ֵС��n��������һ����СΪn+1��0�ľ���ֵΪ0���ĸ�������A��A��Ĭ������Ԫ�س�ֵΪ0��
            ��ͷ����������A[|p->next->data|]Ϊ1ʱ����ɾ���ýᣬ����A[|data|]��Ϊ1��
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

void Del_Com_Abs(LinkList &L, int n)
{
    LNode *p = L, *q;
    int *A = (int *)malloc((n + 1) * sizeof(int)); //����n+1��λ�õĸ����ռ�
    for (int i = 0; i < n + 1; i++)                //����Ԫ�س�ֵΪ0
        A[i] = 0;
    while (p->next)
    {

        if (A[abs(p->next->data)] == 0) //�ж��Ƿ��Ѵ���data����ֵ��ͬ�Ľ��
        {
            A[abs(p->next->data)] = 1; //�״γ��֣�����
            p = p->next;
        }
        else //�ظ����֣�ɾ��
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
        }
    }
    free(A); //�ͷŸ����ռ�
}
int main()
{
    int num = 22;
    int n1 = 5;
    int A[5] = {21, -15, -15, -7, 15};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n1);
    display(L);
    Del_Com_Abs(L, num);
    cout << "ɾ������ֵ�ظ���Ԫ�غ�" << endl;
    display(L);
    return 0;
}