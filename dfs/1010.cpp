#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int row,col,t;
int used[100];
int step[100]; 
int sw,ew;
int walk[4][2] ={{-1,0},{0,1},{1,0},{0,-1}};
queue<int> q;

void bfs();
bool cango(int x, int dir);
int go(int x, int dir);

int main()
{
    char x;
    while (1)
    {
        cin >> row >> col >> t;
        if(row == 0 && col == 0 && t == 0)
        {
            break;
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> x;
                if(x == 'S')
                {
                    sw = i * row + j;
                }
                if(x == 'D')
                {
                    ew = i * row + j;
                }
                if(x == 'X')
                {
                    used[i * row + j] = 1;
                }
            }
        }
        //初始化
        used[sw] = 1;
        q.push(sw);
        //开始
        bfs();
        if(step[ew] == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            if(step[ew] <= t )
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        memset(used,0,sizeof(used));
        memset(step,0,sizeof(step));
    }
    return 0;
}

void bfs()
{
    int x,y,i;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 0; i < 4; i++)
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
    int xr,xc,yr,yc;
    xr = x / row;
    xc = x % row;
    yr = xr + walk[dir][0];
    yc = xc + walk[dir][1];
    if(used[yr*row+yc] == 1 || yr < 0 || yr >= row || yc < 0 || yc >= col)
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
    int xr,xc,yr,yc;
    xr = x / row;
    xc = x % row;
    yr = xr + walk[dir][0];
    yc = xc + walk[dir][1];
    return yr*row+yc;
}