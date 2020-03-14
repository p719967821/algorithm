/*Ignatius and the Princess III——母函数基础题*/
#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k;
    int c1[130],c2[130];//c2是代表括号展开后的各系数，c1是暂存数
    while (cin >> n)
    {
        //初始化for
        for(i = 0; i <= n; i++)//从0开始，0代表不放
        {
            c2[i] = 1;
            c1[i] = 0;
        }
        //将母函数的括号打开
        for(i = 2; i <= n; i++)//将未展开的第i个括号乘入括号部分展开状态函数中
        {
            for(j = 0; j <= n; j++)//代表括号部分展开状态的每位数，将要与未展开括号前的第i个括号中的每一位数相乘，因为后面系数都是一，直接相加即可
            {
                for(k = 0; k+j <= n;k=k+i)//代表第i个括号中的每个数，范围是k+j<=n，因为要保证两者相乘指数要小于最大指数
                {
                    c1[k+j] += c2[j];
                }
            }
            for(j = 0; j <= n; j++)
            {
                c2[j] = c1[j];
                c1[j] = 0;
            }
        }
        cout << c2[n] << endl;
    }
    return 0;
}