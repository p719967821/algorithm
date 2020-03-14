/*海选女主角*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,m,i,j,max,maxnumr,maxnumc;
    int a[100][100];
    while (cin >> m >> n)
    {
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        max = abs(a[1][1]);
        maxnumr = 1;
        maxnumc = 1;
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(abs(a[i][j]) > max)
                {
                    max = abs(a[i][j]);
                    maxnumc = j;
                    maxnumr = i;
                }
            }
        }
        cout << maxnumr << " " << maxnumc << " " << a[maxnumr][maxnumc] << endl;
    }
    return 0;
}