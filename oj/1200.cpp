/*To and Fro*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int n,col,row,i,j;
    char x[30][30];
    while (cin >> n && n)
    {
        cin >> a;
        col = n;
        row = a.length() / n;
        for(i = 0 ; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                if(i % 2 == 0)//正方向
                {
                    x[i][j] = a[i*n+j];
                }
                else
                {
                    x[i][j] = a[(i+1)*col-j-1];
                }  
            }
        }
        for(j = 0; j < col; j++)
        {
            for(i = 0; i < row; i++)
            {
                cout << x[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}