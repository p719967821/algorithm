/*汉字统计*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,i,j,sum = 0;
    string s;
    cin >> n;
    getchar();
    for(i = 0; i < n; i++)
    {
    getline(cin,s);
    for(j = 0; j < s.size(); j++)
    {
        if(s[j] < 0)
        {
            sum++;
        }
    }
    cout << sum/2 << endl;
    sum = 0;
    }
    return 0;
}
