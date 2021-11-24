/* 
    2010ͳ����
    ��n�����������һά����R�У����һ��ʱ��ռ価���ܸ�Ч���㷨����R�е�����ѭ������p��0<p<n����λ�ã�
    ������X0,X1,X2������Xn-1���任Ϊ��Xp,Xp+1,...,Xn-1, X0,X1,...,Xp-1��
    �㷨˼�룺���ú�����������ǰһ���ֺͺ�һ���֣�����������á�
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
    cout << "����ǰ��";
    for (int i = 0; i < n; i++)
        cout << R[i] << " ";
    cout << endl;
    Converse(R,8,5);
    cout << "���ú�";
    for (int i = 0; i < n; i++)
        cout << R[i] << " ";
    cout << endl;
    return 0;
}