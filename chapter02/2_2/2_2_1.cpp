/*
�����Ա���ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾ��Ԫ�ص�ֵ���ճ���λ�������һ��Ԫ�����
��˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
*/
#include <bits/stdc++.h>
using namespace std;

#define Max 50

typedef struct
{
        int a[Max] = {2, 1, 3, 6, 8, 7, 5, 9};  //���Ա��Ԫ��
        int length = 8; //���Ա���
} Sqlist;
bool listdelete(Sqlist &s, int &e)
{
        if (s.length == 0)
                return false;
        int min = s.a[0];
        int flag = 0;
        for (int i = 1; i < s.length; i++)
        {
                if (s.a[i] < min)
                {
                        min = s.a[i];
                        flag = i;
                }
        }
        e = min;
        s.a[flag] = s.a[s.length - 1];
        s.length--;
        return true;
}

int main()
{
        Sqlist s;
        cout << "ɾ��ǰ����Ϊ��";
        for (int i = 0; i < s.length; i++)
                cout << s.a[i] << " ";
        cout << endl;
        int e = 0;
        if (listdelete(s, e))
        {
                cout << "��СֵԪ��Ϊ��" << e << endl;

                cout << "ɾ��������Ϊ��";
                for (int i = 0; i < s.length; i++)
                        cout << s.a[i] << " ";
                cout << endl;
        }
        else
        {
                cout << "ɾ������" << endl;
        }
        return 0;
}
