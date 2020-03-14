#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char a[3];
    while(scanf("%s",a) != EOF)
    {
        if(a[0] >= a[1] && a[1] > a[2])
        {
            cout << a[2] << " " << a[1] << " " << a[0] << endl;
            continue;
        }
        if(a[0] > a[2] && a[2] > a[1])
        {
            cout << a[1] << " " << a[2] << " " << a[0] << endl;
            continue;
        }
        if(a[1] > a[0] && a[0] > a[2])
        {
            cout << a[2] << " " << a[0] << " " << a[1] << endl;
            continue;
        }
        if(a[1] > a[2] && a[2] > a[0])
        {
            cout << a[0] << " " << a[2] << " " << a[1] << endl;
            continue;
        }
        if(a[2] > a[0] && a[0] > a[1])
        {
            cout << a[1] << " " << a[0] << " " << a[2] << endl;
            continue;
        }
        if(a[2] > a[1] && a[1] > a[0])
        {
            cout << a[0] << " " << a[1] << " " << a[2] << endl;
            continue;
        }
    }
    return 0;
}