#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.14159265

using namespace std;

int main()
{
    int n;
    double x1,y1,x2,y2;
    double a,b,c;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        a = sqrt(x1*x1+y1*y1);
        b = sqrt(x2*x2+y2*y2);
        c = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        cout << fixed << setprecision(2) << acos((a*a+b*b-c*c)/(2*a*b)) * 180.0 / pi << endl;
    }
    return 0;
}