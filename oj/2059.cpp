#include <iostream>

using namespace std;

int flag;

int main()
{
    double sl,cl,ct,vr,v1,v2,p[120],a[1005][2];//sl = sumlong总长,cn = chargenum,cl=chargelong,ct=chargetime,vr=rabbit's v,v1,v2=turtle's v0
    int i,dl[2],cn,x;//duo long 每段充电多余的距离        //a[i][0]用于记录到i位置的时间，0，1分别代表不充电和充电
    while (cin >> sl)
    {
        cin >> cn >> cl >> ct;
        cin >> vr >> v1 >> v2;
        for(i = 1; i <= cn; i++)
        {
            cin >> p[i];
        }
        p[i] = sl;//使x=p[i+1]-p[i]对于最后一段也成立
        //初始化第一段
        x = p[1];
        if(x >= cl)
        {
            a[0][0] = cl / v1 + (x-cl) / v2;
            a[0][1] = a[0][0];
            dl[0] = 0;
            dl[1] = 0;
        }
        else
        {
            a[0][0] = x / v1;
            a[0][1] = a[0][0];
            dl[0] = cl - x;
            dl[1] = cl - x;
        }
        //判断后面的情况
        for(i = 1; i <= cn; i++)
        {
            x = p[i+1] - p[i];
            //充电时
            if(cl > x)//充电距离比这一段长
            {
                a[i][1] = x / v1 + a[i-1][flag] + ct;
                dl[1] = cl - x;
            }
            else
            {
                a[i][1] = cl / v1 + (x-cl) / v2 + a[i-1][flag] + ct;
                dl[1] = 0;
            }
            
            //不充电时
            if(dl[flag] > x)//多余的长度比这一段还长
            {
                a[i][0] = a[i-1][flag] + x / v1;
                dl[0] = dl[flag] - x;
            }
            else
            {
                a[i][0] = dl[flag] / v1 + (x-dl[flag]) / v2 + a[i-1][flag];
                dl[0] = 0;
            }
            //判断
            if(a[i][0] > a[i][1])
            {
                flag = 1;
            }
            else if(a[i][0] < a[i][1])
            {
                flag = 0;
            }
            else//相等时就就尽量选择延续距离长的
            {
                if(dl[1] < dl[0])
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
                
            }
            
          }  
          if(a[cn][flag] > sl/vr)  
          {
              cout << "Good job,rabbit!" << endl;
          }
          else
          {
              cout << "What a pity rabbit!" << endl;
          }
    }
    return 0;
}