/* 
    2018统考：
    给定一个含n个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小整数，例如数组{-5,3,2,3}中未出现的最小正整数为1.{1,2,3}中未出现的最小正整数为4
    算法思想：分配一个标记数组用来记录A中是否出现了1-n的正整数，由于A中有n个整数，因此可能返回的值为1-n+1，当A中恰好是1-n时返回n+1，
        当A中出现了小于0或者大于n的值时，会导致1-n中出现空余位置，此时返回值在1-n之中，因此当A中出现了小于0或者大于n的值时，不用进行任何操作，
        最后遍历标记数组，找到第一个没标记的数即为未出现的最小整数。
 */
#include <iostream>
using namespace std;

int findMissMin(int A[], int n)
{
    int B[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
        {
            B[A[i]] = 1;
        }
    }
    int i;
    for (i = 1; i < n+1; i++)
    {
        if (B[i] == 0)
        {
            break;
        }
    }
    return i;
}

int main()
{
    int n = 4;
    int A[n] = {-5, 3, 2, 3};
    cout << "数组：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    int ans = findMissMin(A, n);
    cout << "未出现的最小整数为：" << ans << endl;
    return 0;
}