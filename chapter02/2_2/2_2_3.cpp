/*
对长度为n的顺序表L，编写一个时间复杂度为O(n),空间复杂度为O(1)的算法，删除线性表中所有值为x的元素。
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

typedef struct
{
    int a[Maxsize] = {2, 1, 3, 1, 8, 1, 5, 9}; //线性表的元素
    int length = 8; //线性表长度
} Sqlist;

void deletex_1(Sqlist &L, int x)
{
    int j=0;
    for(int i=0;i<L.length;i++) //i一直走
    {
        if(L.a[i]!=x) //当值不等于x时j才走
        {
            L.a[j]=L.a[i]; 
            j++;
        }   
    }
    L.length=j;
}
void deletex_2(Sqlist &L, int x)
{
    int k=0;  //k统计值为x的元素个数
    for(int i=0;i<L.length;i++) 
    {
        if(L.a[i]==x)
        {
            k++;
        }
        else
        {
            L.a[i-k]=L.a[i];  //当前元素前移k个位置
        }
    }
    L.length-=k;  //修改顺序表长度
}

int main()
{
    Sqlist L;
    int x;
    cout << "删除前的顺序表为：";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    cout << "请输入你要删除的元素值：";
    cin>>x;

    deletex_1(L,x);

    cout << "删除后的顺序表为：";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    return 0;
}