/* 
    ���һ���ǵݹ��㷨��������ĸ߶ȡ�
 */
#include <iostream>
using namespace std;
#define Maxsize 50

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

//�ǵݹ���������߶�
int BTdepth(BiTree T)
{
    if (!T) 
        return 0; //���գ��߶�Ϊ0
    int front = -1, rear = -1;
    int last = 0; //lastָ��ǰ������ҽ�㣨ÿ��ķֽ�㣩
    int level = 0;
    BiTree Q[Maxsize]; //���ö���Q
    Q[++rear] = T;     //���ڵ����
    BiTree p;
    while (front < rear) //���в�Ϊ�գ���ѭ��
    {
        p = Q[++front]; //��ͷԪ�س���
        if (p->lchild)  //�������
            Q[++rear] = p->lchild;
        if (p->rchild) //�Һ������
            Q[++rear] = p->rchild;
        if (front == last) //�������˸ò����һ�����
        {
            level++;     //����+1
            last = rear; //lastָ����һ������ҽڵ�
        }
    }
    return level;
}

//�ݹ���������߶�
int BTdepth_1(BiTree T){
    if(!T)
        return 0;
    int ldepth=BTdepth_1(T->lchild);
    int rdepth=BTdepth_1(T->rchild);
    return ldepth>rdepth?ldepth+1:rdepth+1;
}

int main()
{
    BiTree T;
    cout << "������һ�Ŷ�����������:";
    creatBiTree(T);
    int depth = BTdepth_1(T);
    cout << "�ö������ĸ߶�Ϊ��" << depth << endl;
    return 0;
}
//ABD##E##CF##G##
/* 
                A
              /   \
            B       C
          /  \     /  \
         D    E   F    G
 */