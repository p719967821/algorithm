#include <iostream>
#include <algorithm>

using namespace std;

int f[11][11][11][11],a[11][11];

int main()
{
    int n,x,y,num,i,j,k,l;
    cin >> n;
    while (1)
    {
        cin >> x >> y;
        cin >> a[x][y];
        if(x == 0 && y == 0 && a[x][y] == 0)
        {
            break;
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            for(k = 1; k <= n; k++)
            {
                for(l = 1; l <= n; l++)
                {
                    f[i][j][k][l] = max(f[i-1][j][k-1][l],max(f[i-1][j][k][l-1],max(f[i][j-1][k-1][l],f[i][j-1][k][l-1])))+a[i][j]+a[k][l];
                    if(i == k && j == l)
                    {
                        f[i][j][k][l] -= a[i][j];
                    }
                }
            }
        }
    }
    cout << f[n][n][n][n] << endl;
    return 0;
}