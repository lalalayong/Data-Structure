/*
�Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)���㷨��ɾ�����Ա�������ֵΪx��Ԫ�ء�
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

typedef struct
{
    int a[Maxsize] = {2, 1, 3, 1, 8, 1, 5, 9}; //���Ա��Ԫ��
    int length = 8; //���Ա���
} Sqlist;

void deletex_1(Sqlist &L, int x)
{
    int j=0;
    for(int i=0;i<L.length;i++) //iһֱ��
    {
        if(L.a[i]!=x) //��ֵ������xʱj����
        {
            L.a[j]=L.a[i]; 
            j++;
        }   
    }
    L.length=j;
}
void deletex_2(Sqlist &L, int x)
{
    int k=0;  //kͳ��ֵΪx��Ԫ�ظ���
    for(int i=0;i<L.length;i++) 
    {
        if(L.a[i]==x)
        {
            k++;
        }
        else
        {
            L.a[i-k]=L.a[i];  //��ǰԪ��ǰ��k��λ��
        }
    }
    L.length-=k;  //�޸�˳�����
}

int main()
{
    Sqlist L;
    int x;
    cout << "ɾ��ǰ��˳���Ϊ��";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    cout << "��������Ҫɾ����Ԫ��ֵ��";
    cin>>x;

    deletex_1(L,x);

    cout << "ɾ�����˳���Ϊ��";
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    return 0;
}