/* 
    ���ѡ������Ԫ�صĿ�������
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
//���ֺ���
int Partition(int A[], int low, int high) //һ�˻���
{
    int rand_index = low+rand()%(high-low+1); //�����������Ϊ����
    swap(A[rand_index],A[low]); //��������A[low]����

    //����ִ�п��Ż����㷨
    int pivot = A[low]; //�����еĵ�һ��Ԫ������Ϊ����
    while (low < high)  //ѭ����������
    {
        while (low < high && A[high] >= pivot)
            high--; //�ҵ�������С��Ԫ��
        A[low] = A[high]; //�ƶ������
        while (low < high && A[low] <= pivot)
            low++; //�ҵ���������Ԫ��
        A[high] = A[low]; //�ƶ����ֶ�
    } //ѭ��������low=high
    A[low] = pivot; //low��high��λ�ü�Ϊ����Ԫ�ص�����λ��
    return low; //���ش������Ԫ�ص�λ��
}

//��������������
void QuickSort(int A[], int low, int high)
{
    if (low < high) //�ݹ�����������
    {
        int pos = Partition(A, low, high); //����
        QuickSort(A, low, pos - 1);        //�ݹ�������ӱ���п�������
        QuickSort(A, pos + 1, high);
    }
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    cout << "����ǰ����Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    QuickSort(A, 0, n - 1);

    cout << "���������Ϊ��";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}