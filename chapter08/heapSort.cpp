/*
    ������
*/
#include <bits/stdc++.h>
using namespace std;

//��Ԫ��kΪ�����������µ���
void HeapAdjust(int A[], int k, int len)
{
    A[0] = A[k]; //Ԫ��k�ݴ浽A[0]
    for (int i = 2 * k; i <= len; i *= 2) //��k���ӽڵ�2*k��2*k+1����ɸѡ
    {
        if (i < len && A[i] < A[i + 1]) //�ҵ�k�Ľϴ���ӽڵ�
            i++;
        if (A[0] < A[i]) //������ӽڵ����Ԫ��k
        {
            A[k] = A[i]; //��A[i]������˫�׽ڵ���
            k = i; //�޸�kֵ��������һ��ѭ������
        }
        else //ɸѡ����
        {
            break; 
        } 
    }
    A[k] = A[0]; //��Ԫ��k��������λ��
}

//�����ʼ��
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; --i) //��len/2��1����������
    {
        HeapAdjust(A, i, len);
    }
}

//������������
void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len); //������ʼ�����

    for (int i = len; i > 0; --i) //ÿ��ѡ��һ�����ֵ���Ѷ���
    {
        //���Ѷ�Ԫ����ѵ�Ԫ�ؽ��������ֵ��β����
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        //������
        HeapAdjust(A, 1, i - 1);
    } //���յõ�һ����������
}

int main()
{
    int A[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //�����һ��λ�ò����Ԫ�أ������ڱ�
    int len = 8;
    cout << "����ǰ����Ϊ��";
    for (int i = 1; i <= len; i++)
        cout << A[i] << " ";
    cout << endl;

    HeapSort(A, len);

    cout << "���������Ϊ��";
    for (int i = 1; i <= len; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}