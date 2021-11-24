/* 
    某汽车轮渡口，过江渡船每次能载十辆车过江，车辆分为客车和货车，规定：同类车先到先上船，客车优于货车先上船，且每上4辆客车，才允许上一辆货车，若等待的客车不足4辆
则以货车代替，若无货车等待，允许客车都上船，设计一个算法模拟渡口管理。
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
        return true; //队空
    else
        return false;
}
bool isFull(quene q)
{
    if (q.f == q.r && q.tag == 1)
        return true; //队满
    else
        return false;
}

bool enQuene(quene &q, elemtype x)
{
    if (isFull(q))
    {
        cout << "队满，进队失败！" << endl;
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
        cout << "队空，出队失败！" << endl;
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
    quene q; //渡船队列
    q.r = q.f = q.tag = 0;
    quene q1; //客车队列
    q1.r = q1.f = q1.tag = 0;
    quene q2; //货车队列
    q2.r = q2.f = q2.tag = 0;

    for (int k = 0; k < Maxsize; k++)
    {
        enQuene(q1, 1);
        enQuene(q2, 2);
    }

    int i = 0, j = 0, x; //j表示渡船上车辆数
    while (j < 10)       //不足10辆
    {
        if (!isEmpty(q1) && i < 4) //客车队列非空且客车未上足4辆
        {
            deQuene(q1, x); //客车队列出队
            enQuene(q, x);  //客车上渡船
            i++;            //客车数+1
            j++;            //渡船上车辆数+1
        }
        else if (i == 4 && !isEmpty(q2)) //客车已上足4辆，且货车队列不空
        {
            deQuene(q2, x); //货车出队
            enQuene(q, x);  //货车上渡船
            j++;
            i = 0; //渡船总车辆数+1
        }
        else //货车队列空或客车队列空
        {
            while (j < 10 && i < 4 && !isEmpty(q2)) //客车队列空
            {
                deQuene(q2, x); //货车队列出队
                enQuene(q, x);  //货车上渡船
                j++;            //渡船上总车辆数+1
                i++;
            }
            i = 0; //i归0
        }
        if (isEmpty(q1) && isEmpty(q2)) //货车和客车加起来不足10辆
            j = 11;                     //跳出循环
    }

    cout << "客车队列" << endl;
    display(q1);
    cout << "货车队列" << endl;
    display(q2);
    cout << "渡船队列" << endl;
    display(q);
}

int main()
{
    manager();
    return 0;
}