/*
    堆排序
*/
#include <bits/stdc++.h>
using namespace std;

//将元素k为根的子树向下调整
void HeapAdjust(int A[], int k, int len)
{
    A[0] = A[k]; //元素k暂存到A[0]
    for (int i = 2 * k; i <= len; i *= 2) //从k的子节点2*k和2*k+1进行筛选
    {
        if (i < len && A[i] < A[i + 1]) //找到k的较大的子节点
            i++;
        if (A[0] < A[i]) //如果该子节点大于元素k
        {
            A[k] = A[i]; //则将A[i]调整到双亲节点上
            k = i; //修改k值，进行下一次循环调整
        }
        else //筛选结束
        {
            break; 
        } 
    }
    A[k] = A[0]; //将元素k放入最终位置
}

//构造初始堆
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; --i) //从len/2到1反复调整堆
    {
        HeapAdjust(A, i, len);
    }
}

//堆排序主函数
void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len); //建立初始大根堆

    for (int i = len; i > 0; --i) //每次选出一个最大值（堆顶）
    {
        //将堆顶元素与堆底元素交换（最大值到尾部）
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        //调整堆
        HeapAdjust(A, 1, i - 1);
    } //最终得到一个递增序列
}

int main()
{
    int A[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //数组第一个位置不存放元素，用作哨兵
    int len = 8;
    cout << "排序前数组为：";
    for (int i = 1; i <= len; i++)
        cout << A[i] << " ";
    cout << endl;

    HeapSort(A, len);

    cout << "排序后数组为：";
    for (int i = 1; i <= len; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}