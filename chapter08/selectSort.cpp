/*
    ��ѡ������
*/
#include <bits/stdc++.h>
using namespace std;

void SelectSort(int A[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i; //��¼��СԪ��λ��
        for(int j=i+1;j<n;j++) //��A[i]��A[n-1]��ѡȡ��С��Ԫ��
        {
            if(A[j]<A[min])
                min=j; //������СԪ��λ��
        }
        if(min!=i){ //����СԪ�ؽ�����ǰ��
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
    cout << "����ǰ����Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    SelectSort(A, n);

    cout << "���������Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}