/*
    ����������˳���ϲ���һ���µ�����˳������ɺ������ؽ��˳���
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

typedef struct
{
    int data[Maxsize];
    int length;
} Sqlist;

bool merge(Sqlist A, Sqlist B, Sqlist &C)
{
    int i = 0, j = 0, k = 0;
    if (A.length + B.length > C.length)
    {
        return false;
    }
    while (i < A.length && j < B.length)
    {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
    {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length)
    {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
    return true;
}

int main()
{
    Sqlist A = {{2, 3, 4, 6, 7}, 5};
    Sqlist B = {{3, 4, 4}, 3};
    Sqlist C;
    C.length = 8;
    cout << "A��";
    for (int i = 0; i < A.length; i++)
        cout << A.data[i] << " ";
    cout << endl;
    cout << "B��";
    for (int i = 0; i < B.length; i++)
        cout << B.data[i] << " ";
    cout << endl;
    if (merge(A, B, C))
    {
        cout << "�ϲ����C��";
        for (int i = 0; i < C.length; i++)
            cout << C.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "����" << endl;
    }
    return 0;
}