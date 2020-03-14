/*一只小蜜蜂...*/
/*动态规划*/
#include <iostream>

using namespace std;

int main()
{
    int n,i,j,a,b;
    long long x[60];//代表每个位置的可能路线数,这个题的范围比阶梯那个题的范围还大，int会溢出，所以用long long
    cin >> n;
    x[1] = 0;
    x[2] = 1;
    x[3] = 2;
    for(j = 0; j < n; j++)
    {
        cin >> a >> b;
        while (a != 1)
        {
            a--;
            b--;
        }
        for(i = 4; i <= b; i++)
        {
            x[i] = x[i-2] + x[i-1];                                                   
        }
        cout << x[b] << endl;
    }
    return 0;
}