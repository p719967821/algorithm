/*Oil Deposits——dfs，横竖对角线都算一个*/
#include <iostream>

using namespace std;

int row,col;
char a[105][105];
int sum;//记录深搜了几次，即代表有几种区域

void dfs(int wr,int wc);

int main()
{
    while (1)
    {
        cin >> row >> col;
        if(row == 0)
        {
            break;
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(a[i][j] == '@')
                {
                    dfs(i,j);
                    sum++;
                }
            }
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}

void dfs(int wr,int wc)
{
    if(wr < 0 || wr >= row || wc < 0 || wc >= col || a[wr][wc] == '*')
    {
        return;
    }
    a[wr][wc] = '*';
    dfs(wr+1,wc);
    dfs(wr-1,wc);
    dfs(wr,wc+1);
    dfs(wr,wc-1);
    dfs(wr+1,wc-1);
    dfs(wr+1,wc+1);
    dfs(wr-1,wc-1);
    dfs(wr-1,wc+1);
}