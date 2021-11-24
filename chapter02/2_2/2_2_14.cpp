/* 
    2020统考：
    定义三元组（a,b,c）的距离D=|a-b|+|b-c|+|c-a|,给定3个非空整数集合S1，S2，S3，按升序存储在3个数组中，设计一个尽可能高效的算法，计算并输出所有可能的三元组
中的最小距离，例如S1={-1,0,9},S2={-25,-10,10,11},S3={2,9,17,30,41},则最小距离为2，相应的三元组为（9,10,9）。
    算法思想：暴力法,设S1,S2,S3长度分别为n，时间复杂度为O(n^3)
 */
#include <iostream>
using namespace std;

int abs(int x)
{
    return x >= 0 ? x : -x;
}

int findMinD(int A[], int m, int B[], int n, int C[], int p)
{
    int D = 0, Min_D = INT_MAX;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < p; k++)
            {
                D = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k] - A[i]);
                if (D < Min_D)
                    Min_D = D;
            }
    return Min_D;
}

int main()
{
    int m = 3, n = 4, p = 5;
    int S1[m] = {-1, 0, 9};
    int S2[n] = {-25, -10, 10, 11};
    int S3[p] = {2, 9, 17, 30, 41};
    int ans = findMinD(S1, m, S2, n, S3, p);
    cout << "最小距离D为：" << ans << endl;
    return 0;
}