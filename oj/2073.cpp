#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double weigh(int x,int y);

int main()
{
    int n,i,x1,x2,y1,y2;
    double w1,w2;
    cin >> n;
    for(i = 0; i <n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        w1 = weigh(x1,y1);
        w2 = weigh(x2,y2);
        cout << fixed << setprecision(3) << abs(w1-w2) << endl;
    }
    return 0;
}

double weigh(int x,int y)
{
    int wz,n,times = 0,i;
    double s,sum = 0;
    while (x != 0)
    {
        x--;
        y++;
        times++;//代表该点距边境有几段
    }
    n = y;//代表边境距起点的距离
    for(i = 1; i <= n; i++)
    {
        s = sqrt(i*i + (i-1)*(i-1)) + sqrt(i*i + i*i);
        sum += s;
    }
    if(n == 0)
    {
        return 0;
    }
    else
    { 
        sum -= (n-times)*sqrt(n*n + n*n)/n;
        return sum;
    }
}