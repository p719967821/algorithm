/*阿牛的EOF牛肉串*/
#include <iostream>

using namespace std;

int main()
{
    int n,i;
    long long a[60][2];//代表最后一个位置是o和无o的个数，0代表有o，1代表无o
    a[1][0] = 1;
    a[1][1] = 2;
    while (cin >> n)
    {
        //递推的关键就是保证加一个数但字符串一直合理（没有oo）
        for(i = 2; i <= n; i++)
        {
            a[i][1] = a[i-1][0]*2+ a[i-1][1]*2;
            a[i][0] = a[i-1][1];
        }
        if(n == 1)
        {
            cout << a[1][0]+a[1][1] << endl;
        }
        else
        {
            cout << a[n][0]+a[n][1] << endl;
        }
    }
    return 0;
}