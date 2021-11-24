/* 
    已知线性表按顺序存储，其每个元素不同，设计算法将所有的奇数移动到所有的偶数前面
    算法思想：利用快排的思想，从后往前找第一个奇数，从前往后找第一个偶数，交换这两个元素，重复此过程，直到i>j。
 */

#include <bits/stdc++.h>
using namespace std;

void move(int A[], int n)
{
    int i = 0, j = n - 1;
    while (i < j) //循环跳出条件，若哦flag=false说明已经排序完成
    {
        while (i < j && A[j] % 2 == 0)
            --j; //从后往前找第一个奇数
        while (i < j && A[i] % 2 != 0)
            i++; //从前往后找第一个偶数
        if (i < j)
        { //交换这两个元素
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }
}

int main()
{
    int A[] = {4, 3, 6, 9, 7, 1, 2, 8};
    int n = 8;
    cout << "移动前数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    move(A, n);

    cout << "移动后数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}