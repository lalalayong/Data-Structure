/* 
    将n个正整数构成的集合A划分为两个不相交的子集A1和A2，元素个数分别是n1和n2，A1和A2中的元素之和分别是s1和s2，
设计一个尽可能高效的划分算法，满足|n1-n2|最小并且|S1-S2|最大
    算法思想：由题意知，将最小的n/2个元素放在A1，其余的元素放在A2，即可满足要求，仿照快速排序的思想，基于枢轴划分为两个子集，
根据枢轴的位置i判断：
        若i=n/2，则分组完成，算法结束
        若i<n/2，则枢轴及其之前的所有元素都属于A1.继续对i之后的元素进行划分
        若i>n/2，则枢轴及其之后的所有元素都属于A2.继续对i之前的元素进行划分
    基于此算法无需对全部元素进行全排序，平均时间复杂度为O(n),空间复杂度为O(1)
 */
#include <iostream>
using namespace std;

int setPartition(int A[], int n)
{
    int low = 0,high = n - 1; //low和high为划分时的工作指针
    int low0 = 0, high0 = n - 1; //low0和high0暂存上下界，之后划分区间改变时会再次用到，
    int flag = 1;
    int k = n / 2;
    int s1 = 0, s2 = 0;
    while (flag)
    {
        int pivot = A[low]; //选择枢轴
        while (low < high) //基于枢轴进行划分
        {
            while (low < high && A[high] >= pivot)
                --high;
            A[low] = A[high];
            while (low < high && A[low] <= pivot)
                low++;
            A[high] = A[low];
        }
        A[low] = pivot;
        if(low=k-1) //若枢轴为第n/2个元素，划分完成
            flag=0;
        else{
            if(low<k){ //继续对low之后的元素进行划分
                low0=++low; //更新下界并保存，下一次划分结束可能又会用到该下界
                high=high0; //更新上界，下一次对新的low-high进行划分
            }
            else{
                high0=--low; //更新上界并保存，下一次划分结束可能又会用到该上界
                low=low0; //更新下界，下一次对新的low-high进行划分
            }
        }
    }
    for(int i=0;i<k;i++) 
        s1+=A[i];
    for(int j=k;j<n;j++)
        s2+=A[j];
    return s2-s1;
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    int ans = setPartition(A,n);
    cout<<"划分完成！"<<endl;
    cout << "S2-S1=" << ans << endl;
    return 0;
}