/*
    �ж�һ�������Ƿ���С����
*/
#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(int A[], int len)
{
    if (len % 2 == 0) //lenΪż������һ������֧���
    {
        if (A[len / 2] > A[len]) //�жϵ���֧���
            return false;
        for (int i = len / 2 - 1; i >= 1; i--) //�ж�����˫��֧���
        {
            if (A[i] > A[i * 2] || A[i] > A[i * 2 + 1])
                return false;
        }
    }
    else //lenΪ����ʱ��û�е���֧���
    {
        for (int i = len / 2; i >= 1; i--) //�ж�����˫��֧���
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
    cout << "���У�";
    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
    if (isMinHeap(A, len))
    {
        cout << "��С���ѣ�";
    }
    else
    {
        cout << "����С���ѣ�";
    }

    return 0;
}