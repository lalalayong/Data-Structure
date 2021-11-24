/* 
    ��ROOTΪ���������ڵ�ָ�룬p��qΪָ��������������ָ�룬�Ա�д�㷨Ancestor(ROOT,p,q,r)���ҵ�p��q������������Ƚ��r��
    �㷨˼��:���ú���ǵݹ�����㷨�������ʵ�ĳ���ʱ��ս������Ԫ��Ϊ�ý������ȡ������ʵ�p��qʱ����ջ���Ƶ���һ����ջ�����Ҽ����������ȱ�����p��q����һ�����ʱ��
����ǰջ�еĽ���븨��ջ�н��ȥƥ�䣬��һ��ƥ���Ԫ�ؾ���p��q������������Ƚ�㡣
 */
#include <iostream>
using namespace std;
#define Maxsize 50
#define elemtype BiTree

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
    int tag;
} BiTNode, *BiTree;

//�ݹ齨��������������
void creatBiTree(BiTree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (BiTNode *)malloc(sizeof(BiTNode));
        t->data = ch;
        t->tag = 0;
        t->lchild = NULL;
        t->rchild = NULL;
        creatBiTree(t->lchild);
        creatBiTree(t->rchild);
    }
}
void disp(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        disp(T->lchild);
        disp(T->rchild);
    }
}

//----ջ------------------
typedef struct
{
    elemtype data[Maxsize];
    int top;
} stack1;

void InitStack(stack1 &s)
{
    s.top = -1;
}

bool isEmpty(stack1 s)
{
    if (s.top == -1)
        return true; //ջ��
    else
        return false;
}

bool isFull(stack1 s)
{
    if (s.top == Maxsize - 1)
        return true;
    else
        return false;
}
bool push(stack1 &s, elemtype x)
{
    if (isFull(s))
    {
        cout << "ջ������ջʧ�ܣ�" << endl;
        return false;
    }
    s.data[++s.top] = x; //ջ��ָ����+1������ջ
    return true;
}

bool pop(stack1 &s, elemtype &x)
{
    if (isEmpty(s))
    {
        cout << "ջ�գ���ջʧ�ܣ�" << endl;
        return false;
    }
    x = s.data[s.top--]; //��ȡջ��Ԫ�أ�����ջ��ָ��-1
    return true;
}

BiTNode *Ancestor(BiTree ROOT, BiTNode *p, BiTNode *q)
{
    int flag;
    BiTNode *t = ROOT;
    stack1 s, s1;
    InitStack(s);
    InitStack(s1);
    while (t || !isEmpty(s)) //����ĺ���ǵݹ��㷨
    {
        if (t) //�������ڣ���һֱ������
        {
            if (t == p || t == q) //�����Ϊp��q
            {
                //flag������¼�Ƿ��Ѿ�������p��q��p��qλ�ò�ȷ�����п���������p����������q��
                if (flag == 0) //��һ������p��q����sջ��Ԫ�ظ��Ƶ�����ջs1
                {
                    s1.top = s.top;
                    for (int i = s.top; i >= 0; i--)
                        s1.data[i] = s.data[i];
                    flag = 1; //��flagΪ1
                }
                else //������p��q�е�����һ����ֱ�ӽ�ջs��Ԫ���븨��ջs1��Ԫ�ؽ��бȽϣ�
                {
                    for (int i = s.top; i >= 0; i--)
                        for (int j = s1.top; j >= 0; j--)
                            if (s1.data[j] == s.data[i])
                                return s.data[i]; //��һ����ͬ�Ľ�㼴Ϊpq����������Ƚ��
                }
            }

            push(s, t);    //��ջ
            t = t->lchild; //������
        }
        else
        {
            t = s.data[s.top];
            if (t->rchild && t->rchild->tag == 0)
                t = t->rchild;
            else
            {
                pop(s, t);
                t->tag = 1;
                t = NULL;
            }
        }
    }
    return NULL;
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "��������";
    disp(T);
    cout << endl;
    BiTNode *p = T->rchild, *q = T->lchild->rchild, *r; //����p,q
    r = Ancestor(T, p, q);
    cout << p->data << "��" << q->data << "������������Ƚ��Ϊ��" << r->data << endl;
    return 0;
}
//��������
/* 
ABD##E##CF##G##
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */
/* 
ABD##E##C#G##
                A
              /   \
            B       C
          /  \        \
         D    E        G
 */
