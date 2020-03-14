/*C语言合法标识符*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,i,j,flag = 1,flag1 = 0,len;
    string s;
    cin >> n;
    getchar();
    for(i = 0; i < n; i++)
    {
        getline(cin,s);
        if(s[0] == '_' || (s[0] <= 'z' && s[0] >= 'a') || (s[0] <= 'Z' && s[0] >= 'A'))
        {
            flag1 = 1;
        }
        len = s.length();
        for(j = 1; j < len; j++)
        {
            if(s[j] == '_' || (s[j] <= 'z' && s[j] >= 'a') || (s[j] <= 'Z' && s[j] >= 'A') || (s[j] <= '9' && s[j] >= '0'))
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1 && flag1 == 1)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        flag = 1;
        flag1 = 0;
    }
    return 0;
}