/* 
    ����һ��������������֪���������У����һ���㷨����������С�
 */
#include <iostream>
using namespace std;
#define Maxsize 50

void preTopost(char pre[], int l1, int h1, char post[], int l2, int h2)
{
    int half;
    if (h1 >= l1)
    {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        preTopost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        preTopost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
    }
}

int main()
{
    char pre[7] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
    cout << "��������:" << pre << endl;
    ;
    char post[Maxsize];
    preTopost(pre, 0, 6, post, 0, 6);
    cout << "��������:" << post << endl;
    ;
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
