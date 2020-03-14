/*数列有序!*/
#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j;
    int a[120];
    while (1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(i = 0; i < n; i++)
        {
            if(m <= a[i])
            {
                break;
            }
        }
        for(j = 0; j < n; j++)
        {
            if(j == 0)
            {
                if(j == i)
                {
                    cout << m << " " << a[j];
                } 
                else
                {
                    cout << a[j];
                }
                
            }
            else
            {
                if(j == i)
                {
                    cout << " " << m << " " << a[j];
                } 
                else
                {
                    cout << " " << a[j];
                }
                
            }     
        }
        if(j == i)
        {
            cout << " " << m;
        }
        cout << endl;
    }
    return 0;
}