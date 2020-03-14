/*数据的交换输出*/
#include <iostream>

using namespace std;

int main()
{
    int n,i,a[120],min,minnum;
    while (cin >> n && n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        min = a[0];
        minnum = 0;
        for(i = 0; i < n; i++)
        {
            if(min > a[i])
            {
                min = a[i];
                minnum = i;
            }
        }
        swap(a[minnum],a[0]);
        for(i = 0; i < n; i++)
        {
            if(i == n-1)
            {
                cout << a[i];
            }
            else
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}