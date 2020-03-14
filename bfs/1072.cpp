/*Nightmare*/

#include <iostream>
#include <queue>

using namespace std;

struct curw 
{
    int r;//current row
    int c;//current column
    int t;//current time
    int s;//current step
};

struct curw cur;
queue<curw> q;//注意这里要改成curw类型
int col,row;
int map[10][10];
int walk[4][2] ={{-1,0},{0,1},{1,0},{0,-1}};

int bfs();

int main()
{
    int n,k,i,j,ans;
    while(cin >> n)
    {   
        for(k = 0; k < n; k++)
        {
            cin >> row >> col;
            for(i = 0; i < row; i++)
            {
                for(j = 0; j < col; j++)
                {
                    cin >> map[i][j];
                    if(map[i][j] == 2)
                    {
                        cur.r = i;
                        cur.c = j; 
                    }
                }
            }
            cur.s = 0;
            cur.t = 6;
            q.push(cur);
            ans = bfs();
            cout << ans << endl;
            while(!q.empty())
            {
                q.pop();
            }
        }
    } 
    return 0;
}

int bfs()
{
    struct curw x,y; 
    int i;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if(map[x.r][x.c] == 3)
        {
            return x.s;
        }
        if(x.t == 1)//没到终点，时间变成1，下一步之后，时间变0，无论怎么走，都没时间了，直接跳过
        {           //忽略掉时间为0的，下面的引爆就不用判断时间
            continue;      
        }        
        for(i = 0; i < 4; i++)
        {
            y.c = x.c + walk[i][1];
            y.r = x.r + walk[i][0];
            if(y.c < 0 || y.c >= col || y.r < 0 || y.r >= row || map[y.r][y.c] == 0)//可以回退，所以在后面不加把路变成used[]=1
            {                                                                       //所以这里的map只是判墙（本题0为墙，路为1）
                continue;
            }
            y.t = x.t - 1;
            y.s = x.s + 1;
            if(map[y.r][y.c] == 4)
            {
                y.t = 6;
                map[y.r][y.c] = 0;
            }
            q.push(y);
        }
    }
    return -1;
}