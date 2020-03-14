/**加一乘二平方**/

#include <iostream>
#include <queue>
#define N 10001
using namespace std;

int m,n;
int sum;
int step[N];
int used[N];
queue<int> q;

void search();
int change(int x, int way);

int main()
{
    cin >> m >> n;
    q.push(m);
    used[m] = 1;
    search();
    return 0;
}

void search()
{
    int i,x,y;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 0; i < 3; i++)
        {
            y = change(x,i);
            if(y <= n && used[y] == 0)
            {
                step[y] = step[x] + 1;
                used[y] = 1;
                if(y == n)
                {
                    cout << step[y] << endl;
                    return;
                }
                q.push(y);
            }
            
        }
    }
}



int change(int x, int way)
{
    if(way == 0)
    {
        x += 1;
    }
    if(way == 1)
    {
        x *= 2;
    }
    if(way == 2)
    {
        x = x * x;
    }
    return x;
}
