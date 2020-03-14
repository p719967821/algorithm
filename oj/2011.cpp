/*多项式求和*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i,j,n,m;
    double sum,x;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> m;
        for(j = 1; j <= m; j++)
        {
            if(j % 2 == 0)
            {
                x = j;
                sum -= 1/x;
            }
            else
            {
                x = j;
                sum += 1/x;
            }
            
        }
        cout << fixed << setprecision(2) << sum << endl;
        sum = 0; 
    }
    return 0;
}