/*字符串统计*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int n,i,j,lo,sum = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        lo = s.length();
        for(j = 0; j < lo; j++)
        {
            if(s[j] <= '9' && s[j] >= '0')
            {
                sum++;
            }
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}