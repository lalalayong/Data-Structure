/* 
    判断IO序列（出栈入栈序列）是否合法。
 */
#include <iostream>
using namespace std;

bool isok(char A[])
{
    int i = 0;
    int j = 0, k = 0;
    while (A[i])
    {
        switch (A[i])
        {
        case 'I':
            j++;
            break;
        case 'O':
            k++;
            if (k > j)
                return false;
        }
        i++;
    }
    if (k == j)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char A[8] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
    if (isok(A))
    {
        cout << "序列合法！" << endl;
    }
    else
    {
        cout << "序列不合法！" << endl;
    }
    return 0;
}