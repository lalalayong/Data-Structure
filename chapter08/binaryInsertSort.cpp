/*
    �۰��������
*/
#include <bits/stdc++.h>
using namespace std;

void binaryInsertSort(int A[], int n)
{
    //���ڱ�
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) //���ν�A[2]��A[n]����ǰ������������
    {
        A[0] = A[i]; //��A[i]�ݴ浽A[0]
        low = 1;
        high = i - 1;
        while (low <= high) //�۰����Ҫ�����λ��
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
                high = mid - 1;
            else
                low = mid + 1;
        } //����ͣ��low=high+1��
        for (j = i - 1; j >= low; --j)
            A[j + 1] = A[j];
        A[low] = A[0]; //low��ΪҪ�����λ��
    }
}

int main()
{
    int A[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //�����һ��λ�ò����Ԫ�أ������ڱ�
    int n = 8;
    cout << "����ǰ����Ϊ��";
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;

    binaryInsertSort(A, n);

    cout << "���������Ϊ��";
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}