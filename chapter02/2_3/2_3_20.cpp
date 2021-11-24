/* 
    设头指针为L的带有表头结点的非循环双向链表，其每个结点中除有prior(前驱指针),data（数据）和next（后继指针）域外，还有一个访问频度域freg。在链表被启用前，
其值均初始化为零。每当在链表中进行一次Locate(L，x)运算时，结点中freg域的值增+1，并使此链表中结点保持按访问频度非增（递减）的顺序排列，同时最近访问的结点排
在频度相同的结点的前边，以使频繁访问的结点总是靠近表头，试编写满足上述要求的Locate(L，x)函数，返回值为查找到的结点的地址，类型为指针。
    算法思想：找到该结点，从链上摘下，寻找待插入位置，插入，返回
 */
#include <iostream>
using namespace std;

//有访问频度的双链表
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
    int freq;
} DNode, *DLinkList;

//创建带头结点的非循环双链表（从数组）
void buildList(DLinkList &L, int a[], int n)
{
    L = (DLinkList)malloc(sizeof(DNode));
    DNode *r = L; //r始终指向双链表最后一个结点
    L->next = L;
    L->prior = L;
    for (int i = 0; i < n; i++)
    {
        DNode *s = (DLinkList)malloc(sizeof(DNode));
        s->data = a[i];
        s->freq = 0;

        s->next = r->next; //双链表尾插法
        r->next->prior = s;
        s->prior = r;
        r->next = s;

        r = s; //r指向新的尾部结点
    }
    r->next = NULL;
}

//输出双链表结点访问频度
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
    while (p && p->data != x) //找到结点
        p = p->next;
    if (!p) //如果节点不存在返回NULL
        return NULL;
    else
    {
        p->freq++; //频度+1
        //将p结点摘下
        if (p->next) //如果p是最后一个结点，则不用设置其后继结点prior指针
            p->next->prior = p->prior;
        p->prior->next = p->next;

        q = L;
        while (q->next->freq > p->freq) //从头扫描链表，寻找p待插入位置
            q = q->next;

        p->next = q->next; //插入该存放的位置
        q->next->prior = p;
        q->next = p;
        p->prior = q;
        return p; //返回p指针
    }
}

int main()
{
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};
    DLinkList L;
    buildList(L, a, n);
    cout << "查找前的双链表结点访问频度:";
    display_freq(L);
    int x;
    while (1)
    {
        cout << "请输入要查找的值：";
        cin >> x;
        DNode *p = Locate(L, x);
        if (p)
            cout << "查找成功！" << endl;
        else
            cout
                << "查找失败！" << endl;
        cout << "查找后的双链表结点访问频度:";
        display_freq(L);
        cout << endl;
    }

    return 0;
}