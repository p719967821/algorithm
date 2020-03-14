/*改革春风吹满地_求多边形面积*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n,i;
    double s = 0;
    int a[220];
    while (cin >> n && n)
    {
        for(i = 0; i < n * 2; i++)
        {
            cin >> a[i];
        }
        for(i = 0; i <= 2*(n-2); i = i + 2)//因为每次增加i+2个，且从0开始，所以要输出n-1次，就要2*(n-2)，还有一次到起点，单独考虑
        {
            s += (a[i]*a[i+3] - a[i+1]*a[i+2]); 
        }
        s += (a[i]*a[1] - a[i+1]*a[0]);
        s /= 2; 
        cout << fixed << setprecision(1) << s << endl;
        s = 0;
    }
    return 0;
}