/**活动安排**/
#include <iostream>
#include <algorithm>
#include <map>
#define N 1001

using namespace std;

int s[N];
int tem[N];
int e[N];

map<int,int>p;

int main()
{
    int n,i,sum = 1,firstend;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s[i] >> e[i];
        p[e[i]] = s[i];
    }
    sort(e, e+n);
    for(i = 0; i < n; i++)
    {
        s[i] = p[e[i]];
    }
    firstend = s[0];
    for(i = 1; i <= n; i++)
    {
        if(s[i] >= firstend)
        {
            sum++;
            firstend = e[i];
        }
    }
    cout << sum << endl;
    return 0;
}