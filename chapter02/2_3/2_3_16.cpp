/* 
    �����������зֱ����������������У����һ���㷨���ж�����B�Ƿ�Ϊ����A������������.
    �㷨˼�룺����������ĵ�һ����㿪ʼ�Ƚϣ���������ͬ�������ָ�룬��֮�����ݲ���ͬ����A���ϴο�ʼ�ȽϵĽ��ĺ�̿�ʼ��B�Դӵ�һ����㿪ʼ��
ֱ��B�����β����ʾ�ɹ�����A���˱�β��Bδ����β����ʾʧ�ܣ�������Ӧ��¼A����ÿ�ο�ʼ�Ľ�㣬�Ա��´�ƥ��ʱ�ô����̿�ʼ��

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

bool pattern(LinkList A, LinkList B)
{
    LNode *pa = A->next, *pb = B->next;
    LNode *pre=A->next; //pre��¼ÿ�αȽ���A����Ŀ�ʼ���
    while(pa&&pb){
        if(pa->data==pb->data){ //����ƥ����һֱ���ƣ�ֱ����β
            pa=pa->next;
            pb=pb->next;
        }else{ //����;������ƥ����pa����ΪA���ϴο�ʼ���ĺ�̣�pb����ΪB���һ�����
            pre=pre->next;
            pa=pre;
            pb=B->next;
        }
    }
    if(pb==NULL)
        return true;
    else
        return false;
}

int main()
{
    int n1 = 6;
    int a[6] = {1, 2, 3, 4, 5, 6};
    int n2 = 4;
    int b[4] = {2, 3, 4, 5};
    LNode *A = (LNode *)malloc(sizeof(LNode));
    LNode *B = (LNode *)malloc(sizeof(LNode));
    buildList(A, a, n1);
    buildList(B, b, n2);
    cout << "ԭ����A��";
    display(A);
    cout << "ԭ����B��";
    display(B);
    if(pattern(A,B)){
        cout<<"����B������A������������!"<<endl;
    }
    else
        cout<<"����B��������A������������!"<<endl;

    return 0;
}