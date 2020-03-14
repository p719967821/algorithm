/*#include <iostream>

using namespace std;

int used[22][22];
int dir[2][2]={{0,1},{1,0}};
int hr,hc;//horse location
int er,ec;//end location
unsigned long long sum;

void move(int lr,int lc);
void cannotgo();

int main()
{
    cin >> er >> ec >> hr >> hc;
    cannotgo();
    move(0,0);
    cout << sum << endl;
    return 0;
}

void move(int lr,int lc)
{
    if(lr == er && lc == ec)
    {
        sum++;
    }
    else
    {
        for(int i = 0; i < 2; i++)
        {   
            if(used[lr +dir[i][0]][lc+dir[i][1]] == 0 && (lr +dir[i][0])<= er && (lc+dir[i][1]) <= ec)
            {
                used[lr +dir[i][0]][lc+dir[i][1]] = 1;
                move(lr+dir[i][0],lc+dir[i][1]);
                used[lr +dir[i][0]][lc+dir[i][1]] = 0;
            }
        }
    }
    
}

void cannotgo()
{
    used[hr][hc] = 1;//马的位置
    if(hr-2 >= 0 && hr-2 < 20 && hc+1 >= 0 && hc+1 < 20)//右上
    {
        used[hr-2][hc+1] = 1;
    }
    if(hr-1 >= 0 && hr-1 < 20 && hc+2 >= 0 && hc+2 < 20)
    {
        used[hr-1][hc+2] = 1;        
    }
    if(hr+2 >= 0 && hr+2 < 20 && hc+1 >= 0 && hc+1 < 20)//右下
    {
        used[hr+2][hc+1] = 1;
    }
    if(hr+1 >= 0 && hr+1 < 20 && hc+2 >= 0 && hc+2 < 20)
    {
        used[hr+1][hc+2] = 1;        
    }
    if(hr+2 >= 0 && hr+2 < 20 && hc-1 >= 0 && hc-1 < 20)//左下
    {
        used[hr+2][hc-1] = 1;
    }
    if(hr+1 >= 0 && hr+1 < 20 && hc-2 >= 0 && hc-2 < 20)
    {
        used[hr+1][hc-2] = 1;        
    }
    if(hr-2 >= 0 && hr-2 < 20 && hc-1 >= 0 && hc-1 < 20)//左上
    {
        used[hr-2][hc-1] = 1;
    }
    if(hr-1 >= 0 && hr-1 < 20 && hc-2 >= 0 && hc-2 < 20)
    {
        used[hr-1][hc-2] = 1;        
    }

}*/

#include <iostream>

using namespace std;

int er,ec,hr,hc;
int used[30][30];//代表该位置是否能走
unsigned long long f[30][30];//代表该位置有多少条路径

void cannotgo();

int main()
{
    int i,j;
    cin >> er >> ec >> hr >> hc;
    cannotgo();
    f[-1][0] = 1;
    for(i = 0; i <= er; i++)
    {
        for(j = 0; j <= ec; j++)
        {
            f[i][j] = f[i-1][j] + f[i][j-1];
            if(used[i][j] == 1)
            {
                f[i][j] = 0;
            }
        }
    }
    cout << f[er][ec] << endl;
    return 0;
}

void cannotgo()
{
    used[hr][hc] = 1;//马的位置
    if(hr-2 >= 0 && hr-2 < 20 && hc+1 >= 0 && hc+1 < 20)//右上
    {
        used[hr-2][hc+1] = 1;
    }
    if(hr-1 >= 0 && hr-1 < 20 && hc+2 >= 0 && hc+2 < 20)
    {
        used[hr-1][hc+2] = 1;        
    }
    if(hr+2 >= 0 && hr+2 < 20 && hc+1 >= 0 && hc+1 < 20)//右下
    {
        used[hr+2][hc+1] = 1;
    }
    if(hr+1 >= 0 && hr+1 < 20 && hc+2 >= 0 && hc+2 < 20)
    {
        used[hr+1][hc+2] = 1;        
    }
    if(hr+2 >= 0 && hr+2 < 20 && hc-1 >= 0 && hc-1 < 20)//左下
    {
        used[hr+2][hc-1] = 1;
    }
    if(hr+1 >= 0 && hr+1 < 20 && hc-2 >= 0 && hc-2 < 20)
    {
        used[hr+1][hc-2] = 1;        
    }
    if(hr-2 >= 0 && hr-2 < 20 && hc-1 >= 0 && hc-1 < 20)//左上
    {
        used[hr-2][hc-1] = 1;
    }
    if(hr-1 >= 0 && hr-1 < 20 && hc-2 >= 0 && hc-2 < 20)
    {
        used[hr-1][hc-2] = 1;        
    }
}