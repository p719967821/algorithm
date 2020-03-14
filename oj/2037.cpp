/*今年暑假不AC*/
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int,int> p;

int main()
{
    int n,i,j,a,sum = 0,curw,curmin,x;//curw代表当前位置下标数，curmin代表最小值
    int s[120],e[120];
    while (cin >> n && n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> s[i];
            cin >> e[i];
            p[e[i]] = i;
        }
        sort(e,e+n);
        curw = p[e[0]];
        curmin = e[0];
        x = e[0];
        while (1)
        {
            for(i = 0; i < n; i++)
            {
                if(s[i] >= curmin && x < s[i])
                {
                    x = s[i];
                    j = i;
                }
            }
            if(i == n)
            {
                break;
            }
            curw = p[e[i]];
            curmin = e[curw];
            sum++;
        }
        cout << sum << endl;
        sum = 0;
    } 
    return 0;
}