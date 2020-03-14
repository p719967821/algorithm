/**踩气球**/
#include <iostream>

using namespace std;

int x,y;
int used[101];
int used1[101];
int flag;

int ministrue(int m);
int maxistrue(int m);
int judge(int x, int y);

int main()
{
    int t;
    while (1)
    {
        cin >> x >> y;
        if(x == 0 && y == 0)
        {
            break;
        }
        if(x < y)//保证x永远代表大数，y永远代表小数
        {
            t = x;
            x = y;
            y = t; 
        }
        for(int i = 0; i < 101; i++)
        {
            used[i] = 0;
            used1[i] = 0;
        }
        cout << judge(x,y) << endl;
    }
}

int judge(int x, int y)
{
    if(!ministrue(y))
    {
        return x;
    }
    else
    {
        if(maxistrue(x))
        {
            return x;
        }
        else
        {
            return y;
        }
        
    }
    
}

int ministrue(int m)
{
    int i;
    flag = 0;
    if(m == 1)
    {
        flag = 1;
        return flag;
    }
    else
    {
        for(i = 2; i <= 100; i++)
        {
            if(m % i == 0 && used[i] == 0)
            {
                used[i] = 1;
                used1[i] = used[i];
                m /= i;
                ministrue(m);
                m *= i;
                used[i] = 0;
            }
        }
    }
    
}

int maxistrue(int m)
{
    int i;
    flag = 0;
    if(m == 1)
    {
        flag = 1;
        return flag;
    }
    else
    {
        for(i = 2; i <= 100; i++)
        {
            if(m % i == 0 && used1[i] == 0)
            {
                used1[i] = 1;
                m /= i;
                maxistrue(m);
                m *= i;
                used1[i] = 0;
            }
        }
        return flag;
    }
    
}