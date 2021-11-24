/* 
    2020ͳ����
    ������Ԫ�飨a,b,c���ľ���D=|a-b|+|b-c|+|c-a|,����3���ǿ���������S1��S2��S3��������洢��3�������У����һ�������ܸ�Ч���㷨�����㲢������п��ܵ���Ԫ��
�е���С���룬����S1={-1,0,9},S2={-25,-10,10,11},S3={2,9,17,30,41},����С����Ϊ2����Ӧ����Ԫ��Ϊ��9,10,9����
    �㷨˼�룺������,��S1,S2,S3���ȷֱ�Ϊn��ʱ�临�Ӷ�ΪO(n^3)
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
    cout << "��С����DΪ��" << ans << endl;
    return 0;
}