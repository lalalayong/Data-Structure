/* 
    2012ͳ��
    �ٶ����ô�ͷ���ĵ������浥�ʣ���������������ͬ�ĺ�׺ʱ���ɹ�����ͬ�ĺ�׺�洢�ռ䣬����loading��being����str1��str2�ֱ�ָ�������������ͷ��㣬���һ��
ʱ���Ͼ����ܸ�Ч���㷨���ҳ�����������ͬ��׺����ʼλ�ã�ָ����ͬ����
    �㷨˼�룺1.�ֱ������������ĳ���m��n
            2.����������β�����룬�������������������ֵ������ʹp��q��ָ��㵽����β���ĳ�����ͬ��
            3.��p��qͬ�����ƣ�ֱ��p��qָ��ͬһ��λ�ã����������ء�
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

int listLength(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while (p)
    {
        p = p->next;
        len++;
    }
    return len;
}

LNode *findAddr(LinkList str1, LinkList str2)
{
    LNode *p = str1, *q = str2;
    int len1 = listLength(str1); //����������
    int len2 = listLength(str2);
    if (len1 > len2) //�����������߲�ֵ������
    {
        int dist = len1 - len2;
        for (int i = 0; i < dist; i++)
            p = p->next;
    }
    else
    {
        int dist = len2 - len1;
        for (int i = 0; i < dist; i++)
            q = q->next;
    }
    while (p->next && p->next->data != q->next->data) //��ָ��p��qͬ������
    {
        p = p->next;
        q = q->next;
    }
    return p->next; //���ع�ͬ��׺����ʼ��ַ
}

int main()
{
    int n1 = 7;
    char A[7] = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};
    int n2 = 5;
    char B[5] = {'b', 'e', 'i', 'n', 'g'};
    LNode *str1 = (LNode *)malloc(sizeof(LNode));
    LNode *str2 = (LNode *)malloc(sizeof(LNode));
    buildList(str1, A, n1);
    buildList(str2, B, n2);
    display(str1);
    display(str2);
    LNode *p = findAddr(str1, str2);
    if (p)
    {
        cout << "��һ����ͬ��׺λ�ã�" << p->data << endl;
    }
    else
    {
        cout << "�޹�ͬ��׺" << endl;
    }
    return 0;
}