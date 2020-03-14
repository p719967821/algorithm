/*水仙花数*/
#include <iostream>

using namespace std;

bool isright(int a,int b,int c);

int main()
{
    int m,n,one,two,three,sum = 0,flag = 0;
    while (cin >> m >> n)
    {
        for(int i = m; i <= n; i++)
        {
            one = i % 10;
            two = (i / 10) % 10;
            three = (i / 100) % 10;//这里一定要注意，以后这种不能i/10，因为如果是除的尽的数，就会出现错误
            if(isright(one,two,three))
            {
                flag++;
                if(flag == 1)
                {
                    cout << i;                    
                }
                else
                {
                    cout << " " << i;
                }
                
            }
            else
            {
                sum++;
            }
        }
        if(sum == n - m + 1)
        {
            cout << "no"<< endl;
        }
        else
        {
            cout << endl;
        }
        sum = 0;
        flag = 0;
    }
    return 0;
}

bool isright(int a,int b,int c)
{
    int sum;
    sum = a*a*a+b*b*b+c*c*c;
    if(sum == c*100+b*10+a)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}