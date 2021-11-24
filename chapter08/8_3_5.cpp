/* 
    ��дһ���㷨���ҳ�һ�������е�kС��Ԫ�أ���С����������ڵ�k��λ�õ�Ԫ�أ�
    �㷨˼�룺һ��ֱ�Ӷ������С��������Ȼ��ȡ��k��Ԫ�أ�ʱ�临�Ӷ�O(nlogn)
            ������������ѡ��������кͿ�������һ���Ļ��ֲ����󣬱�A[]������ΪA[0��m-1]��A[m+1��n]��A[m]=pivot
            �ж�m��k�Ĵ�С
                    m=k��ֱ�ӷ���A[pivot]
                    m>k,��ҪѰ�ҵ�Ԫ��һ������A[0��m-1]����A[0��m-1]���еݹ�Ѱ��
                    m<k,��ҪѰ�ҵ�Ԫ��һ������A[m+1��n]]����A[m+1��n]���еݹ�Ѱ��
                ���㷨ƽ��ʱ�临�Ӷ�O(n).
 */
#include <iostream>
using namespace std;

int kth_elem(int A[], int low, int high, int k)
{
    int low_temp = low;
    int high_temp = high;
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    if (low == k)
        return A[low];
    else if (low > k)
    {
        return kth_elem(A, low_temp, low - 1, k);
    }
    else
    {
        return kth_elem(A, low + 1, high_temp, k);
    }
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    int k;
    cout << "������Ҫ���ҵڼ�С��Ԫ��";
    cin >> k;
    int ans = kth_elem(A, 0, n - 1, k-1);
    cout << "��" << k << "С��Ԫ��Ϊ" << ans << endl;
    return 0;
}