/**矩阵连乘**/

#include <iostream>
#define N 101

using namespace std;

int n;
int row[N];//每个矩阵的行
int col[N];//每个矩阵的列
int s[N][N];//记录最少的次数

void dp();

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> row[i] >> col[i];
    }
    dp();
    cout << s[0][n-1] << endl;
    return 0;
}

void dp()
{
    int i,j,k,len;
    //初始化
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                s[i][j] = 0;
            }
            else
            {
                s[i][j] = INT_MAX;
            }
            
        }
    }
    //开始从底向上规划
    for(len = 1; len < n; len++)
    {
        for(i = 0,j = i + len; j < n; i++ , j++)
        {
            for(k = i; k < j; k++)
            {
                s[i][j] = min(s[i][j],s[i][k] + s[k+1][j] + row[i]*col[k]*col[j]);
            }
        }
    }
}