/*进制转换*/
#include <iostream>

using namespace std;

int main()
{
    int n,m,a[100],ws = 0,i;//ws代表位数
    while (cin >> n >> m)
    {
        if(n < 0)
        {
            cout << "-";
            n = 0 - n;
        }
        while (n >= m)
        {
            a[ws] = n % m;
            n /= m;
            ws++;
        }
        a[ws] = n;
        for(i = ws; i >= 0; i--)
        {
            if(a[i] > 9)
            {
                switch (a[i])
                {
                    case 10:{cout << "A";break;}
                    case 11:{cout << "B";break;}
                    case 12:{cout << "C";break;}
                    case 13:{cout << "D";break;}
                    case 14:{cout << "E";break;}
                    case 15:{cout << "F";break;}
                }
            }
            else
            {
                cout << a[i];
            }
        }
        cout << endl;   
        ws = 0;
    }  
    return 0;
}