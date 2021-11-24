/* 
    荷兰旗问题：有一个由红白蓝三种颜色组成的条块序列，编写一个时间复杂度为O(n)的算法，使得这些条块按红、白、蓝的顺序排好，即排成荷兰国旗图案。
    算法思想：顺序扫描线性表，将红色条块交换到线性表最前面，将蓝色条块交换到线性表最后边，
    设立三个指针，j为工作指针，表示当前扫描的元素，i以前的元素都为红色，k以后的元素都为蓝色。
 */
#include <iostream>
using namespace std;

typedef enum
{
    RED,
    WHITE,
    BLUE
} color; //设置枚举数组

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
        switch (A[j]) //判断条块颜色
        {
        case RED: //红色，则和i交换，之后i++，j++
            swap(A[i], A[j]);
            i++;
            j++;
            break;
        case WHITE: //白色，不动，j++
            j++;
            break;
        case BLUE: //蓝色，和k交换。k--
            swap(A[j], A[k]);
            k--; //这里没有j++，防止交换以后仍然为蓝色的情况
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