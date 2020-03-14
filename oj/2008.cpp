/*数值统计*/
#include <iostream>

using namespace std;

int main()
{
    int n,zh=0,fu=0,li=0;
    double x;
    while (cin >> n && n)
    {
      for(int i = 0; i < n; i++)
      {
          cin >> x;
          if(x > 0){zh++;}
          if(x < 0){fu++;}
          if(x == 0){li++;}
          
      }
      cout << fu << " " << li << " " << zh << endl;   
      zh=0;
      fu=0;
      li=0;
    }
    return 0;
}