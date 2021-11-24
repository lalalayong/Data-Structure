/* 
    已知在一个数组A[m+n]中一次存放两个线性表（a1-am）（b1-bn），编写一个函数将两个线性表位置互换，即将（b1-bn）放在（a1-am）的前面。
    算法思想：先将整体逆置，再将前n个元素和后m个元素各自逆置即得到想要的结果。
 */
#include <iostream>
using namespace std;
//逆置函数
void reverse(int A[], int left, int right, int size)
{
    if (left >= right || right >= size)
        return;
    int mid = (left + right) / 2;
    for (int i = left; i <= mid; i++)
    {
        int temp = A[i];
        A[i] = A[left + right - i];
        A[left + right - i] = temp;
    }
}

void exchange(int A[], int m, int n, int size)
{
    reverse(A, 0, m + n - 1, size);
    reverse(A, 0, n - 1, size);
    reverse(A, n, m + n - 1, size);
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;
    int m = 3, n = 5;
    cout << "逆置前：";
    for (int i = 0; i < n + m; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "前" << m << "个元素：";
    for (int i = 0; i < m; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "后" << n << "个元素：";
    for (int i = m; i < n + m; i++)
        cout << A[i] << " ";
    cout << endl;
    exchange(A, m, n, size);
    cout << "逆置后：";
    for (int i = 0; i < n + m; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
