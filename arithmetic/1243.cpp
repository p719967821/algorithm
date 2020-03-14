/**循环赛日程表**/

#include <iostream>
#define N 150
using namespace std;

int k;//二的多少次方
int a[N][N];

int main()
{
    int n = 1,m = 1,i,j,s,t,x;
    cin >> k;
    for(i = 0; i < k; i++)
    {
        n = 2 * n;
    }
    x = n;
    for(i = 1; i <= n; i++)
    {
        a[1][i] = i;
    }
    for(s = 1; s <= k; s++)
    {
        n /= 2;
        for(t = 1; t <= n; t++)
        {
         for(i = m+1; i <= 2*m; i++)
         {
             for(j = m+1; j <= 2*m; j++)
             {
                 a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*2*m-m];
                 a[i][j+(t-1)*m*2-m] = a[i-m][j+(t-1)*2*m]; 
             }
         }   
        }
        m *= 2;
    }
    //输出
    for(i = 1; i <= x; i++)
    {
        for(j = 1; j <= x; j++)
        {
            if(j!= x)
            {
                cout << a[i][j] << " ";
            }
            else
            {
                cout << a[i][j];
            }
            
        }
        cout << endl;
    }
    return 0;
}