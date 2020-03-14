/*求数列的和*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
   int m;
   double n,sum = 0.0;
   while (cin >> n >> m)
   {
       for(int i = 0; i < m; i++)
       {
           sum += n;
           n = sqrt(n);
       }
       cout << fixed << setprecision(2) << sum << endl;
       sum = 0.0;
   }
   return 0;
}