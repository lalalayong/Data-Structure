/* 
    ��֪һ�Ŷ�������˳��洢�ṹ���д洢�����һ���㷨�����ŷֱ�Ϊi��j��������������Ĺ������ȵ�ֵ��
 */
#include <iostream>
using namespace std;

struct tree
{
    int data[12] = {-1, 1, 2, 3, -1, 4, -1, 5, -1, -1, 6, -1};
};

int comm(tree t, int i, int j)
{
    if (t.data[i] != -1 && t.data[j] != -1)
    {
        while (i != j)
        {
            if (i > j)
                i = i / 2;
            else
                j = j / 2;
        }
        return t.data[i];
    }
    return -1;
}

int main()
{
    tree t;
    int ans = comm(t, 7, 10);
    cout << ans << endl;
    return 0;
}
