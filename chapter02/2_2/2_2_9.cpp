/* 
    ���Ա�Ԫ�ص���������˳��洢�����һ���㷨��ʹ������ʱ���ڱ��в�����ֵΪx��Ԫ�أ����ҵ��������ĺ�̽�������δ�ҵ������Ӧ�ò����λ�ã�ʹ��˳�����Ȼ��������
 */
#include <iostream>
using namespace std;

#define Max 50

typedef struct
{
    int data[Max] = {1,2,3,4,5,6,7,8}; //���Ա��Ԫ��
    int length = 8;                           //���Ա���
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
    cout << "����ǰ��";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    searchExchangeInsert(L, x);
    cout << "���Һ�";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    return 0;
}