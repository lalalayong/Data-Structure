/* 
    ��˳���(����)��ɾ����ֵ�ڸ���ֵs��t��s<t��֮�������Ԫ�أ���s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
 */

#include <iostream>
using namespace std;

#define Maxsize 50

typedef struct {
    int data[Maxsize]= {1, 2, 3, 4, 5, 6, 7, 8};;
    int length= 8;
}Sqlist;

bool del_s_t(Sqlist &L,int s,int t){
    int k=0;
    if(s>=t||L.length==0)
        return false;
    for(int i=0;i<L.length;i++){ //iһֱ��
        if(L.data[i]<s||L.data[i]>t)
        {
            L.data[k]=L.data[i]; //��������ɾ����Ԫ��ʱ���ƣ�k++��һ��
            k++;
        }
    }
    L.length=k;
    return true;
}

int main(){
    Sqlist L;
    int s, t;
    cout << "ɾ��ǰ��˳���Ϊ��";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    cout << "��������Ҫɾ����s��tֵ��";
    cin >> s >> t;
    // cin>>t;

    if (del_s_t(L, s, t))
    {
        cout << "ɾ���ɹ���" << endl;
        cout << "ɾ�����˳���Ϊ��";
        for (int i = 0; i < L.length; i++)
            cout << L.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "ɾ��ʧ�ܣ�" << endl;
    }
    return 0;
}