/* 
    2013ͳ��:
    ���������е���Ԫ�أ���һ��Ԫ���������г��ִ�������һ�룬��Ƹ�Ԫ��Ϊ���е���Ԫ�أ���û��Ԫ�س��ִ���һ�����ϣ�������û����Ԫ�أ�
���һ�������ܸ�Ч���㷨��������A����Ԫ�أ���������Ԫ����������������-1��
    �㷨˼�룺1.ɨ�����飬��һ����������ͳ��ÿ��Ԫ�صĸ������������������飬ѡ���������ģ��жϸ����Ƿ񳬹�һ�롣
            2.����ɨ�����飬����һ�����浽c�У�����count=1������һ��Ԫ����Ȼ��������count++�������ǣ���count--��
            ��count����0.����һ��������������c����������Ϊ1���ٴ�ɨ�����飬ͳ��c�ĳ��ִ������ж��Ƿ�Ϊ��Ԫ�ء�
 */
#include <iostream>
using namespace std;

int Majority(int A[], int n)
{
    int c, count = 1;
    c = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] == c)
            count++;
        else
        {
            if (count > 0)
                count--;
            else
            {
                c = A[i];
                count = 1;
            }
        }
    }
    if (count > 0)
        for (int i = count = 0; i < n; i++)
        {
            if (A[i] == c)
                count++;
        }
    if (count > n / 2)
        return c;
    else
        return -1;
}

int main()
{
    int n = 8;
    //int A[n] = {0,5,5,3,5,7,5,5};
    int A[n] = {0,5,5,3,5,1,5,7};
    cout<<"���У�";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    int ans = Majority(A, n);
    if (ans>=0)
    {
        cout << "��Ԫ��Ϊ��" << ans << endl;
    }
    else
    {
        cout << "û����Ԫ��" << endl;
    }
    return 0;
}