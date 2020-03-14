/*一个人的旅行*/
/**************
 * floyd算法*
 * 但会超时*
 ***********

#include <iostream>
#include <string.h>
#define INF 1000000

using namespace std;
 
//g[i][j]代表i顶点到j顶点的最小权值，也是输入的图,path[i][j]的值代表i顶点到j顶点最短距离的中间过渡顶点对应的数,path[i][j]起始值为j
int s[1005],e[1005],g[1005][1005],path[1005][1005];
int maxcity;//用于表示最大的地点数目
int minn = INF,minest = INF;

void floyd();
void judgemin(int sn,int en);

int main()
{
    int i,n,sn,en,a,b,c;//分别代表个数，开始地点的个数，结束地点的个数
    while (cin >> n >> sn >> en)
    {
        for(i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            g[a][b] = c;
            g[b][a] = c;
        }
        for(i = 0; i < sn; i++)
        {
            cin >> s[i];
        }
        for(i = 0; i < en; i++)
        {
            cin >> e[i];
            if(maxcity < e[i])
            {
                maxcity = e[i];
            }
        }
        floyd();
        judgemin(sn,en);
        cout << minest << endl;
        //初始化
        minest = INF;
        memset(g,0,sizeof(g));
    }
    return 0;
}

void floyd()
{
    int i,j,k;
    //初始化                              
    for(i = 1; i <= maxcity; i++)
    {
        for(j = 1; j <= maxcity; j++)
        {
            if(g[i][j] == 0)
            {
                g[i][j] = INF;
            }
        }
    }
    for(i = 1; i <= maxcity; i++)
    {
        for(j = 1; j <= maxcity; j++)
        {
            path[i][j] = j;            
        }
    }
    //floyd
    for(k = 1; k <= maxcity; k++)
    {
        for(i = 1; i <= maxcity; i++)
        {
            for(j = 1; j <= maxcity; j++)
            {
                if(g[i][k] + g[k][j] < g[i][j])
                {
                    g[i][j] = g[i][k] + g[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

void judgemin(int sn,int en)
{
    int i,j;
    for(i = 0; i < sn; i++)
    {
        for(j = 0; j < en; j++)
        {
            minn = g[s[i]][e[i]];
            if(minn < minest)
            {
                minest = minn;
            }
        }
    }
}
****************/

/*dijstra算法*/
#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f 

using namespace std;

int set[1020],dis[1020];
int e[1020],s[1020],g[1020][1020];
int maxcity;
int minn = INF,minest = INF;//分别代表对于每个起点来说的最小值和整个某组数据的最小值

int dijstra(int sta,int en);

int main()
{
    int i,j,n,sn,en,a,b,c;//分别代表个数，开始地点的个数，结束地点的个数
    while (cin >> n >> sn >> en)
    {    
        for(i = 1; i <= 1005; i++)
        {
            for(j = 1; j <= 1005; j++)
            {
                    g[i][j] = INF;
            }
        }
        for(i = 0; i < n; i++)
        {
            maxcity = 0;
            cin >> a >> b >> c;//有一条边两个权值的情况
            if(maxcity < a){maxcity = a;}
            if(maxcity < b){maxcity = b;}
            if(g[a][b] > c)
            {
                g[a][b] = c;
                g[b][a] = c;
            }
        }
        for(i = 0; i < sn; i++)
        {
            cin >> s[i];
        }
        for(i = 0; i < en; i++)
        {
            cin >> e[i];
        }
        for(i = 0; i < sn; i++)
        {
            minn = dijstra(s[i],en);
            if(minn < minest)
            {
                minest = minn;
            }
        }
        cout << minest << endl;
        minest = INF;
        maxcity = 0;
        memset(g,0,sizeof(g));
        memset(set,0,sizeof(set));
    }    
    return 0;
}

int dijstra(int sta,int en)
{
    int i,j,mindis,wz;
    //初始化
    for(i = 1; i <= maxcity; i++)
    {
        dis[i] = g[sta][i];
    }
    set[sta] = 1;
    //纳入点
    for(i = 2; i <= maxcity; i++)
    {
        mindis = INF;
        for(j = 1; j <= maxcity; j++)
        {
            if(mindis > dis[j] && set[j] == 0)
            {
                mindis = dis[j];
                wz = j;
            }
        }
        set[wz] = 1;
        for(j = 1; j <= maxcity; j++)
        {
            if(set[j] == 0 && dis[j] > dis[wz] + g[wz][j])
            {
                dis[j] = dis[wz] + g[wz][j];
            }
        }
    }
    //判断
    mindis = INF;
    for(i = 0; i < en; i++)
    {
        if(mindis > dis[e[i]])
        {
            mindis = dis[e[i]];
        }
    }
    return mindis;
}