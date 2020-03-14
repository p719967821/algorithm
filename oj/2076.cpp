/*夹角有多大(题目已修改,注意读题)*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n,i,h,m,s;
    double hd,md,sub; 
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> h >> m >> s;
        h %= 12;
        hd = h * 30 + m * 1.0 / 2 + s * 1.0 / 120;
        md = m * 6 + s * 0.1;
        sub = abs(hd - md);
        if(sub > 180)
        {
            sub = 360 - sub;
        }
        cout << fixed << setprecision(0) << abs(sub-0.5) << endl;//只取整数部分
    }
    return 0;
}