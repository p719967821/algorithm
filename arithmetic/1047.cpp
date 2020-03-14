/**田忌赛马**/
#include <iostream>
#include <algorithm>
#define N 101
#define INF 100000
using namespace std;

int n;
int t[N];
int q[N];
int mon[N][N];//代表钱数
int te,qs;//te=tianjiend qs=qiwangstart 隐含条件qe(qiwangend)=te+qs 

int dp(int te, int qs);
void init();

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    int i;
    while (cin >> n && n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        for(i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        sort(t,t+n,cmp);
        sort(q,q+n,cmp);
        init();
        cout << dp(n-1, 0) << endl;
    }
    return 0;
}

void init()
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            mon[i][j] = INF;
        }
    }
}


int dp(int te, int qs)
{
    if(te == -1)
    {
        return 0;
    }
    else if(mon[te][qs] != INF)
    {
        return mon[te][qs];
    }
    else
    {
        if(q[qs+te] > t[te])
        {
            mon[te][qs] = dp(te-1,qs+1) - 1;
        }
        else if(q[qs+te] < t[te])//齐王输
        {
            mon[te][qs] = dp(te-1,qs) + 1;
        }
        else
        {
            int x,y;//x为最差与最差比，y为最差与最好比
            x = dp(te-1,qs);
            y = dp(te-1,qs+1) + (q[qs] > t[te]? -1 : 0);
            mon[te][qs] = max(x,y);
        }
        return mon[te][qs];
    }
}