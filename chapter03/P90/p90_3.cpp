/* 
    利用一个栈实现以下递归函数的非递归计算。
    {   f1 = 1         ,n=0
    {   f2 = 2 * x     ,n=1
    {   fn=2 * x * f2 - 2 * (n - 1) * f1   ,n>1
 */
#include <iostream>
using namespace std;
#define Maxsize 50

struct stack
{
    int no;
    double value;
} st[Maxsize];

double ans(int n, double x)
{
    int top = -1, i;
    double fv1 = 1, fv2 = 2 * x;
    for (i = n; i >= 2; i--)
    {
        top++;
        st[top].no = i;
    }
    while (top >= 0)
    {
        st[top].value = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].value;
        top--;
    }
    if (n == 0)
        return fv1;
    return fv2;
}

int main()
{
    double ans1 = ans(3, 1.9);
    cout << ans1 << endl;
    return 0;
}