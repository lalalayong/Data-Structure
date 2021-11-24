/* 
    增设tag标记的循环队列
 */
#include <iostream>
using namespace std;
#define Maxsize 50

typedef struct
{
    int data[Maxsize];
    int front, rear;
    int tag;
} squene;

bool enQuene(squene &q, int x)
{
    if (q.front == q.rear && q.tag == 1)
    {
        cout << "队满" << endl;
        return false;
    }
    q.data[q.rear] = x;
    cout<<q.data[q.rear]<<" ";
    q.rear = (q.rear + 1) % Maxsize;
    q.tag = 1;
    return true;
}

bool deQuene(squene &q, int &x)
{
    if (q.front == q.rear && q.tag == 0)
    {
        cout << "队空" << endl;
        return false;
    }
    x = q.data[q.front];
    q.front = (q.front + 1) % Maxsize;
    q.tag = 0;
    return true;
}

int main()
{
    squene q;
    q.front=0,q.rear=0,q.tag=0;
    for(int i=0;i<Maxsize;i++)
        enQuene(q,i);
    cout<<endl;
    enQuene(q,1);

    return 0;
}