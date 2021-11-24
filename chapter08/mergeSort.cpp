/*
    归并排序
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

//辅助数组B
// int *B=new int[Maxsize];
int *B = (int *)malloc((Maxsize) * sizeof(int));

void Merge(int A[], int low, int mid, int high)
{
    /* 
        表A的两段各自有序：
            low-mid：左表
            mid+1-high：右表
        本函数将左右表归并
     */
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k]; //将表A的元素全部复制到表B
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j]) //比较B的左右两段中的元素
            A[k] = B[i++]; //将较小的值复制到A中
        else
            A[k] = B[j++];
    }
    while (i <= mid) //左表有剩余，直接复制到A
        A[k++] = B[i++];
    while (j <= high) //右表有剩余，直接复制到A
        A[k++] = B[j++];
}

//归并排序主函数
void MergeSort(int A[], int low, int high)
{
    if (low < high) //递归跳出的条件
    {
        int mid = (low + high) / 2; //从中间划分成两个表
        MergeSort(A, low, mid);  //递归对左表排序
        MergeSort(A, mid + 1, high); //递归对右表排序
        Merge(A, low, mid, high);  //将左右表归并
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

    MergeSort(A, 0, n - 1);

    cout << "排序后数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}