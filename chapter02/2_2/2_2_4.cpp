/*
    ��˳���(����)��ɾ����ֵ�ڸ���ֵs��t��s<t��֮�������Ԫ�أ���s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

typedef struct
{
    int data[Maxsize] = {1, 2, 3, 4, 5, 6, 7, 8}; //���Ա��Ԫ��
    int length = 8;                               //���Ա���
} Sqlist;

bool Del_s_t(Sqlist &L, int s, int t)
{
    int i, j = 0;
    if (s >= t || L.length == 0)
        return false;
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ;
    if (i >= L.length)
        return false;
    for (j = 0; j < L.length && L.data[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}

int main()
{
    Sqlist L;
    int s, t;
    cout << "ɾ��ǰ��˳���Ϊ��";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    cout << "��������Ҫɾ����s��tֵ��";
    cin >> s >> t;
    // cin>>t;

    if (Del_s_t(L, s, t))
    {
        cout << "ɾ���ɹ���" << endl;
        cout << "ɾ�����˳���Ϊ��";
        for (int i = 0; i < L.length; i++)
            cout << L.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "ɾ��ʧ�ܣ�" << endl;
    }

    return 0;
}