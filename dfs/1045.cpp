#include <iostream>
#include <string.h>

using namespace std;

int map[25];
int maxn,n,mmaxn;

void dfs(int m);
bool canplace(int m);

int main()
{
    char x;
    while (cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> x;
                if(x == 'X')
                {
                    map[i*n+j] = 1;
                }
            }
        }
        maxn = 0;
        mmaxn = -1;
        dfs(0);
        cout << mmaxn << endl;
        memset(map,0,sizeof(map));
    }   
    return 0;
}

void dfs(int m)
{
    if(m == n*n)
    {
        if(maxn > mmaxn)
        {
            mmaxn = maxn;
        }
    }
    else
    {
        if(canplace(m))
        {
            map[m] = 2;
            maxn++;
            dfs(m+1);
            map[m] = 0;
            maxn--;
        }   
        dfs(m+1);  
    }
}

bool canplace(int m)
{
    int row,col;
    int flag1 = 0,flag2 = 0;
    row = m / n;
    col = m % n;
    if(map[m] == 1)
    {
        return false;
    }
    for(int i = 0; i < col; i++)
    {
        if(map[row*n+i] == 2)
        {
            flag1 = 1;
        }
        if(map[row*n+i] == 1)
        {
            flag1 = 0;
        }
    }
    for(int i = 0; i < row; i++)
    {
        if(map[i*n+col] == 2)
        {
            flag2 = 1;
        }
        if(map[i*n+col] == 1)
        {
            flag2 = 0;
        }
    }
    if(flag1 == 0 && flag2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}