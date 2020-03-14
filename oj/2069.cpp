/*Coin Change——dp,关键是递归的思路*/

#include <iostream>
#include <string.h>

using namespace std;

int v[5]={1,5,10,25,50};
int dp[110][260];//dp[i][j]代表由i个硬币组成的j元钱的可能数

int main()
{
    int n,i,j,k,sum;
    while (cin >> n)                    
    {
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        //三次for原因见recording
        for(k = 0; k <5; k++)
        {
            for(i = 1; i <= 100; i++)
            {
                for(j = v[k]; j <= n; j++)//从v[k]开始（因为如果从小于v[k]开始，没有加一个5元硬币的可能性）
                {
                    dp[i][j] += dp[i-1][j-v[k]];
                }
            }
        }
        sum = 0;
        for(i = 0; i <= 100; i++)
        {
            sum += dp[i][n];
        }
        cout << sum << endl;
    }
    return 0;
}