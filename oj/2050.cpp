/*折线分割平面——递推，数学问题*/
#include <iostream>

using namespace std;

int main()
{
    int n,i,m;
    long long cnt[10005];
    cin >> n;
    cnt[1] = 2;
    for(i = 2; i <= 10000; i++)
    {
        cnt[i] = cnt[i-1] + 4*(i-1) + 1;
    }
    for(i = 0; i < n; i++)
    {
        cin >> m;
        cout << cnt[m] << endl;
    }
    return 0;
}