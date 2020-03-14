/*素数判定*/
#include <iostream>
#include <cmath>

using namespace std;

bool isright(int z);

int main()
{
    int x,y,z,flag ;
    while (1)
    {
        cin >> x >> y;
        if(x == 0 && y == 0)
        {
            break;
        }
        for(int i = x;i <= y; i++)
        {
            z = i*i + i + 41;
            if(isright(z))//判断是否是素数
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "Sorry" << endl;
        }
        
    }
    return 0;
}

bool isright(int z)
{
    int i,x;
    x = sqrt(z);
    for(i = 2; i <= x; i++)
    {
        if(z % i == 0)
        {
            return false;
        }
    }
    return true;    
}