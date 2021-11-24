/*
    从顺序表(有序)中删除其值在给定值s到t（s<t）之间的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

typedef struct
{
    int data[Maxsize] = {1, 2, 3, 4, 5, 6, 7, 8}; //线性表的元素
    int length = 8;                               //线性表长度
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
    cout << "删除前的顺序表为：";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    cout << "请输入你要删除的s与t值：";
    cin >> s >> t;
    // cin>>t;

    if (Del_s_t(L, s, t))
    {
        cout << "删除成功！" << endl;
        cout << "删除后的顺序表为：";
        for (int i = 0; i < L.length; i++)
            cout << L.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "删除失败！" << endl;
    }

    return 0;
}