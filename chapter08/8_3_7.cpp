/* 
    ���������⣺��һ���ɺ����������ɫ��ɵ��������У���дһ��ʱ�临�Ӷ�ΪO(n)���㷨��ʹ����Щ���鰴�졢�ס�����˳���źã����ųɺ�������ͼ����
    �㷨˼�룺˳��ɨ�����Ա�����ɫ���齻�������Ա���ǰ�棬����ɫ���齻�������Ա����ߣ�
    ��������ָ�룬jΪ����ָ�룬��ʾ��ǰɨ���Ԫ�أ�i��ǰ��Ԫ�ض�Ϊ��ɫ��k�Ժ��Ԫ�ض�Ϊ��ɫ��
 */
#include <iostream>
using namespace std;

typedef enum
{
    RED,
    WHITE,
    BLUE
} color; //����ö������

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void flag_Arrange(color A[], int n)
{
    int i = 0, j = 0, k = n - 1; 
    while (j <= k)
    {
        switch (A[j]) //�ж�������ɫ
        {
        case RED: //��ɫ�����i������֮��i++��j++
            swap(A[i], A[j]);
            i++;
            j++;
            break;
        case WHITE: //��ɫ��������j++
            j++;
            break;
        case BLUE: //��ɫ����k������k--
            swap(A[j], A[k]);
            k--; //����û��j++����ֹ�����Ժ���ȻΪ��ɫ�����
            break;
        }
    }
}

int main()
{
    color A[] = {WHITE, BLUE, WHITE, RED, BLUE, WHITE, RED, BLUE, WHITE, RED};
    int n = 10;
    flag_Arrange(A, n);
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
            cout << "RED ";
        if (A[i] == 1)
            cout << "WHITE ";
        if (A[i] == 2)
            cout << "BLUE ";
    }
    cout << endl;
    return 0;
}