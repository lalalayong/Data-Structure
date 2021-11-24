/*
    希尔排序
*/
#include <bits/stdc++.h>
using namespace std;

void ShellSort(int A[], int n)
{
    //不带哨兵
    int i, j,temp;
    int dk; //步长
    for (dk = n / 2; dk >= 1; dk = dk / 2) //步长变化
    {
        for (i = dk; i < n; i++) //交替执行各个子表
        {
            if (A[i] < A[i - dk]) //需将A[i]插入其有序递增子表
            {
                temp = A[i]; //暂存A[i]
                for (j = i - dk; j >= 0 && A[j] > temp; j=j-dk) //从后往前查找插入位置
                    A[j + dk] = A[j];                        //依次后移
                A[j + dk] = temp;                            //插入位置
            }
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

    ShellSort(A, n);

    cout << "排序后数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}