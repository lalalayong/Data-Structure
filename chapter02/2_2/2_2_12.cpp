/* 
    2013统考:
    求整数序列的主元素：若一个元素在序列中出现次数大于一半，则称该元素为序列的主元素，若没有元素出现次数一半以上，则序列没有主元素，
设计一个尽可能高效的算法，求序列A的主元素，若存在主元素则输出，否则输出-1；
    算法思想：1.扫描数组，用一个辅助数组统计每个元素的个数，最后遍历辅助数组，选出个数最大的，判断个数是否超过一半。
            2.依次扫描数组，将第一个保存到c中，计数count=1，若下一个元素仍然是它，则count++，若不是，则count--，
            若count减到0.将下一个遇到的数存入c，计数重新为1，再次扫描数组，统计c的出现次数，判断是否为主元素。
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
    cout<<"序列：";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    int ans = Majority(A, n);
    if (ans>=0)
    {
        cout << "主元素为：" << ans << endl;
    }
    else
    {
        cout << "没有主元素" << endl;
    }
    return 0;
}