#include <iostream>

using namespace std;

int main()
{
    int n,i;
    long long f[55];
    f[0] = 0;
    f[1] = 1;
    for(i = 2; i <= 50; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    while (1)
    {
        cin >> n;
        if(n == -1)
        {
            break;
        }
        cout << f[n] << endl;
    }
    return 0;
}