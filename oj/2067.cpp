/*小兔的棋盘*/
#include <iostream>

using namespace std;

int main()
{
    int i,j,n = 0;
    long long a[40][40];
    for(i = 0; i <= 35; i++)
    {
        a[0][i] = 1;
    }
    for(i = 1; i <= 35; i++)
    {
        a[i][i] = a[i-1][i];
        for(j = i+1; j <= 35; j++)
        {
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    i = 1;
    while (1)
    {   
        cin >> n;
        if(n == -1)
        {
            break;
        }
        cout << i++ << " " << n << " " << 2*a[n][n] << endl; 
    }
    return 0;
}