/*Picture*/
#include <iostream>

using namespace std;

int main()
{
    int wei,hei,i,j;
    while (cin >> wei >> hei)
    {
         for(i = 0; i < hei+2; i++)
         {
             if(i == 0 || i == hei + 1)
             {
                 for(j = 0; j < wei+2; j++)
                 {
                     if(j == 0 || j == wei+1)
                     {
                         cout << "+";
                     }
                     else
                     {
                         cout << "-";
                     }
                 }  
                 cout << endl;
             }
             else
             {
                 for(j = 0; j < wei+2; j++)
                 {
                     if(j == 0 || j == wei+1)
                     {
                         cout << "|";
                     }
                     else
                     {
                         cout << " ";
                     }
                 }  
                 cout << endl;
             }   
         }
         cout << endl;  
    }
    return 0;
}