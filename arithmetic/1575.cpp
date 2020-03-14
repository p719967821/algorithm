/**图的m着色问题**/
#include <iostream>
#define N 20
using namespace std;

int m,r,n;
int sum;
int g[N][N];//1代表有路，0代表没路
int colored[N];//0代表没图色，1～n代表相应的颜色

int canprint(int s, int color);
void dfs(int s);

int main()
{
    int i,j,x,y;
    cin >> m >> r >> n;
    for(i = 0; i < r; i++)
    {
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    dfs(0);
    cout << sum << endl;
    return 0;
}

void dfs(int s)
{
    if(s == m)
    {
        sum++;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(canprint(s,i))
            {
                colored[s] = i;
                dfs(s + 1);
                colored[s] = 0;
            }
        }
    }
    
}

int canprint(int s, int color)
{
    int i,flag = 1;
    for(i = 0; i < m; i++)
    {
        if(g[s][i] == 1 && color == colored[i])//有路且颜色同时才不行，其他三种都可以
        {
            flag = 0;
        }
    }
    return flag;
}