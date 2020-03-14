#include <iostream>
#include <string.h>

using namespace std;

int gd[10],num[10],n,k,ceng;//层代表在第几层循环里 
int sum;

void dfs(int x);

int main()
{
    int t,i,j;
    cin >> t;
    for(i = 0; i < t; i++)
    {
        cin >> n >> k;
        for(j = 0; j < k; j++)
        {
            cin >> gd[j] >> num[j];//用同一个下标保持两个数组的对应一致
        }
        sum = 0;
        ceng = 1;
        dfs(0);
        cout << sum << endl;
        memset(gd,0,sizeof(gd));
        memset(num,0,sizeof(num));
    }
    return 0;
}

void dfs(int x)
{
    int i;
    if(x == n)
    {
        sum++;
    }
    else
    {
        if(x < n)//防止x超过n还不退出循环的情况
        {
            for(i = 0; i < k; i++)
            {
                if(num[i] != 0)
                {
                    x += gd[i];
                    num[i]--;
                    ceng++;
                    dfs(x);
                    x -= gd[i];
                    num[i]++;
                    ceng--;
                    if(ceng == 1)
                    {
                        num[i] = 0;
                    }
                }
            }
        }
        
    }
    
}