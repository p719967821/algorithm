/*神、上帝以及老天爷——错排问题*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n,x;
    long long num[25],sum;
    cin >> n;
    num[1] = 0;
    num[2] = 1;
    for(int j = 3; j <= 20; j++)
    {
        num[j] = (j-1)*(num[j-1]+num[j-2]);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        sum = 1;
        for(int j = 1; j <= x; j++)
        {
            sum *= j; 
        }
        cout << fixed << setprecision(2) << num[x] * 100.0 / sum << "%" << endl;
    }
    return 0;
}
