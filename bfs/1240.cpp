/*Asteroids!*/
#include <iostream>
#include <string.h>
#include <queue>
#include <string>

using namespace std;

int n;
int sw,ew;
int used[1005];
int step[1005]; 
int walk[6][3] ={{0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0}};
queue<int> q;

void bfs();
bool cango(int x, int dir);
int go(int x, int dir);

int main()
{
    char x;
    string s;
    int sli,col,row;
    while (cin >> s)
    {   
        cin >> n;
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cin >> x;
                    if(x == 'X')
                    {
                        used[k*n*n+i*n+j] = 1;
                    }
                }
            }
        }
        cin >> col >> row >> sli;
        sw = sli * n * n + row * n + col;
        cin >> col >> row >> sli;
        ew = sli * n * n + row * n + col;
        cin >> s;//输入END的
        //初始化
        used[sw] = 1;
        q.push(sw);
        //开始
        bfs();
        if(step[ew] == 0 && sw != ew)//排除起点与终点相同的情况
        {
            cout << "NO ROUTE" << endl;
        }
        else
        {
            cout << n << " " << step[ew] << endl;
        }
        memset(used,0,sizeof(used));
        memset(step,0,sizeof(step));
    }
    return 0;
}

void bfs()
{
    int x,y,i,j;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 0; i < 6; i++)
        {
            if(cango(x,i))
            {
                y = go(x,i);
                used[x] = 1;
                step[y] = step[x] + 1;
                q.push(y);
            }
        }
    }
    
}

bool cango(int x, int dir)
{
    int xr,xc,xs,yr,yc,ys;
    xs = x / (n*n);
    xr = (x % (n*n)) / n;
    xc = (x % (n*n)) % n;
    ys = xs + walk[dir][0];
    yr = xr + walk[dir][1];
    yc = xc + walk[dir][2];
    if(used[ys*n*n+yr*n+yc] == 1 || yr < 0 || yr >= n || yc < 0 || yc >= n || ys < 0 || ys >= n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int go(int x, int dir)
{
    int xr,xc,xs,yr,yc,ys;
    xs = x / (n*n);
    xr = (x % (n*n)) / n;
    xc = (x % (n*n)) % n;
    ys = xs + walk[dir][0];
    yr = xr + walk[dir][1];
    yc = xc + walk[dir][2];
    return ys*n*n+yr*n+yc;
}