/**防卫导弹**/
#include <iostream>
#define N 101

using namespace std;

int n;
int a[N];//记录a个数
int num[N];//代表0到当前位置最大拦截数

int dp();

int main()
{
    while (cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        } 
        cout << dp() << endl;
    }
    return 0;
}

int dp()
{
    int i,j,maxnum = 1;
    for(i = 0; i < n; i++)
    {
        num[i] = 1;//初始化为1,代表只有自己
        for(j = 0; j < i; j++)
        {       
            if(a[j] >= a[i])
            {
                num[i] = max(num[i], num[j] + 1);                
            }
        }
        maxnum = max(maxnum, num[i]);
    }
    return maxnum;
}