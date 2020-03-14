/**八数码**/
#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef struct tagnode
{
    int a[3][3];
    int zr,zc;//零的行和列
    int num;//组合成的一个数
    int step;//到该结点的步数
}node;

node start;
queue<node> q;
map <int,int> used;
int walk[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; 

bool canchange(node x, int dir);
int bfs();
node change(node x,int dir);
void init();

int main()
{
    init();
    cout << bfs() << endl;
    return 0;
}

int bfs()
{
    int i;
    node x,y;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 0; i < 4; i++)
        {
            if(canchange(x,i))
            {
                y = change(x,i);
                if(y.num == 123456780)
                {
                    return (y.step + 1); 
                }
                used[y.num] = 1;
                y.step = x.step + 1;
                q.push(y);
            }
        }
    }
    return -1;
}

node change(node x,int dir)
{
    int t,nzr,nzc,nnum = 0;
    nzr = x.zr + walk[dir][0];
    nzc = x.zc + walk[dir][1];
    t = x.a[x.zr][x.zc];
    x.a[x.zr][x.zc] = x.a[nzr][nzc];
    x.a[nzr][nzc] = t;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            nnum = nnum * 10 + x.a[i][j];
        }
    }
    //更改为新值
    x.zc = nzc;
    x.zr = nzr;
    x.num = nnum;
    return x;
}

bool canchange(node x, int dir)
{
    int t,nzr,nzc,nnum = 0;
    nzr = x.zr + walk[dir][0];
    nzc = x.zc + walk[dir][1];
    if(nzr < 3 && nzr >= 0 && nzc < 3 && nzc >= 0)
    {
        //0和其要变的位置的数交换
        t = x.a[x.zr][x.zc];
        x.a[x.zr][x.zc] = x.a[nzr][nzc];
        x.a[nzr][nzc] = t;
        //得到新的num
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
               nnum = nnum * 10 + x.a[i][j];
            }
        }
        //再判断新的是否用过
        if(used.count(nnum) == 0)
        {
            return true;
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false;
    }
    
}

void init()
{
    int i,j;
    start.num = 0;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cin >> start.a[i][j];
            if(start.a[i][j] == 0)
            {
                start.zr = i;
                start.zc = j;
            }
            start.num = start.num * 10 + start.a[i][j];
        }
    }
    used[start.num] = 1;
    start.step = 0;
    q.push(start);
}