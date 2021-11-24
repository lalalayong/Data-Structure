/*
从线性表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值，空出的位置由最后一个元素填补，
若顺序表为空，则显示出错信息并退出运行。
*/
#include <bits/stdc++.h>
using namespace std;

#define Max 50

typedef struct
{
        int a[Max] = {2, 1, 3, 6, 8, 7, 5, 9};  //线性表的元素
        int length = 8; //线性表长度
} Sqlist;
bool listdelete(Sqlist &s, int &e)
{
        if (s.length == 0)
                return false;
        int min = s.a[0];
        int flag = 0;
        for (int i = 1; i < s.length; i++)
        {
                if (s.a[i] < min)
                {
                        min = s.a[i];
                        flag = i;
                }
        }
        e = min;
        s.a[flag] = s.a[s.length - 1];
        s.length--;
        return true;
}

int main()
{
        Sqlist s;
        cout << "删除前数组为：";
        for (int i = 0; i < s.length; i++)
                cout << s.a[i] << " ";
        cout << endl;
        int e = 0;
        if (listdelete(s, e))
        {
                cout << "最小值元素为：" << e << endl;

                cout << "删除后数组为：";
                for (int i = 0; i < s.length; i++)
                        cout << s.a[i] << " ";
                cout << endl;
        }
        else
        {
                cout << "删除错误！" << endl;
        }
        return 0;
}
