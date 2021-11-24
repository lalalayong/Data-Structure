/* 
    随机选择枢轴元素的快速排序。
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
//划分函数
int Partition(int A[], int low, int high) //一趟划分
{
    int rand_index = low+rand()%(high-low+1); //产生随机数作为枢轴
    swap(A[rand_index],A[low]); //将枢轴与A[low]交换

    //下面执行快排划分算法
    int pivot = A[low]; //将表中的第一个元素设置为枢轴
    while (low < high)  //循环跳出条件
    {
        while (low < high && A[high] >= pivot)
            high--; //找到比枢轴小的元素
        A[low] = A[high]; //移动到左端
        while (low < high && A[low] <= pivot)
            low++; //找到比枢轴大的元素
        A[high] = A[low]; //移动到又端
    } //循环结束后low=high
    A[low] = pivot; //low和high的位置即为枢轴元素的最终位置
    return low; //返回存放枢轴元素的位置
}

//快速排序主函数
void QuickSort(int A[], int low, int high)
{
    if (low < high) //递归跳出的条件
    {
        int pos = Partition(A, low, high); //划分
        QuickSort(A, low, pos - 1);        //递归对两个子表进行快速排序
        QuickSort(A, pos + 1, high);
    }
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    cout << "排序前数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    QuickSort(A, 0, n - 1);

    cout << "排序后数组为：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}