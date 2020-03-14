/*18岁生日*/
#include <iostream>
#include <string>

using namespace std;

int runyear(int year);

int main()
{
    int n;
    int year,mon,day,eyear,sum = 6570;//eyear是18岁
    string a;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        year = atoi(a.substr(0,4).c_str());
        mon = atoi(a.substr(5,2).c_str());
        day = atoi(a.substr(8,2).c_str());
        eyear = year + 18;
        sum = 6570;
        if(day == 29 && mon == 2)
        {
            cout << "-1" << endl;
            return 0;
        }
        else if(runyear(year) == 1 && runyear(eyear) != 1 && mon < 3)
        {
            sum++;
        } 
        else if(runyear(year) != 1 && runyear(eyear) == 1 && mon >= 3)
        {
           sum++; 
        }
        for(int j = year + 1; j < eyear; j++)
        {
            if(j % 4 == 0)
            {
                sum++;
            }
        }
    cout << sum << endl;
    }
    return 0;
}

int runyear(int year)//是闰年就返回1，否则返回0
{
    if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}