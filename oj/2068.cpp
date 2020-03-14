/*RPG的错排(排列组合，错排)*/
#include <iostream>

using namespace std;

long long plzh(int m,int n);

int main()
{
    int n,i,times;
    long long a[30],sum,pz;
    a[1] = 0;
    a[2] = 1;
    for(i = 3; i <= 25; i++)
    {
        a[i] = (i-1)*(a[i-1]+a[i-2]);
    } 
    while (cin >> n && n)
    {
        sum = 0;
        times = n / 2;//需要错排的次数
        for(i = 1; i <= times; i++)
        {
            pz = plzh(i,n);
            sum += pz * a[i];
        }
        cout << sum + 1 << endl;
    }
    return 0;
}

long long plzh(int m,int n)//组合,即是c几几而不是a几几，而且注意c几几时，不要用Cmn=n!/((n-m)!*m!),这样十有八九超限，所以用平时手算时的那种方法更好
{
    long long up = 1,down = 1;
    int i,j = n;
    for(i = 0; i < m; i++)
    {
        up *= j;
        j--;
    }
    for(i = 1; i <= m; i++)
    {
        down *= i;
    }
    return up/down;
}