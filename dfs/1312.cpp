/*black and red——最基础dfs */
#include <iostream>

using namespace std;

char a[21][21]; 
int row,col;
int sum;

void dfs(int wr, int wc);

int main()
{
    int sr,sc;
    while (1)
    {
        cin >> col >> row;
        if(col == 0 && row == 0)
        {
            break;
        }
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == '@')
                {
                    sr = i;
                    sc = j;
                }
            }
        }
        dfs(sr,sc);
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}

void dfs(int wr, int wc)
{
    if(wr > row || wr < 1 || wc > col || wc < 1 || a[wr][wc] == '#')
    {
        return;
    }
    a[wr][wc] = '#';
    sum++;
    dfs(wr+1,wc);
    dfs(wr-1,wc);
    dfs(wr,wc+1);
    dfs(wr,wc-1);
}