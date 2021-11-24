/*
    冒泡排序
*/
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int A[], int n)
{
    //小元素往前冒泡，排成递增序列
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        bool flag = false; //记录一趟排序是否发生交换
        for (j = n - 1; j > i; j--) //一趟冒泡过程
        {
            if (A[j - 1] > A[j]) //若元素小于前一个元素，则交换（冒泡到前面）
            {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                flag = true; //发生交换，记录
            }
        }
        if (flag == false) //若该趟排序没有发生交换，说明排序完成，则提前退出
            return;
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

    BubbleSort(A, n);

    cout << "排序后数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}