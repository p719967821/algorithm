/*第几天?*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int year,mon,day,sum = 0;
    while (scanf("%d/%d/%d",&year,&mon,&day) != EOF)
    {
        switch (mon)
        {
        case 12:{
            sum += day;
        }
        case 11:{
            if(mon == 11)
            {
                sum += day;                
            }
            else
            {
                sum += 30;
            }
            
        }
        case 10:{
            if(mon == 10)
            {
                sum += day;                
            }
            else
            {
                sum += 31;
            }
        }
        case 9:{
            if(mon == 9)
            {
                sum += day;                
            }
            else
            {
                sum += 30;
            }
        }
        case 8:{
            if(mon == 8)
            {
                sum += day;                
            }
            else
            {
                sum += 31;
            }
        }
        case 7:{
            if(mon == 7)
            {
                sum += day;                
            }
            else
            {
                sum += 31;
            }
        }       
        case 6:{
            if(mon == 6)
            {
                sum += day;                
            }
            else
            {
                sum += 30;
            }
        }
        case 5:{
            if(mon == 5)
            {
                sum += day;                
            }
            else
            {
                sum += 31;
            }
        }
        case 4:{
            if(mon == 4)
            {
                sum += day;                
            }
            else
            {
                sum += 30;
            }
        }
        case 3:{
           if(mon == 3)
            {
                sum += day;                
            }
            else
            {
                sum += 31;
            }
        }
        case 2:{
            if(mon == 2)
            {
                sum += day;                
            }
            else
            {
               if((year % 4 == 0 && year % 100 != 0)||(year % 400 ==0))
               {
                   sum += 29;
               }
               else
               {
                   sum += 28;
               }
               
            }
        }
        case 1:{
            if(mon == 1)
            {
                sum += day;                
            }
            else
            {
                sum += 31;
            }
        }
    }
    cout << sum << endl;
    sum = 0;
    }
    return 0;
}