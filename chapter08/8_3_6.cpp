/* 
    ��n�����������ɵļ���A����Ϊ�������ཻ���Ӽ�A1��A2��Ԫ�ظ����ֱ���n1��n2��A1��A2�е�Ԫ��֮�ͷֱ���s1��s2��
���һ�������ܸ�Ч�Ļ����㷨������|n1-n2|��С����|S1-S2|���
    �㷨˼�룺������֪������С��n/2��Ԫ�ط���A1�������Ԫ�ط���A2����������Ҫ�󣬷��տ��������˼�룬�������Ữ��Ϊ�����Ӽ���
���������λ��i�жϣ�
        ��i=n/2���������ɣ��㷨����
        ��i<n/2�������ἰ��֮ǰ������Ԫ�ض�����A1.������i֮���Ԫ�ؽ��л���
        ��i>n/2�������ἰ��֮�������Ԫ�ض�����A2.������i֮ǰ��Ԫ�ؽ��л���
    ���ڴ��㷨�����ȫ��Ԫ�ؽ���ȫ����ƽ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
 */
#include <iostream>
using namespace std;

int setPartition(int A[], int n)
{
    int low = 0,high = n - 1; //low��highΪ����ʱ�Ĺ���ָ��
    int low0 = 0, high0 = n - 1; //low0��high0�ݴ����½磬֮�󻮷�����ı�ʱ���ٴ��õ���
    int flag = 1;
    int k = n / 2;
    int s1 = 0, s2 = 0;
    while (flag)
    {
        int pivot = A[low]; //ѡ������
        while (low < high) //����������л���
        {
            while (low < high && A[high] >= pivot)
                --high;
            A[low] = A[high];
            while (low < high && A[low] <= pivot)
                low++;
            A[high] = A[low];
        }
        A[low] = pivot;
        if(low=k-1) //������Ϊ��n/2��Ԫ�أ��������
            flag=0;
        else{
            if(low<k){ //������low֮���Ԫ�ؽ��л���
                low0=++low; //�����½粢���棬��һ�λ��ֽ��������ֻ��õ����½�
                high=high0; //�����Ͻ磬��һ�ζ��µ�low-high���л���
            }
            else{
                high0=--low; //�����Ͻ粢���棬��һ�λ��ֽ��������ֻ��õ����Ͻ�
                low=low0; //�����½磬��һ�ζ��µ�low-high���л���
            }
        }
    }
    for(int i=0;i<k;i++) 
        s1+=A[i];
    for(int j=k;j<n;j++)
        s2+=A[j];
    return s2-s1;
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    int ans = setPartition(A,n);
    cout<<"������ɣ�"<<endl;
    cout << "S2-S1=" << ans << endl;
    return 0;
}