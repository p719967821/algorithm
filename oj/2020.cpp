/*绝对值排序*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,a[120],i,j,max,maxnum;
    while (cin >> n && n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        max = abs(a[0]);
        maxnum = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(max < abs(a[j]))
                {
                    max = abs(a[j]);
                    maxnum = j;
                }
            }
            if(i == 0)
            {
                cout << a[maxnum];
            }
            else
            {
                cout << " " << a[maxnum];
            }
            //不干扰下一轮判断
            a[maxnum] = 0;
            //初始化
            max = abs(a[0]);
            maxnum = 0; 
        }
        cout << endl;
    }
    return 0;
}