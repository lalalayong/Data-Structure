/*
    直接插入排序
*/
#include <bits/stdc++.h>
using namespace std;

void InsertSort(int A[], int n)
{
    //不带哨兵
    int i, j,temp;
    for (i = 1; i < n; i++) //依次将A[1]到A[n-1]插入前面已排序序列
    {
        if (A[i] < A[i - 1]) //A[i]小于其前驱时才进行插入，否则不动
        {
            temp = A[i];
            for (j = i - 1;j>=0 && A[j] > temp; --j) //从后往前查找插入位置
                A[j + 1] = A[j]; //依次后移
            A[j + 1] = temp; //插入位置
        }
    }
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    cout << "排序前数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    InsertSort(A, n);

    cout << "排序后数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}