/*lowest common multiple plus*/
#include <iostream>

using namespace std;

int main()
{
    int n,a[1000],i,x,flag = 1;
    while (cin >> n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        x = a[0];
            for(x = a[0];;x++)
            {
                for(i = 0; i < n; i++)
                {
                    if(x % a[i] == 0)
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    break;
                }
                flag = 1;
            }
            cout << x << endl;
    }
    
    return 0;
}