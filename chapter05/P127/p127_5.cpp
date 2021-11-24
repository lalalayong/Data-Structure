/* 
    已知一颗二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为i和j的两个结点的最近的公共祖先的值。
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
