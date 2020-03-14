#include <iostream>
#include <iomanip>
#define PI 3.1415927

using namespace std;

int main()
{
    double r,v;
    while (cin >> r)
    {
        v = 4*PI*r*r*r/3;
        cout << fixed << setprecision(3) << v << endl; 
    }
    return 0;
}