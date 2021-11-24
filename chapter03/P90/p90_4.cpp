/* 
    ĳ�����ֶɿڣ������ɴ�ÿ������ʮ����������������Ϊ�ͳ��ͻ������涨��ͬ�೵�ȵ����ϴ����ͳ����ڻ������ϴ�����ÿ��4���ͳ�����������һ�����������ȴ��Ŀͳ�����4��
���Ի������棬���޻����ȴ�������ͳ����ϴ������һ���㷨ģ��ɿڹ���
 */
#include <iostream>
using namespace std;
#define Maxsize 10
#define elemtype int

typedef struct
{
    elemtype data[Maxsize];
    int f, r, tag;
} quene;

bool isEmpty(quene q)
{
    if (q.f == q.r && q.tag == 0)
        return true; //�ӿ�
    else
        return false;
}
bool isFull(quene q)
{
    if (q.f == q.r && q.tag == 1)
        return true; //����
    else
        return false;
}

bool enQuene(quene &q, elemtype x)
{
    if (isFull(q))
    {
        cout << "����������ʧ�ܣ�" << endl;
        return false;
    }
    q.data[q.r] = x;
    q.r = (q.r + 1) % Maxsize;
    q.tag = 1;
    return true;
}
bool deQuene(quene &q, elemtype &x)
{
    if (isEmpty(q))
    {
        cout << "�ӿգ�����ʧ�ܣ�" << endl;
        return false;
    }
    x = q.data[q.f];
    q.f = (q.f + 1) % Maxsize;
    q.tag = 0;
    return true;
}
void display(quene q)
{
    for (int i = 0; i < Maxsize; i++)
    {
        cout << q.data[q.f] << " ";
        q.f = (q.f + 1) % Maxsize;
    }
    cout << endl;
}

void manager()
{
    quene q; //�ɴ�����
    q.r = q.f = q.tag = 0;
    quene q1; //�ͳ�����
    q1.r = q1.f = q1.tag = 0;
    quene q2; //��������
    q2.r = q2.f = q2.tag = 0;

    for (int k = 0; k < Maxsize; k++)
    {
        enQuene(q1, 1);
        enQuene(q2, 2);
    }

    int i = 0, j = 0, x; //j��ʾ�ɴ��ϳ�����
    while (j < 10)       //����10��
    {
        if (!isEmpty(q1) && i < 4) //�ͳ����зǿ��ҿͳ�δ����4��
        {
            deQuene(q1, x); //�ͳ����г���
            enQuene(q, x);  //�ͳ��϶ɴ�
            i++;            //�ͳ���+1
            j++;            //�ɴ��ϳ�����+1
        }
        else if (i == 4 && !isEmpty(q2)) //�ͳ�������4�����һ������в���
        {
            deQuene(q2, x); //��������
            enQuene(q, x);  //�����϶ɴ�
            j++;
            i = 0; //�ɴ��ܳ�����+1
        }
        else //�������пջ�ͳ����п�
        {
            while (j < 10 && i < 4 && !isEmpty(q2)) //�ͳ����п�
            {
                deQuene(q2, x); //�������г���
                enQuene(q, x);  //�����϶ɴ�
                j++;            //�ɴ����ܳ�����+1
                i++;
            }
            i = 0; //i��0
        }
        if (isEmpty(q1) && isEmpty(q2)) //�����Ϳͳ�����������10��
            j = 11;                     //����ѭ��
    }

    cout << "�ͳ�����" << endl;
    display(q1);
    cout << "��������" << endl;
    display(q2);
    cout << "�ɴ�����" << endl;
    display(q);
}

int main()
{
    manager();
    return 0;
}