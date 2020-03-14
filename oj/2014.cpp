/*青年歌手大奖赛_评委会打分*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n,i,max,min,a[120],maxnum = 0,minnum = 0;
    double sum = 0.0; 
    while (cin >> n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        max = a[0];
        min = a[0];
        for(i = 0; i < n; i++)
        {
            if(a[i] > max)
            {
                max = a[i];
                maxnum = i;
            }
            if(a[i] < min)
            {
                min = a[i];
                minnum = i;
            }
        }
        a[maxnum] = 0;
        a[minnum] = 0;
        for(i = 0; i < n; i++)
        {
            sum += a[i];
        }
        sum /= (n-2);
        cout << fixed << setprecision(2) << sum << endl;
        maxnum = 0;
        minnum = 0;
        sum = 0;
    }
    return 0;
}