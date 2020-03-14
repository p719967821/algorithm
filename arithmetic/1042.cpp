/**电子老鼠闯迷宫**/
#include <iostream>

using namespace std;

int sr,sc;
int er,ec;
int sum,sumend=10000000;//用来表示走了多少步
int used[12][12];
int walk[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; 

void gomaze(int wz);
int go(int wz, int dir);
bool cango(int y, int dir);

int main()
{
    int i,j,sw;//开始时的位置
    char x;
    cin >> sr >> sc;
    cin >> er >> ec;
    sr -= 1;
    sc -= 1;
    er -= 1;
    ec -= 1;
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
        {
            cin >> x;
            if(x == 'X')
            {
                used[i][j] = 1;
            }
        }
    }
    sw = sr *12 + sc;
    gomaze(sw);
    cout << sumend << endl;
    return 0;
}

void gomaze(int wz)
{
    int i,y,wr,wc;
    wr = wz / 12;
    wc = wz % 12;
    if(wz == ((er * 12) + ec))
    {
        if(sumend > sum)
        sumend = sum;
        return;
    }
    else
    {
        for(i = 0; i < 4; i++)
        {
            y = go(wz,i);
            if(cango(y,i))
            {
                sum++;
                used[wr][wc] = 1;
                gomaze(y);
                sum--;
                used[wr][wc] = 0;
            }
        }
    }
    
}

int go(int wz, int dir)
{
    int wr,wc;
    wr = wz / 12;
    wc = wz % 12;
    wr = wr +walk[dir][0];
    wc = wc +walk[dir][1];
    return (wr * 12 + wc);
}

bool cango(int y, int dir)
{
    int yr,yc;
    yr = y / 12;
    yc = y % 12;
    if(yr < 12 && yr >= 0 && yc < 12 && yc >= 0 && used[yr][yc] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}