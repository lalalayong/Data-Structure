/*
    ϣ������
*/
#include <bits/stdc++.h>
using namespace std;

void ShellSort(int A[], int n)
{
    //�����ڱ�
    int i, j,temp;
    int dk; //����
    for (dk = n / 2; dk >= 1; dk = dk / 2) //�����仯
    {
        for (i = dk; i < n; i++) //����ִ�и����ӱ�
        {
            if (A[i] < A[i - dk]) //�轫A[i]��������������ӱ�
            {
                temp = A[i]; //�ݴ�A[i]
                for (j = i - dk; j >= 0 && A[j] > temp; j=j-dk) //�Ӻ���ǰ���Ҳ���λ��
                    A[j + dk] = A[j];                        //���κ���
                A[j + dk] = temp;                            //����λ��
            }
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

    ShellSort(A, n);

    cout << "���������Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}