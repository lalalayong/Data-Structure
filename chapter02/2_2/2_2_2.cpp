/*
����˳���L������Ԫ�أ�Ҫ��ռ临�Ӷ�Ϊ O(1)
*/
#include <bits/stdc++.h>
using namespace std;

#define Max 50

typedef struct
{
    int a[Max] = {2, 1, 3, 6, 8, 7, 5, 9}; //���Ա��Ԫ��
    int length = 8;                        //���Ա���
} Sqlist;

void reverse(Sqlist &L)
{
    for (int i = 0; i <= L.length / 2; i++)
    {
        int t = L.a[i];
        L.a[i] = L.a[L.length - i - 1];
        L.a[L.length - i - 1] = t;
    }
}

int main()
{
    Sqlist L;
    cout << "����ǰ��˳���Ϊ��";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    reverse(L);

    cout << "���ú��˳���Ϊ��";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    return 0;
}
