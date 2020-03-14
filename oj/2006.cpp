/*求奇数的乘积*/
#include <iostream>

using namespace std;

int main()
{
    int n,i,sum = 1,a;
    while (cin >> n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> a;
            if(a % 2 != 0)
            {
                sum *= a;
            }
        }
        cout << sum << endl;
        sum = 1;
    }
    return 0;
}