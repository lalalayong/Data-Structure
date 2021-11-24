/* 
    ɾ����ͷ���ĵ�����L������ֵΪx�Ľ�㡣���ͷ���ռ䣬����ֵΪx�Ľ�㲻Ψһ��
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

void deletex(LinkList &L, int x)
{
    LNode *q, *p = L;
    while (p->next) //����ɾ�������Ҫ�ý���ǰһ����㣬�����жϵ�ʱ��ֱ���ж���һ������Ԫ���Ƿ�Ϊx��ʡȥ��preָ��
    {
        if (p->next->data == x) //���p����һ����ֵΪx����ɾ����һ���
        {
            q = p->next;             //�ݴ���һ���
            p->next = p->next->next; //ɾ����һ���
            free(q);                 //�ͷ��ڴ�
        }
        else //���򣬽�����һ�������ж�
        {
            p = p->next;
        }
    }
}
int main()
{
    int n = 6;
    int A[6] = {1, 2, 4, 3, 4, 5};
    LNode *L = (LNode *)malloc(sizeof(LNode));
    buildList(L, A, n);
    display(L);
    int x;
    cout << "������Ҫɾ����Ԫ�أ�";
    cin >> x;
    deletex(L, x);
    display(L);
    return 0;
}