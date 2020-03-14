#include <iostream>

using namespace std;

int main()
{
    int n,i,a,b;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(a % b == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}