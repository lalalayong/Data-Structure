/*
    简单选择排序
*/
#include <bits/stdc++.h>
using namespace std;

void SelectSort(int A[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i; //记录最小元素位置
        for(int j=i+1;j<n;j++) //在A[i]到A[n-1]中选取最小的元素
        {
            if(A[j]<A[min])
                min=j; //更新最小元素位置
        }
        if(min!=i){ //将最小元素交换到前边
            int temp=A[i];
            A[i]=A[min];
            A[min]=temp;
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

    SelectSort(A, n);

    cout << "排序后数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}