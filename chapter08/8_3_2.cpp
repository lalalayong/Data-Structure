/* 
    双向冒泡排序算法
 */
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int A[], int n)
{
    int low = 0, high = n - 1;
    bool flag = true; //记录一趟排序是否发生交换
    int i, j;
    while (low < high && flag) //循环跳出条件，若哦flag=false说明已经排序完成
    {
        flag = false;  //每趟初始置flag为false
        for (i = low; i < high; i++) //从前向后起泡
        {
            if (A[i] > A[i + 1])  //发生逆序
            {
                int temp = A[i + 1]; //交换
                A[i + 1] = A[i];
                A[i] = temp;
                flag = true; //发生交换，置flag
            }
        }
        high--; //更新上界
        for (j = high; j > low; j--) //从后向前起泡
        {
            if (A[j] < A[j - 1]) //发生逆序
            {
                int temp = A[j - 1]; //交换
                A[j - 1] = A[j];
                A[j] = temp;
                flag = true; //置flag
            }
        }
        low++; //更新下界
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