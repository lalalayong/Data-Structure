/* 
    ��֪���Ա�˳��洢����ÿ��Ԫ�ز�ͬ������㷨�����е������ƶ������е�ż��ǰ��
    �㷨˼�룺���ÿ��ŵ�˼�룬�Ӻ���ǰ�ҵ�һ����������ǰ�����ҵ�һ��ż��������������Ԫ�أ��ظ��˹��̣�ֱ��i>j��
 */

#include <bits/stdc++.h>
using namespace std;

void move(int A[], int n)
{
    int i = 0, j = n - 1;
    while (i < j) //ѭ��������������Ŷflag=false˵���Ѿ��������
    {
        while (i < j && A[j] % 2 == 0)
            --j; //�Ӻ���ǰ�ҵ�һ������
        while (i < j && A[i] % 2 != 0)
            i++; //��ǰ�����ҵ�һ��ż��
        if (i < j)
        { //����������Ԫ��
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }
}

int main()
{
    int A[] = {4, 3, 6, 9, 7, 1, 2, 8};
    int n = 8;
    cout << "�ƶ�ǰ����Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    move(A, n);

    cout << "�ƶ�������Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}