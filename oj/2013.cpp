/*蟠桃记*/
#include <iostream>

using namespace std;

int main()
{
    int n,i,x = 1;
    while (cin >> n)
    {
        for(i = n; i > 1; i--)
        {
            x = (x+1)*2;
        }
        cout << x << endl;
        x = 1;
    }
    return 0;
}