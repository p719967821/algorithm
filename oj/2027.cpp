/*统计元音*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,i,len,j,anum=0,ennum=0,inum=0,onum=0,unum=0;
    string s;
    cin >> n;
    getchar();
    for(i = 0; i < n; i++)
    {
        getline(cin,s);
        len = s.length();
        for(j = 0; j < len; j++)
        {
            if(s[j] == 'a')
            {
                anum++;
            }
            if(s[j] == 'e')
            {
                ennum++;
            }
            if(s[j] == 'i')
            {
                inum++;
            }
            if(s[j] == 'o')
            {
                onum++;
            }
            if(s[j] == 'u')
            {
                unum++;
            }
        }
        cout << "a:" << anum << endl;
        cout << "e:" << ennum << endl;
        cout << "i:" << inum << endl;
        cout << "o:" << onum << endl;
        cout << "u:" << unum << endl; 
        if(i < n-1)
        {
            cout << endl;
        }
        anum=0;
        ennum=0;
        inum=0;
        onum=0;
        unum=0;
    }
    return 0;
}