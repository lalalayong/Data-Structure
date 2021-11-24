/* 
    编写一个算法，找出一个数组中第k小的元素（从小到大排序后处于第k个位置的元素）
    算法思想：一、直接对数组从小到大排序，然后取第k个元素，时间复杂度O(nlogn)
            二、从数组中选择枢轴进行和快速排序一样的划分操作后，表A[]被划分为A[0，m-1]和A[m+1，n]，A[m]=pivot
            判断m和k的大小
                    m=k，直接返回A[pivot]
                    m>k,所要寻找的元素一定落在A[0，m-1]，对A[0，m-1]进行递归寻找
                    m<k,所要寻找的元素一定落在A[m+1，n]]，对A[m+1，n]进行递归寻找
                该算法平均时间复杂度O(n).
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
    cout << "请输入要查找第几小的元素";
    cin >> k;
    int ans = kth_elem(A, 0, n - 1, k-1);
    cout << "第" << k << "小的元素为" << ans << endl;
    return 0;
}