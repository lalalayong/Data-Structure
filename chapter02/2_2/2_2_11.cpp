/* 
    2011统考：
    给两个等长的升序序列，找出他们的中位数（位于第n/2向上取整位置的元素）。
    算法思想：
        1.先合并，然后找到中位数即可
        2.改进版：合并的时候只用k计数，不合并元素，当k到达n/2时便是要找的中位数
                时间复杂度为O(n),空间复杂度为O(1)
 */
#include <iostream>
using namespace std;

int M_Search(int A[], int B[], int n)
{
    //修改后的合并函数
    int i = 0, j = 0, k = 0; //k计数合并后的序列长度，到达n/2时便返回
    while (i < n && j < n)
    {
        if (A[i] <= B[j])
        {
            if (k == (2 * n - 1) / 2) //只判断，不合并
                return A[i];
            k++;
            i++;
        }
        else
        {
            if (k == (2 * n - 1) / 2)
                return B[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        if (k == (2 * n - 1) / 2)
            return A[i];
        k++;
        i++;
    }
    while (j < n)
    {
        if (k == (2 * n - 1) / 2)
            return B[j];
        k++;
        j++;
    }
    return -1;
}

int main()
{
    int A[5] = {11, 13, 15, 17, 19};
    int B[5] = {2, 4, 6, 8, 20};
    int n = 5;
    cout << "序列A：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "序列B：";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << endl;
    int ans = M_Search(A, B, n);
    if (ans == -1)
    {
        cout << "错误！" <<endl;
    }
    else
    {
        cout << "A和B的中位数为：" << ans << endl;
    }
    return 0;
}