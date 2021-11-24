/* 
    ����������������й���һ�Ŷ�������
 */
#include <iostream>
using namespace std;
#define Maxsize 50

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int pos = 0;
BiTree build(char A[], char B[], int s, int e)
{
    if (s <= e)
    {
        BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
        root->data = A[pos]; //�������ڵ�
        int i;
        for (i = s; B[i] != root->data; i++) //�ҵ����ڵ������������е�λ��
            ;
        pos++;                                //ȫ�ֱ�����ָ����һ�������ĸ��ڵ㣬
        root->lchild = build(A, B, s, i - 1); //�ݹ齨��������
        root->rchild = build(A, B, i + 1, e); //�ݹ齨��������
        return root;                          //���ظ��ڵ�
    }
    return NULL; //��Ҷ���ʱ��ʼ����
}

void disp(BiTree T)
{
    if (T)
    {
        disp(T->lchild);
        disp(T->rchild);
        cout << T->data << " ";
    }
}
int main()
{
    int n = 6;
    char A[6] = {'A', 'B', 'D', 'E', 'C', 'F'}; //��������
    char B[6] = {'D', 'B', 'E', 'A', 'F', 'C'}; //��������
    BiTree T = build(A, B, 0, n - 1);
    cout << "��������Ϊ��";
    disp(T);
    return 0;
}