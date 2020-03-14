/*走迷宫*/
#include <iostream>
#define N 20

using namespace std;

int m,n;//迷宫的行和列
int sr,sc;
int er,ec;
int flag;
int used[N][N];
int walk[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

void bfs(int wz);
bool cango(int wz, int dir);
int go(int wz, int dir);

int main()
{
    int i,j,x,sw;
    cin >> m >> n;
    cin >> sr >> sc;
    cin >> er >> ec;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> used[i][j];
        }
    }
    sw = sr * n + sc;
    bfs(sw);
    if(flag == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}

void bfs(int wz)
{
    int i,x,y;
    if(wz == (er * n + ec))
    {
        flag = 1;
    }
    else
    {
        for(i = 0; i < 4; i++)
        {
            if(cango(wz,i))
            {
                y = go(wz,i);
                used[wz/n][wz%n] = 1;
                bfs(y);
                if(flag == 1)//已经找到了最终的结果，但是递归还得一步步回，如果是10*10的全0，深搜会把所有情况都搜一遍，绝对会
                {            //超时所以用了一个退出
                    break;
                }
                used[wz/n][wz%n] = 0;
            }
        }
    }
    
}

bool cango(int wz, int dir)
{
    int wc,wr,nc,nr;
    wc = wz % n;
    wr = wz / n;
    nr = wr + walk[dir][0];
    nc = wc + walk[dir][1];
    if(nr < m && nr >= 0 && nc < n && nc >= 0 && used[nr][nc] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int go(int wz, int dir)
{
    int wc,wr,nc,nr;
    wc = wz % n;
    wr = wz / n;
    nr = wr + walk[dir][0];
    nc = wc + walk[dir][1];
    return (nr * n + nc);
}