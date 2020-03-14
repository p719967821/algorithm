/*Bitset*/
#include <iostream>

using namespace std;

int main()
{
    int x,y,a[1000],wz=0,i;
    while (cin >> x)
    {
         while (x >= 2)
        {
            a[wz] = x % 2;
            x = x / 2;
            wz++;
        }
        a[wz] = x;
        for(i = wz; i >= 0; i--)
        {
            cout << a[i];
        }
        cout << endl;
        wz = 0;
    }
    return 0;
}