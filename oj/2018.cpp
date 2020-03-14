/*母牛的故事*/
#include <iostream>

using namespace std;

int main()
{
    int n,a[70];
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    while (cin >> n && n)
    {
        for(int i = 5; i <=n; i++)
        {
            a[i] = a[i-1] + a[i-3];//关键
        }
        cout << a[n] << endl;
    }
    return 0;
}