#include <iostream>

using namespace std;

int v[]={1,2,5};
int c1[8010],c2[8010];//c1是起始，c2是缓存

void judge(int num[4]);

int main()
{
    int x;
    int num[4];
    while (1)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> num[i];
        }
        if(num[0] == 0 && num[1] == 0 && num[2] == 0)
        {
            break;
        }
        /*x = 1;
        while (1)
        {
            if(judge(x,num))
            {
                cout << x << endl;
                break;
            }
            x++;
        }*/
        judge(num);
        x = 1;
        while (1)
        {
            if(c1[x] == 0)
            {
                cout << x << endl;
                break;
            }
            x++;
        }
    }
    return 0;
}

void judge(int num[4])
{
    int i,j,k,times;
    for(i = 0; i <= 8000; i++)
    {
        if(i <= num[0])
        {
            c1[i] = 1;
        }
        else
        {
            c1[i] = 0;
        }
        c2[i] = 0;
    }
    for(i = 1; i <= 2; i++)
    {
        for(j = 0; j <= 8000; j++)
        {
            times = 0;//用于计数，使之不超过限定数目
            for(k = 0; k+j <= 8000 && times <= num[i]; k=k+v[i])
            {
                c2[k+j] += c1[j];
                times++;
            }
        }
        for(j = 0; j <= 8000; j++)
        {
            c1[j] = c2[j];
            c2[j] = 0;
        }
    }
   /* if(c1[n] != 0)
    {
        return false;
    }
    else
    {
        return true;
    }*/
    
}