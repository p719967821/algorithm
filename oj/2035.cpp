/*人见人爱A^B*/
#include <iostream>

using namespace std;

int main()
{
    int n,m,i,one,two,three,mul = 1;
    while (1)
    {
        cin >> m >> n;
        if(m == 0 && n == 0)
        {
            break;
        }
        for(i = 0; i < n; i++)
        {
            if(m > 999)
            {
                one = m % 10;
                two = (m / 10) % 10;
                three = (m / 100) % 10;
                m = three * 100 + two * 10 + one;
            }
            if(mul > 999)
            {
                one = mul % 10;
                two = (mul / 10) % 10;
                three = (mul / 100) % 10;
                mul = three * 100 + two * 10 + one;
            }
            mul *= m;
        }
        one = mul % 10;
        two = (mul / 10) % 10;
        three = (mul / 100) % 10;
        m = three * 100 + two * 10 + one;
        cout << m << endl;
        mul = 1;
    }
    return 0;
}