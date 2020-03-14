/**堡垒问题**/

#include <iostream>
#define N 5
using namespace std;

int n;
int used[N][N];//0为空格，1为墙，2为堡垒
int sum,sumend;

void search(int m);
bool canplace(int wz);

int main()
{
    int i,j;
    char x;
    while (cin >> n && n)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cin >> x;
                if(x == 'X')
                {
                    used[i][j] = 1;
                }
                else
                {
                    used[i][j] = 0;
                }   
            }
        }
        search(0);
        cout << sumend << endl;
        //清空
        sum = 0;
        sumend = 0;
    }
    return 0;
}

void search(int m)
{
    if(m == (n*n))
    {
        sumend = max(sumend,sum);
    }
    else
    {
        if(canplace(m))
        {
            used[m/n][m%n] = 2;
            sum++;
            search(m + 1);
            used[m/n][m%n] = 0;
            sum--;
        }
        search(m + 1);

    }   
}

bool canplace(int wz)
{
    int wr,wc,i,flag1 = 0,flag2 = 0;
    wr = wz / n;
    wc = wz % n;
    for(i = 0; i < wr; i++)
    {
        if(used[i][wc] == 2)
        {
            flag1 = 1;
        }
        if(used[i][wc] == 1)
        {
            flag1 = 0;
        }
    }
    for(i = 0; i < wc; i++)
    {
        if(used[wr][i] == 2)
        {
            flag2 = 1;
        }
        if(used[wr][i] == 1)
        {
            flag2 = 0;
        }
    }
    if(flag1 == 0 && flag2 == 0 && used[wr][wc] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}