/*不容易系列之(4)——考新郎——错排+排列组合*/
#include <iostream>

using namespace std;

int main()
{
    int t,i,j,n,m;
    long long num[25],up,down,C,x;
    cin >> t;
    num[1] = 0;
    num[2] = 1;
    for(j = 3; j <= 20; j++)
    {
        num[j] = (j-1)*(num[j-1]+num[j-2]);
    }
    for(i = 0; i < t; i++)
    {
        cin >> n >> m;
        //组合
        up = 1;
        down = 1;
        x = m;
        for(j = n; x > 0; j--,x--)
        {
            up *= j; 
            down *= x; 
        }
        C = up / down;
        cout << C*num[m] << endl;
    }
    return 0;
}