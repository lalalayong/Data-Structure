/*
    ɾ������˳������ظ���Ԫ�ء�
*/
#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50

typedef struct
{
    int data[Maxsize] = {1, 2, 3, 3, 5, 5, 7, 8}; //���Ա��Ԫ��
    int length = 8; //���Ա���
} Sqlist;

bool Del_Same(Sqlist &L){
    if(L.length==0)
        return false;
    int i,j;  //i��ŵ�һ������ͬ��Ԫ�أ�jΪ����ָ��
    for(i=0,j=1;j<L.length;j++)
    {
        if(L.data[i]!=L.data[j])  //������i����ͬ��Ԫ�أ���ͬ��Ԫ��������
            L.data[++i]=L.data[j];  //����ͬ��Ԫ����ǰ����
    }
    L.length=i+1;
    return true;
}

int main()
{
    Sqlist L;
    int s,t;
    cout << "ɾ��ǰ��˳���Ϊ��";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout<<endl;

    if(Del_Same(L)){
        cout << "ɾ���ظ�Ԫ�سɹ�������";
        cout << "ɾ�����˳���Ϊ��";
        for (int i = 0; i < L.length; i++)
            cout << L.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "ɾ��ʧ�ܣ�"<<endl;
    }

    return 0;
}