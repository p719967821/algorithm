/**花生米（二）*/
#include <iostream>
#define N 1001
using namespace std;

int n;
int a[N];

int dp(int m);

int main()
{
    int i;
    for(i = 1; i <=10; i++)
    {
        if(i % 2 == 0)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }     
    }
    while (cin >> n && n)
    { 
        cout << dp(n) << endl;
    }
    return 0;
}

int dp(int m)
{
    int i;
    if(m <= 10)
    {
        return a[m];
    }
    else
    {
        for(i = 11; i <= m; i++)
        {
            if(a[i-1] == 1 && a[i-5] == 1 && a[i-10] == 1)
            {
                a[i] = 0;
            }   
            else
            {
                a[i] = 1;
            }
        }   
        return a[n]; 
    }
}
