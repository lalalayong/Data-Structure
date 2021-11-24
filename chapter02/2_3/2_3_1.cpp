/* 
    ���һ���ݹ��㷨��ɾ������ͷ���ĵ�����L������ֵΪx��Ԫ�ء�
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

int n = 4;
int A[4] = {1, 2, 3, 4};
void buildList(LinkList L)
{ //����ͷ�ڵ�
    LNode *s, *r = L;
    r->data = A[0];
    if (n == 1)
        r->next = NULL;
    else
    {
        for (int i = 1; i < n; i++)
        {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = A[i];
            r->next = s;
            r = s;
        }
    }
    r->next = NULL;
}

void display(LinkList L)
{
    LNode *s = L;
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

void deletex(LinkList &L, int x)
{
    LNode *p;
    if (L == NULL) //�ݹ����
        return;
    if (L->data == x) 
    {
        p = L;  //��L��ָ�Ľ���ֵΪx
        L = L->next; //ɾ��L,����Lָ����һ���
        free(p);
        deletex(L, x); //�ݹ����
    }
    else //��L��ָ�Ľ���ֵ��Ϊx
    {
        deletex(L->next, x); //�ݹ����
    }
}
int main()
{
    // LNode *L=new LNode(); //��new������ڴ�Ҫʹ��delete���ͷ��ڴ�
    LNode *L=(LNode *)malloc(sizeof(LNode)); //malloc��Ӧfree
    buildList(L);
    display(L);
    int x;
    cout << "������Ҫɾ����Ԫ�أ�";
    cin >> x;
    deletex(L, x);
    display(L);
    return 0;
}