/*Zipper*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string str1,str2,str3;
int l1,l2,l3;
int vis[1100][1100];
int w1,w2;
int flag;

void dfs(int m);

int main()
{
    int n,i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> str1 >> str2 >> str3;
        l1 = str1.length();
        l2 = str2.length();
        l3 = str3.length();
        if(l3 != l1 + l2)
        {
            cout << "Data set " << i << ": no" << endl;
            continue;
        }
        flag = 0;
        w1 = 0;
        w2 = 0;
        memset(vis,0,sizeof(vis));
        dfs(0);
        if(flag == 1)
        {
            cout << "Data set " << i << ": yes" << endl;
        }
        else
        {
            cout << "Data set " << i << ": no" << endl;
        }
        
    }
    return 0;
}

void dfs(int m)
{
    if(m == l3)
    {
        flag = 1;
    }
    if(flag == 1 || vis[w1][w2] == 1)
    {
        return;
    }
    else
    {
        if(str3[m] == str1[w1] && w1 < l1)
        {
            w1++;
            vis[w1][w2] = 1;
            dfs(m+1);
            //vis[w1][w2] = 0;
            w1--;
        } 
        if(str3[m] == str2[w2] && w2 < l2)
        {
            w2++;
            vis[w1][w2] = 1;
            dfs(m+1);
            //vis[w1][w2] = 0;
            w2--;
        }
    }
}