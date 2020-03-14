#include <iostream>

using namespace std;

int m,bian,sum,ave,flag;
int a[25],used[25];

void dfs(int num,int lenth,int bian);

int main()
{
    int n,i,j;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> m;
        sum = 0;
        flag = 0;
        for(j = 0; j < m; j++)
        {
            cin >> a[j];
            sum += a[j]; 
        }
        if(sum % 4 != 0)
        {
            cout << "no" << endl;
            continue;
        }
        ave = sum / 4;
        for(j = 0; j < m; j++)
        {
            if(a[j] > ave)
            {
                flag = 1;
                continue;
            } 
        }
        if(flag == 1)
        {
            cout << "no" << endl;
            continue;
        }
        bian = 0;
        flag = 0;
        dfs(0,0,0);
        if(flag)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}

void dfs(int num,int lenth,int bian)
{
    if(bian == 3)
    {
        flag = 1;
        return;
    }
    if(num == m)
    {
        return;
    }
    if(lenth + a[num] < ave && used[num] == 0)
    {
        used[num] = 1;
        dfs(num+1,lenth+a[num],bian);
        used[num] = 0;
    }
    if(lenth + a[num] == ave && used[num] == 0)
    {
        used[num] = 1;
        dfs(0,0,bian+1);
        used[num] = 0;
    }
    dfs(num+1,lenth,bian);
}