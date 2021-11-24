/* 
    �������������������е�k������ֵ��
 */
#include <iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
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

static int i = 0;
static int a;
char findPre_K(BiTree T, int k)
{
    if (T)
    {
        if (++i == k)
        {
            a = T->data;
        }
        else
        {
            findPre_K(T->lchild, k);
            findPre_K(T->rchild, k);
        }
    }
    return a;
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "������:";
    disp(T);
    cout << endl;
    int k;
    cout << "������Ҫ�����������еڼ���ֵ:";
    cin >> k;
    char ans = findPre_K(T, k);
    cout << "�������е�" << k << "��ֵΪ��" << ans << endl;
    return 0;
}
/* 
ABD##E##CF##G##
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */