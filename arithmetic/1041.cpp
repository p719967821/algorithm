/**最长公共子序列**/
#include <iostream>
#include <string>

using namespace std;

string x;
string y;

int dp(int a, int b);

int main()
{
    int i,j;
    cin >> x;
    cin >> y;
    i = x.length();
    j = y.length();
    cout << dp(i-1, j-1) << endl;
    return 0; 
}

int dp(int a, int b)
{
    if(a == -1 || b == -1)
    {
        return 0;
    }
    else
    {
        if(x[a] == y[b])
        {
            return dp(a-1, b-1) + 1;
        }
        else
        {
            return (max(dp(a-1,b),dp(a,b-1)));
        }
    }
}