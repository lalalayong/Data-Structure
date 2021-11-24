/* 
    2010统考：
    设n个整数存放在一维数组R中，设计一个时间空间尽可能高效的算法，将R中的序列循环左移p（0<p<n）个位置，
    即将（X0,X1,X2。。。Xn-1）变换为（Xp,Xp+1,...,Xn-1, X0,X1,...,Xp-1）
    算法思想：逆置函数，先逆置前一部分和后一部分，最后整个逆置。
 */
#include <iostream>
using namespace std;

void reverse(int R[],int left,int right){
    int mid =(left+right)/2;
    for(int i=left;i<=mid;i++)
    {
        int temp=R[i];
        R[i]=R[left+right-i];
        R[left+right-i]=temp;
    }
}
void Converse(int R[],int n,int p){
    reverse(R,0,p-1);
    reverse(R,p,n-1);
    reverse(R,0,n-1);
}

int main(){
    int R[]={1,2,3,4,5,6,7,8};
    int n=8;
    cout << "逆置前：";
    for (int i = 0; i < n; i++)
        cout << R[i] << " ";
    cout << endl;
    Converse(R,8,5);
    cout << "逆置后：";
    for (int i = 0; i < n; i++)
        cout << R[i] << " ";
    cout << endl;
    return 0;
}