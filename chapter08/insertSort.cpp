/*
    ֱ�Ӳ�������
*/
#include <bits/stdc++.h>
using namespace std;

void InsertSort(int A[], int n)
{
    //�����ڱ�
    int i, j,temp;
    for (i = 1; i < n; i++) //���ν�A[1]��A[n-1]����ǰ������������
    {
        if (A[i] < A[i - 1]) //A[i]С����ǰ��ʱ�Ž��в��룬���򲻶�
        {
            temp = A[i];
            for (j = i - 1;j>=0 && A[j] > temp; --j) //�Ӻ���ǰ���Ҳ���λ��
                A[j + 1] = A[j]; //���κ���
            A[j + 1] = temp; //����λ��
        }
    }
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    cout << "����ǰ����Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    InsertSort(A, n);

    cout << "���������Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}