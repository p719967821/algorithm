#include <iostream>
#include <queue>

using namespace std;

typedef struct  Data
{
    int Etime;
    int x, y;
    int count;
}Data;
 
int n, m, sx, sy;
int map[9][9];
int direction[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
 
int bfs()                       //广度搜索
{
    int i;
    int tx, ty;
    queue<Data> Que;
    while(!Que.empty())
    {
        Que.pop();
    }
    Data Da, temp;
    Da.x = sx; Da.y = sy;
    Da.Etime = 6; Da.count = 0;
    Que.push(Da);                       //起点入队
    while(!Que.empty())
    {
        temp = Que.front();
        Que.pop();
        if(map[temp.x][temp.y] == 3)  //到了终点
            return temp.count;
        if(temp.Etime == 1)           //没到终点，时间变成1，下一步之后，时间变0，无论怎么走，都没时间了，直接跳过
            continue;             //忽略掉时间为0的，下面的引爆就不用判断时间
        for(i = 0; i < 4; i++)        //四个方向搜索
        {
            tx = temp.x + direction[i][0];
            ty = temp.y + direction[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || map[tx][ty] == 0)
                continue;
    
            Da.x = tx; Da.y = ty; Da.Etime = temp.Etime - 1; Da.count = temp.count + 1;    
            if(map[tx][ty] == 4)          //引爆，重置时间
            {
                Da.Etime = 6;
                map[tx][ty] = 0;
            }
            Que.push(Da);
        }
    }
    return -1;
}
 
int main()
{
//    freopen("data.txt", "r", stdin);
    int T, i, j;
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d%d", &n, &m);
            for(i = 0; i < n; i++)
                for(j = 0; j < m; j++)
                {
                    scanf("%d", &map[i][j]);
                    if(map[i][j] == 2)            //找到起点
                    {
                        sx = i;
                        sy = j;
                    }
                }
            int ans = bfs();
            cout << ans << endl;
        }
    }
    return 0;
}