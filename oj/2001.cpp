#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    double ar,ac,br,bc,dis;
    while (cin >>ar >> ac >> br >> bc)
    {
        dis = sqrt((ar-br)*(ar-br)+(ac-bc)*(ac-bc));
        cout << fixed << setprecision(2) << dis << endl;//c++形式
        //printf("%.2lf\n",dis);//c形式
    }
    return 0;

}