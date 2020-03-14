#include <iostream>

using namespace std;

int main()
{
    int n,i,x,y,num = 0;
    int a[10000],b[10000],g[10000],k[10000];
    cin >> n;
    for(i = 0; i < n ; i++)
    {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    cin >> x >> y;
    for(i = 0; i < n; i++)
    {
        if(x >= a[i] && x <= (a[i] + g[i]) && y >= b[i] && y <= (b[i] + k[i]))
        {   
            num = i + 1;
        }
    }
    if(num == 0)
    {
        num = -1;
    }
    cout << num << endl;
    return 0;
}