#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s,rig,end;
    cin >> n;
    rig = '6';
    for(int i = 0; i < n; i++)
    {
         cin >> s;
         end = rig + s.substr(6,5);
         cout << end << endl;
    }
    return 0;
}