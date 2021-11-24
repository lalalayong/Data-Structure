/* 
    2012统考
    假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的后缀存储空间，例如loading和being。设str1和str2分别指向两个单链表的头结点，设计一个
时间上尽可能高效的算法，找出两个单链表共同后缀的起始位置（指针相同）。
    算法思想：1.分别求出两个链表的长度m，n
            2.将两个链表尾部对齐，即长的链表先走链表差值步数，使p，q所指结点到链表尾部的长度相同，
            3.将p，q同步后移，直到p，q指向同一个位置，结束，返回。
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *LinkList;

//尾插法建立单链表(从数组)
void buildList(LinkList L, char A[], int n)
{
    //带头节点
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
//显示单链表
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
    int len1 = listLength(str1); //求两链表长度
    int len2 = listLength(str2);
    if (len1 > len2) //长的链表先走差值个步数
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
    while (p->next && p->next->data != q->next->data) //将指针p，q同步后移
    {
        p = p->next;
        q = q->next;
    }
    return p->next; //返回共同后缀的起始地址
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
        cout << "第一个共同后缀位置：" << p->data << endl;
    }
    else
    {
        cout << "无共同后缀" << endl;
    }
    return 0;
}