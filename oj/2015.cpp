/*偶数求和*/
#include <iostream>

using namespace std;

int main()
{
    int m,n,k,i,j = 0,shen;
    double a[120],sum = 0;
    while (cin >> n >> m)
    {
        k = n;
        for(i = 2;k > 0;i = i + 2)
        {
            a[j] = i;
            j++;
            k--;
        }
        for(i = 0; n - i >= m;i = i + m)
        {
            for(j = i; j < i+m; j++)
            {
                sum += a[j];
            }
            sum /= m;
            if(i == 0)
            {
                cout << sum;
            }
            else
            {
                cout << " " << sum;
            }
            sum = 0;
        }
        shen = n - j;//剩余的个数
        for(j = i; j < n; j++)
        {
            sum += a[j];
        }
        if(shen != 0)
        {
            sum /= shen;
            cout << " " << sum;  
        }
        cout << endl;
        sum = 0;
        j = 0;
    }
    return 0;
}