/*装载问题*/
#include <iostream>
#include <algorithm>
#define N 11

using namespace std;

int c1,c2,n,m;
int a[N];

int search();

int main()
{
    int i,sum = 0;
    while (1)
    {
        cin >> c1 >> c2 >> n;
        if(c1 == 0 && c2 == 0 && n == 0)
        {
            break;
        }
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i]; 
        }
        bfs();
        //清空
        for(i = 0; i < n; i++)
        {
            a[i] = 0; 
        }
        sum = 0;
    }
    return 0;
}

int bfs()
{
    if(m == n)
    {
        if(sum - m <= c2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}