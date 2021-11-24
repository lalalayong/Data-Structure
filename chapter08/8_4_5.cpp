/*
    判断一个序列是否是小根堆
*/
#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(int A[], int len)
{
    if (len % 2 == 0) //len为偶数，有一个单分支结点
    {
        if (A[len / 2] > A[len]) //判断单分支结点
            return false;
        for (int i = len / 2 - 1; i >= 1; i--) //判断所有双分支结点
        {
            if (A[i] > A[i * 2] || A[i] > A[i * 2 + 1])
                return false;
        }
    }
    else //len为奇数时，没有单分支结点
    {
        for (int i = len / 2; i >= 1; i--) //判断所有双分支结点
        {
            if (A[i] > A[i * 2] || A[i] > A[i * 2 + 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int A[] = {13, 27, 38, 49, 49, 65, 76, 97};
    int len = 8;
    cout << "序列：";
    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
    if (isMinHeap(A, len))
    {
        cout << "是小根堆！";
    }
    else
    {
        cout << "不是小根堆！";
    }

    return 0;
}