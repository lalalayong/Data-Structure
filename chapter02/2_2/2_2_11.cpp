/* 
    2011ͳ����
    �������ȳ����������У��ҳ����ǵ���λ����λ�ڵ�n/2����ȡ��λ�õ�Ԫ�أ���
    �㷨˼�룺
        1.�Ⱥϲ���Ȼ���ҵ���λ������
        2.�Ľ��棺�ϲ���ʱ��ֻ��k���������ϲ�Ԫ�أ���k����n/2ʱ����Ҫ�ҵ���λ��
                ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
 */
#include <iostream>
using namespace std;

int M_Search(int A[], int B[], int n)
{
    //�޸ĺ�ĺϲ�����
    int i = 0, j = 0, k = 0; //k�����ϲ�������г��ȣ�����n/2ʱ�㷵��
    while (i < n && j < n)
    {
        if (A[i] <= B[j])
        {
            if (k == (2 * n - 1) / 2) //ֻ�жϣ����ϲ�
                return A[i];
            k++;
            i++;
        }
        else
        {
            if (k == (2 * n - 1) / 2)
                return B[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        if (k == (2 * n - 1) / 2)
            return A[i];
        k++;
        i++;
    }
    while (j < n)
    {
        if (k == (2 * n - 1) / 2)
            return B[j];
        k++;
        j++;
    }
    return -1;
}

int main()
{
    int A[5] = {11, 13, 15, 17, 19};
    int B[5] = {2, 4, 6, 8, 20};
    int n = 5;
    cout << "����A��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "����B��";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << endl;
    int ans = M_Search(A, B, n);
    if (ans == -1)
    {
        cout << "����" <<endl;
    }
    else
    {
        cout << "A��B����λ��Ϊ��" << ans << endl;
    }
    return 0;
}