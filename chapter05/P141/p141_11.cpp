/* 
    ��дһ���㷨�����ڶ�������ÿһ��ֵΪx�Ľ�㣬ɾ������Ϊ�������������ͷ���Ӧ�ռ䡣
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

void deleteXTree(BiTree &T) //�ݹ�ɾ����TΪ��������
{
    if (T)
    {
        deleteXTree(T->lchild); //ɾ��T��������
        deleteXTree(T->rchild); //ɾ��T��������
        free(T);                //�ͷ�T�Ŀռ�
    }
}
//�ڶ������ϵݹ�Ѱ��������xΪԪ��ֵ�Ľ�㣬��ɾ������Ϊ��������
void searchDeleteX(BiTree T, char x)
{
    if (T)
    {
        if (T->data == x) //�����ڵ�Ϊx����ɾ��������
        {
            deleteXTree(T);
            exit(0); //�˳�
        }
        if (T->lchild && T->lchild->data == x) //��T�����Ӵ��ڣ��ҽ��ֵΪx
        {
            deleteXTree(T->lchild); //ɾ����T������Ϊ��������
            T->lchild = NULL;       //T�������ÿ�
        }
        else //���򣬵ݹ����T����������Ѱ��
        {
            searchDeleteX(T->lchild, x);
        }
        if (T->rchild && T->rchild->data == x) //��T���Һ��Ӵ��ڣ��ҽ��ֵΪx
        {
            deleteXTree(T->rchild); //ɾ����T���Һ���Ϊ��������
            T->rchild = NULL;       //T���Һ����ÿ�
        }
        else //���򣬵ݹ����T����������Ѱ��
        {
            searchDeleteX(T->rchild, x);
        }
    }
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    cout << "ɾ��ǰ�Ķ�������";
    disp(T);
    cout << endl;
    char x;
    cout << "������Ҫɾ������ֵ:";
    cin >> x;
    searchDeleteX(T, x);
    cout << "ɾ����Ķ�������";
    disp(T);
    cout << endl;

    return 0;
}
/* 
ABD##E##BF##G##
                A
              /   \
            B       B
          /  \     /  \
         D    E   F    G
 */