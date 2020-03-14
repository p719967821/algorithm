#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
 
int dp[110][255];
int n;
int v[5]={1,5,10,25,50};
 
int main()
{
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int k=0;k<5;k++)
            for(int i=1;i<=100;i++)
                for(int j=v[k];j<=n;j++)
                    dp[i][j] += dp[i-1][j-v[k]];
        int ans = 0;
        for(int i=0;i<=100;i++) ans += dp[i][n]; //n为0的时候输出1，i从0开始
        printf("%d\n",ans);
    }
    return 0;
}
