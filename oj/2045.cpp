/*不容易系列之(3)—— LELE的RPG难题*/
#include <iostream>

using namespace std;

int main()
{
    int n,i;
    long long a[60][2];//代表第i个位置的好坏分别个数，0为不与第一个颜色重合的个数，1为重合的个数
    a[1][0] = 3;
    a[2][0] = 2;
    a[2][1] = 0;
    while (cin >> n)
    {
        for(i = 3; i <= n; i++)
        {
            a[i][1] = a[i-1][0];
            a[i][0] = a[i-1][0] + a[i-1][1]*2;
        }
        if(n == 1)
        {
            cout << a[1][0] << endl;
        }
        else
        {
            cout << a[n][0]*3 << endl;
        }
    }
    return 0;
}