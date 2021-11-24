/*
    �鲢����
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

//��������B
// int *B=new int[Maxsize];
int *B = (int *)malloc((Maxsize) * sizeof(int));

void Merge(int A[], int low, int mid, int high)
{
    /* 
        ��A�����θ�������
            low-mid�����
            mid+1-high���ұ�
        �����������ұ�鲢
     */
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k]; //����A��Ԫ��ȫ�����Ƶ���B
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j]) //�Ƚ�B�����������е�Ԫ��
            A[k] = B[i++]; //����С��ֵ���Ƶ�A��
        else
            A[k] = B[j++];
    }
    while (i <= mid) //�����ʣ�ֱ࣬�Ӹ��Ƶ�A
        A[k++] = B[i++];
    while (j <= high) //�ұ���ʣ�ֱ࣬�Ӹ��Ƶ�A
        A[k++] = B[j++];
}

//�鲢����������
void MergeSort(int A[], int low, int high)
{
    if (low < high) //�ݹ�����������
    {
        int mid = (low + high) / 2; //���м仮�ֳ�������
        MergeSort(A, low, mid);  //�ݹ���������
        MergeSort(A, mid + 1, high); //�ݹ���ұ�����
        Merge(A, low, mid, high);  //�����ұ�鲢
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

    MergeSort(A, 0, n - 1);

    cout << "���������Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}