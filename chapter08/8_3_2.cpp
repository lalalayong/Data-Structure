/* 
    ˫��ð�������㷨
 */
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int A[], int n)
{
    int low = 0, high = n - 1;
    bool flag = true; //��¼һ�������Ƿ�������
    int i, j;
    while (low < high && flag) //ѭ��������������Ŷflag=false˵���Ѿ��������
    {
        flag = false;  //ÿ�˳�ʼ��flagΪfalse
        for (i = low; i < high; i++) //��ǰ�������
        {
            if (A[i] > A[i + 1])  //��������
            {
                int temp = A[i + 1]; //����
                A[i + 1] = A[i];
                A[i] = temp;
                flag = true; //������������flag
            }
        }
        high--; //�����Ͻ�
        for (j = high; j > low; j--) //�Ӻ���ǰ����
        {
            if (A[j] < A[j - 1]) //��������
            {
                int temp = A[j - 1]; //����
                A[j - 1] = A[j];
                A[j] = temp;
                flag = true; //��flag
            }
        }
        low++; //�����½�
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