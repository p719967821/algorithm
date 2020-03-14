/*Subset sequence*/
/*n个数组成集合，其非空子序列按字典序排列，求第m个子序列*/
#include <iostream>

using namespace std;

int a[22];//a[]代表每位所占的数

int main()
{
    int n,i,j,wz;
    long long m;
    long long f[22];//f【n】代表n个数时分为n组，每组的个数.
    f[1] = 1;
    for(i = 2; i < 21; i++)
    {
        f[i] = (i-1)*f[i-1] + 1;
    }
    while (cin >> n >> m)
    {
        for(i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        for(i = n; i > 1; i--)
        {
            //判断m在n组数据中是第几组
            if(m % f[i] == 0)
            {
                wz = m / f[i]; 
            }
            else
            {
                wz = m / f[i] + 1;
            }
            //
            cout << a[wz];
            for(j = wz; j <= n; j++)
            {
                a[j] = a[j+1];
            }
            if(m == f[i]*(wz-1) + 1)
            {
                cout << endl;
                break;
            }
            else
            {
                m = m - (f[i]*(wz-1) + 1);//由在i个数中位置变成在i-1个数中位置
                cout << " ";
            }
        }
        if(i == 1)
        {
            wz = m / f[i];
            cout << a[wz] << endl;
        }
    }
    
    return 0;
}