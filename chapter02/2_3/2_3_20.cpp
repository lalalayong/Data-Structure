/* 
    ��ͷָ��ΪL�Ĵ��б�ͷ���ķ�ѭ��˫��������ÿ������г���prior(ǰ��ָ��),data�����ݣ���next�����ָ�룩���⣬����һ������Ƶ����freg������������ǰ��
��ֵ����ʼ��Ϊ�㡣ÿ���������н���һ��Locate(L��x)����ʱ�������freg���ֵ��+1����ʹ�������н�㱣�ְ�����Ƶ�ȷ������ݼ�����˳�����У�ͬʱ������ʵĽ����
��Ƶ����ͬ�Ľ���ǰ�ߣ���ʹƵ�����ʵĽ�����ǿ�����ͷ���Ա�д��������Ҫ���Locate(L��x)����������ֵΪ���ҵ��Ľ��ĵ�ַ������Ϊָ�롣
    �㷨˼�룺�ҵ��ý�㣬������ժ�£�Ѱ�Ҵ�����λ�ã����룬����
 */
#include <iostream>
using namespace std;

//�з���Ƶ�ȵ�˫����
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
    int freq;
} DNode, *DLinkList;

//������ͷ���ķ�ѭ��˫���������飩
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
        s->freq = 0;

        s->next = r->next; //˫����β�巨
        r->next->prior = s;
        s->prior = r;
        r->next = s;

        r = s; //rָ���µ�β�����
    }
    r->next = NULL;
}

//���˫���������Ƶ��
void display_freq(DLinkList L)
{
    DNode *p = L->next;
    while (p)
    {
        cout << "<" << p->data << "," << p->freq << ">"
             << " ";
        p = p->next;
    }
    cout << endl;
}

DLinkList Locate(DLinkList &L, int x)
{
    DNode *p = L->next, *q;
    while (p && p->data != x) //�ҵ����
        p = p->next;
    if (!p) //����ڵ㲻���ڷ���NULL
        return NULL;
    else
    {
        p->freq++; //Ƶ��+1
        //��p���ժ��
        if (p->next) //���p�����һ����㣬�����������̽��priorָ��
            p->next->prior = p->prior;
        p->prior->next = p->next;

        q = L;
        while (q->next->freq > p->freq) //��ͷɨ������Ѱ��p������λ��
            q = q->next;

        p->next = q->next; //����ô�ŵ�λ��
        q->next->prior = p;
        q->next = p;
        p->prior = q;
        return p; //����pָ��
    }
}

int main()
{
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};
    DLinkList L;
    buildList(L, a, n);
    cout << "����ǰ��˫���������Ƶ��:";
    display_freq(L);
    int x;
    while (1)
    {
        cout << "������Ҫ���ҵ�ֵ��";
        cin >> x;
        DNode *p = Locate(L, x);
        if (p)
            cout << "���ҳɹ���" << endl;
        else
            cout
                << "����ʧ�ܣ�" << endl;
        cout << "���Һ��˫���������Ƶ��:";
        display_freq(L);
        cout << endl;
    }

    return 0;
}