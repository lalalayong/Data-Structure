/*
    ð������
*/
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int A[], int n)
{
    //СԪ����ǰð�ݣ��ųɵ�������
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        bool flag = false; //��¼һ�������Ƿ�������
        for (j = n - 1; j > i; j--) //һ��ð�ݹ���
        {
            if (A[j - 1] > A[j]) //��Ԫ��С��ǰһ��Ԫ�أ��򽻻���ð�ݵ�ǰ�棩
            {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                flag = true; //������������¼
            }
        }
        if (flag == false) //����������û�з���������˵��������ɣ�����ǰ�˳�
            return;
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

    BubbleSort(A, n);

    cout << "���������Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}