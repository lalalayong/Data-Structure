/* 
    ����������������д�㷨�ҵ���������Ĺ�����㣨��ĳһ��㿪ʼ���ǵ�next��ָ��һ����㣩
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//β�巨�����й������ĵ�����(������)
void buildList(LinkList L1, LinkList L2, int A[], int B[], int n1, int n2)
{
    //��ͷ�ڵ�  
    LNode *s1, *r1 = L1;
    LNode *s2, *r2 = L2;
    int dist = n1 - n2;
    for (int i = 0; i < dist + 1; i++)
    {
        s1 = (LNode *)malloc(sizeof(LNode));
        s1->data = A[i];
        r1->next = s1;
        r1 = s1;
    }
    for (int i = 0; i < 1; i++)
    {
        s2 = (LNode *)malloc(sizeof(LNode));
        s2->data = B[i];
        r2->next = s2;
        r2 = s2;
    }
    for (int i = dist + 1; i < n1; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = A[i];
        r1->next = r2->next = s;
        r1 = r2 = s;
    }
    r1->next = r2->next = NULL;
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

int Length(LinkList L)
{
    int k = 0;
    LNode *s = L->next;
    while (s)
    {
        k++;
        s = s->next;
    }
    return k;
}

LNode *Search_1st_Common(LinkList L1, LinkList L2)
{
    int len1 = Length(L1); //����������ı�
    int len2 = Length(L2);
    int dist; //��֮��
    LinkList longlist, shortlist; //�ֱ�ָ����ϳ��ͽ϶̵�����
    if (len1 > len2) //L1���ϳ�
    {
        longlist = L1->next;
        shortlist = L2->next;
        dist = len1 - len2; //��֮��
    }
    else  //L2���ϳ�
    {
        longlist = L2->next;
        shortlist = L1->next;
        dist = len2 - len1;
    }
    while (dist--)  //���������ȱ�������dist����Ȼ������ͬ����
        longlist = longlist->next;
    while (longlist)  //ͬ��Ѱ�ҹ������
    {
        if (longlist == shortlist) //�ҵ��򷵻ؽ��ָ��
            return longlist;
        else
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    return NULL; //����������û�й������
}

int main()
{
    int n1 = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int B[4] = {7, 4, 5, 6};
    LNode *L1 = (LNode *)malloc(sizeof(LNode));
    LNode *L2 = (LNode *)malloc(sizeof(LNode));
    buildList(L1, L2, A, B, n1, n2);
    cout << "ԭ����L1��";
    display(L1);
    cout << "ԭ����L2��";
    display(L2);
    LNode *C = Search_1st_Common(L1, L2);
    cout << "�������Ϊ��" << C->data << endl;
    ;
    return 0;
}