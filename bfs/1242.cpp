#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int row,col;
int used[40005];
int step[40005]; 
int guard[40005];
int sw,ew,k;//k代表守卫的个数
int walk[4][2] ={{-1,0},{0,1},{1,0},{0,-1}};
queue<int> q;

void bfs();
bool cango(int x, int dir);
int go(int x, int dir);

int main()
{
    char x;
   
    while (cin >> row >> col)
    {
        k = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> x;
                if(x == 'r')
                {
                    sw = i * col + j;
                }
                if(x == 'a')
                {
                    ew = i * col + j;
                }
                if(x == '#')
                {
                    used[i * col + j] = 1;
                }
                if(x == 'x')
                {
                    guard[k] = i * col + j;
                    k++; 
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
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        }
        else
        {
            cout << step[ew] << endl;
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
        for(i = 0; i < 4; i++)
        {
            if(cango(x,i))
            {
                y = go(x,i);
                used[x] = 1;
                for(j = 0; j < k; j++)
                {
                    if(y == guard[j])
                    {
                        step[y] = step[x] + 2;
                        break;
                    }
                }
                if(j == k)
                {
                     step[y] = step[x] + 1;
                }
                q.push(y);
            }
        }
    }
    
}

bool cango(int x, int dir)
{
    int xr,xc,yr,yc;
    xr = x / col;
    xc = x % col;
    yr = xr + walk[dir][0];
    yc = xc + walk[dir][1];
    if(used[yr*col+yc] == 1 || yr < 0 || yr >= row || yc < 0 || yc >= col)
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
    xr = x / col;
    xc = x % col;
    yr = xr + walk[dir][0];
    yc = xc + walk[dir][1];
    return yr*col+yc;
}


//用结构体做
