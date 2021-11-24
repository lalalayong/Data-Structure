/*
    删除有序顺序表中重复的元素。
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

typedef struct
{
    int data[Maxsize] = {1, 2, 3, 3, 5, 5, 7, 8}; //线性表的元素
    int length = 8; //线性表长度
} Sqlist;

bool Del_Same(Sqlist &L){
    if(L.length==0)
        return false;
    int i,j;  //i存放第一个不相同的元素，j为工作指针
    for(i=0,j=1;j<L.length;j++)
    {
        if(L.data[i]!=L.data[j])  //查找与i不相同的元素，相同的元素则跳过
            L.data[++i]=L.data[j];  //不相同的元素向前覆盖
    }
    L.length=i+1;
    return true;
}

int main()
{
    Sqlist L;
    int s,t;
    cout << "删除前的顺序表为：";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout<<endl;

    if(Del_Same(L)){
        cout << "删除重复元素成功！！！";
        cout << "删除后的顺序表为：";
        for (int i = 0; i < L.length; i++)
            cout << L.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "删除失败！"<<endl;
    }

    return 0;
}