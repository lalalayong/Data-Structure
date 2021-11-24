/*
逆置顺序表L的所有元素，要求空间复杂度为 O(1)
*/
#include <bits/stdc++.h>
using namespace std;

#define Max 50

typedef struct
{
    int a[Max] = {2, 1, 3, 6, 8, 7, 5, 9}; //线性表的元素
    int length = 8;                        //线性表长度
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
    cout << "逆置前的顺序表为：";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    reverse(L);

    cout << "逆置后的顺序表为：";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;

    return 0;
}
