/*The sum problem*/
/*动态规划题,,,,但是超时了*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m,n,i,j,a;
    while (1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        for(i = sqrt(m*2); i > 0; i--)
        {
            a = (m*2-i*i+i)/(2*i);
            if(a*i+i*(i-1)/2 == m)//上下两个是相互推导的，如果上步得到的是除的尽的a则，上下两步相等，可输出，
            {                     //但是如果除不尽，则根据计算机除法的计算方式，上下两步不相等
                cout << "[" << a << "," << a+i-1 << "]" << endl;
            }
        }
        cout << endl;
    }  
    return 0;
}