/* 
    从顺序表(无序)中删除其值在给定值s到t（s<t）之间的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
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
    for(int i=0;i<L.length;i++){ //i一直走
        if(L.data[i]<s||L.data[i]>t)
        {
            L.data[k]=L.data[i]; //遇到不需删除的元素时复制，k++走一步
            k++;
        }
    }
    L.length=k;
    return true;
}

int main(){
    Sqlist L;
    int s, t;
    cout << "删除前的顺序表为：";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    cout << "请输入你要删除的s与t值：";
    cin >> s >> t;
    // cin>>t;

    if (del_s_t(L, s, t))
    {
        cout << "删除成功！" << endl;
        cout << "删除后的顺序表为：";
        for (int i = 0; i < L.length; i++)
            cout << L.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "删除失败！" << endl;
    }
    return 0;
}