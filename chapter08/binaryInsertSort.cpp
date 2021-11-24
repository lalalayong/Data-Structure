/*
    折半插入排序
*/
#include <bits/stdc++.h>
using namespace std;

void binaryInsertSort(int A[], int n)
{
    //带哨兵
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) //依次将A[2]到A[n]插入前面已排序序列
    {
        A[0] = A[i]; //将A[i]暂存到A[0]
        low = 1;
        high = i - 1;
        while (low <= high) //折半查找要插入的位置
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
                high = mid - 1;
            else
                low = mid + 1;
        } //最终停在low=high+1，
        for (j = i - 1; j >= low; --j)
            A[j + 1] = A[j];
        A[low] = A[0]; //low即为要插入的位置
    }
}

int main()
{
    int A[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //数组第一个位置不存放元素，用作哨兵
    int n = 8;
    cout << "排序前数组为：";
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;

    binaryInsertSort(A, n);

    cout << "排序后数组为：";
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}