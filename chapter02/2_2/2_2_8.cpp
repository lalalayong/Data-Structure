/* 
    ��֪��һ������A[m+n]��һ�δ���������Ա�a1-am����b1-bn������дһ���������������Ա�λ�û�����������b1-bn�����ڣ�a1-am����ǰ�档
    �㷨˼�룺�Ƚ��������ã��ٽ�ǰn��Ԫ�غͺ�m��Ԫ�ظ������ü��õ���Ҫ�Ľ����
 */
#include <iostream>
using namespace std;
//���ú���
void reverse(int A[], int left, int right, int size)
{
    if (left >= right || right >= size)
        return;
    int mid = (left + right) / 2;
    for (int i = left; i <= mid; i++)
    {
        int temp = A[i];
        A[i] = A[left + right - i];
        A[left + right - i] = temp;
    }
}

void exchange(int A[], int m, int n, int size)
{
    reverse(A, 0, m + n - 1, size);
    reverse(A, 0, n - 1, size);
    reverse(A, n, m + n - 1, size);
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;
    int m = 3, n = 5;
    cout << "����ǰ��";
    for (int i = 0; i < n + m; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "ǰ" << m << "��Ԫ�أ�";
    for (int i = 0; i < m; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "��" << n << "��Ԫ�أ�";
    for (int i = m; i < n + m; i++)
        cout << A[i] << " ";
    cout << endl;
    exchange(A, m, n, size);
    cout << "���ú�";
    for (int i = 0; i < n + m; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
