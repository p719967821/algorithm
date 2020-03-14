/*平方和与立方和*/
#include <iostream>

using namespace std;

int main()
{
    int s,e,sumj = 0,sumo = 0;
    while (cin >> s >> e)
    {
        if(s > e)
        {
            swap(s,e);
        }
       for(int i = s; i <= e; i++)
       {
           if(i % 2 == 0)
           {
               sumo += i*i;
           }
           else
           {
               sumj += i*i*i;
           }
       }
       cout << sumo << " " << sumj << endl;
       sumj = 0;
       sumo = 0;
    }
    return 0;
}