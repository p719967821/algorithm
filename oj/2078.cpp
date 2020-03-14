/*复习时间*/
#include <iostream>

using namespace std;

int main()
{
    int t,m,n,x,minn,ans;
    cin >> t;
    for(int j = 0; j < t; j++)
    {
        minn = 1000000;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(minn > x)
            {
                minn = x;
            }
           
        } 
        cout << (100 - minn)*(100 - minn) << endl;
    }
    return 0;
}