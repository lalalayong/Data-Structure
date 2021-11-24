/* 
    线性表元素递增有序且顺序存储，设计一个算法，使用最少时间在表中查找数值为x的元素，若找到则与他的后继交换，若未找到则插入应该插入的位置，使得顺序表依然递增有序
 */
#include <iostream>
using namespace std;

#define Max 50

typedef struct
{
    int data[Max] = {1,2,3,4,5,6,7,8}; //线性表的元素
    int length = 8;                           //线性表长度
} Sqlist;

void searchExchangeInsert(Sqlist &L, int x)
{
    int low = 0, high = L.length - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] == x)
            break;
        else if (L.data[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (L.data[mid] == x && mid != L.length - 1)
    {
        int temp = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = temp;
    }
    if (low > high)
    {
        int i;
        for (i = L.length - 1; i > high; i--)
            L.data[i + 1] = L.data[i];
        L.data[i + 1] = x;
    }
}

int main()
{
    Sqlist L;
    int x = 2;
    cout << "查找前：";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    searchExchangeInsert(L, x);
    cout << "查找后：";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    return 0;
}