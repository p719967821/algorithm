/*Switch Game*/
#include <iostream>

using namespace std;

int main()
{
    int n,sum = 0;
    while (cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(n % i == 0)
            {
                sum++;
            }
        }  
        if(sum % 2 == 0)
        {
            cout << "0" << endl;
        }      
        else
        {
            cout << "1" << endl;
        }
        sum = 0;
    }
    return 0;
}