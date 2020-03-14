/*超级楼梯*/
/****深搜，对但是超时****
 *********************

#include <iostream>
#include<time.h>

using namespace std;

int m,sum;
int go[2] ={1,2};

void dfs(int x);

int main()
{
    int n,i;
    clock_t stime,etime;
    stime = clock();
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> m;
        dfs(1);
        cout << sum << endl;
        sum = 0;
    }
    etime = clock();
    cout << "time is" << static_cast<double>(etime - stime)/CLOCKS_PER_SEC*1000 << endl;
    return 0;
}

void dfs(int x)
{
    int i;
    if(x == m)
    {
        sum++;
    }
    else
    {
        if(x < m)
        {
           for(i = 0; i < 2; i++)
            {
                x = x + go[i];
                dfs(x);
                x = x - go[i];
            } 
        }
    }
    
}
****************/
/**dp**/
#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,a[50];
    cin >> n;
    a[2] = 1;
    a[3] = 2;
    for(j = 0; j < n; j++)
    {
        cin >> m;
        for(i = 4; i <= m; i++)
        {
            a[i] = a[i-1] + a[i-2];
        }
        cout << a[m] << endl;  
    } 
    return 0;
}