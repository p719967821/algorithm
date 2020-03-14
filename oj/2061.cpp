#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int flag;

int main()
{
    int n,m,i,j;
    string str;
    double fz = 0,fm = 0;//分子，分母
    double s[1000],c[1000];
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> m;
        for(j = 0; j < m; j++)
        {
            cin >> str >> c[j] >> s[j];   
        }
        for(j = 0; j < m; j++)
        {
            if(s[j] < 60.0)
            {
                cout << "Sorry!" << endl;
                flag = 1;
                break;
            }
            fz += s[j]*c[j];
            fm += c[j];
        }
        if(flag == 0)
        {
          cout << fixed << setprecision(2) << (fz / fm) << endl;   
        }
        flag = 0;
        fz = 0;
        fm = 0;
        if(i != n-1)
        {
            cout << endl;
        }
    }
    return 0;
}